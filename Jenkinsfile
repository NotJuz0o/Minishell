pipeline {
    agent any
    environment {
        DOCKER_IMAGE = 'epitechcontent/epitest-docker'
    }
    stages {
        stage('Checkout') {
            steps {
                checkout scm
            }
        }
        stage('Build & Test in Docker') {
            agent {
                docker {
                    image env.DOCKER_IMAGE
                    args '--user root'
                }
            }
            stages {
                stage('Compilation') {
                    steps {
                        sh '''
                            make fclean || true
                            make
                            make clean
                        '''
                    }
                }
                stage('Coding Style') {
                    steps {
                        sh '''#!/bin/bash
                            DUMP_PATH=/tmp/coding-style-reports
                            EXPORT_FILE="coding-style-reports.log"
                            SELECTED_FILES=$(find . -type f -name "*.c" -o -name "*.h")
                            
                            # Vérification directe sans créer de script intermédiaire
                            for file in $SELECTED_FILES; do
                                echo "Checking $file"
                                # Vérification des lignes de plus de 80 caractères
                                awk 'length > 80 {print FILENAME ":" FNR ": line too long (" length " > 80 characters)"}' "$file" >> "$EXPORT_FILE"
                                
                                # Vérification des espaces en fin de ligne
                                awk '/.*[[:space:]]+$/ {print FILENAME ":" FNR ": trailing space(s)"}' "$file" >> "$EXPORT_FILE"
                                
                                # Vérification des multiples lignes vides consécutives
                                awk '/^$/ && p {print FILENAME ":" FNR ": too many consecutive empty lines"} {p=/^$/}' "$file" >> "$EXPORT_FILE"
                            done

                            if [ -s "$EXPORT_FILE" ]; then
                                echo "Coding style errors found:"
                                cat "$EXPORT_FILE"
                                exit 1
                            else
                                echo "No coding style errors found"
                            fi
                        '''
                    }
                }
            }
        }
    }
    post {
        always {
            archiveArtifacts artifacts: 'coding-style-reports.log', allowEmptyArchive: true
            cleanWs()
        }
        success {
            echo 'Pipeline completed successfully!'
        }
        failure {
            echo 'Pipeline failed!'
        }
    }
}
