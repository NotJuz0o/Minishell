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
            steps {
                script {
                    docker.image(DOCKER_IMAGE).inside {
                        // Étape de compilation
                        stage('Compilation') {
                            sh '''
                                make fclean || true
                                make
                                make clean
                            '''
                        }

                        // Vérification du coding style
                        stage('Coding Style') {
                            sh '''
                                # Installation de coding-style checker si nécessaire
                                if [ ! -f coding-style.sh ]; then
                                    wget https://raw.githubusercontent.com/Epitech/coding-style-checker/master/coding-style.sh
                                    chmod +x coding-style.sh
                                fi
                                
                                # Lancement du check coding style
                                ./coding-style.sh . .
                                
                                # Vérification des résultats
                                if [ -s coding-style-reports.log ]; then
                                    echo "Coding style errors found:"
                                    cat coding-style-reports.log
                                    exit 1
                                else
                                    echo "No coding style errors found"
                                fi
                            '''
                        }

                        // Lancement des tests unitaires si présents
                        stage('Unit Tests') {
                            sh '''
                                if [ -f tests/unit_tests ]; then
                                    ./tests/unit_tests
                                else
                                    echo "No unit tests found"
                                fi
                            '''
                        }
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
