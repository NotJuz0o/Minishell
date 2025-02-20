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
                        sh '''
                            # Créer le script de vérification du coding style manuellement
                            cat > coding-style.sh << 'EOL'
#!/bin/bash

DUMP_PATH=/tmp/coding-style-reports
EXPORT_FILE="coding-style-reports.log"
SELECTED_FILES=$( find . -type f -name "*.c" -o -name "*.h" )

mkdir -p "$DUMP_PATH"
rm -f "$EXPORT_FILE"

NB_FILES=$( echo "$SELECTED_FILES" | wc -l )

if [ $NB_FILES -eq 0 ]; then
    exit 0
fi

echo "$SELECTED_FILES" | tr '\\n' '\\0' | xargs -0 -L1 bash -c '
    for arg; do
        echo "Checking $arg"
        # Vérification des lignes de plus de 80 caractères
        awk "length > 80 {print FILENAME \":\" FNR \": line too long (\" length \" > 80 characters)\"}" "$arg" >> "$EXPORT_FILE"
        
        # Vérification des espaces en fin de ligne
        awk "/.*[[:space:]]+$/ {print FILENAME \":\" FNR \": trailing space(s)\"}" "$arg" >> "$EXPORT_FILE"
        
        # Vérification des multiples lignes vides consécutives
        awk "/^$/ && p {print FILENAME \":\" FNR \": too many consecutive empty lines\"} {p=/^$/}" "$arg" >> "$EXPORT_FILE"
    done
' bash

chmod +x coding-style.sh
./coding-style.sh . .

if [ -s coding-style-reports.log ]; then
    echo "Coding style errors found:"
    cat coding-style-reports.log
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
