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
                            # Installation des dépendances nécessaires
                            apt-get update -qq && apt-get install -y -qq wget

                            # Check coding style
                            if [ ! -f coding-style.sh ]; then
                                wget https://raw.githubusercontent.com/Epitech/coding-style-checker/master/coding-style.sh
                                chmod +x coding-style.sh
                            fi
                            
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
