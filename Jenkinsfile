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
                        sh '''#!/bin/bash
                            make fclean || true
                            make
                            make clean
                        '''
                    }
                }
                stage('Coding Style') {
                    steps {
                        sh '''#!/bin/bash
                            /usr/bin/coding-style . .
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
            archiveArtifacts artifacts: '**/coding-style-reports.log', allowEmptyArchive: true
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
