#ifndef MINECRAFT_INFOS
    #define MINECRAFT_INFOS

    #include "utils.hpp"
    #include <fstream>
    #include <sstream>
    #include <iostream>

    using namespace std;

    namespace MINECRAFT {

            namespace MINECRAFT_VERSION {
                // Minecraft versions supported
                const string MIN_SUPPORTED_MINECRAFT_VERSION = "1.8";
                const string MAX_SUPPORTED_MINECRAFT_VERSION = "1.20.4";

                const string ALL_MC_SUPPORTED_VERSION[] = {
                    "1.8", "1.8.1", "1.8.2", "1.8.3", "1.8.4", "1.8.5", "1.8.6", "1.8.7", "1.8.8", "1.8.9", // 10
                    "1.9", "1.9.1", "1.9.2", "1.9.3", "1.9.4", // 5
                    "1.10", "1.10.1", "1.10.2", // 3
                    "1.11", "1.11.1", "1.11.2", // 3
                    "1.12", "1.12.1", "1.12.2", // 3
                    "1.13", "1.13.1", "1.13.2", // 3
                    "1.14", "1.14.1", "1.14.2", "1.14.3", "1.14.4", // 5
                    "1.15", "1.15.1", "1.15.2", // 3
                    "1.16", "1.16.1", "1.16.2", "1.16.3", "1.16.4", "1.16.5", // 6
                    "1.17", "1.17.1", // 2
                    "1.18", "1.18.1", "1.18.2", // 3
                    "1.19", "1.19.1", "1.19.2", "1.19.3", "1.19.4", // 5
                    "1.20", "1.20.1", "1.20.2", "1.20.3", "1.20.4" // 5
                };

                const string SUPPORTED_MC_VERSION_1_8[] = {
                    "1.8", "1.8.1", "1.8.2",
                    "1.8.3", "1.8.4", "1.8.5",
                    "1.8.6", "1.8.7", "1.8.8",
                    "1.8.9"
                };

                const string SUPPORTED_MC_VERSION_1_9[] = {
                    "1.9", "1.9.1", "1.9.2", "1.9.3", "1.9.4"
                };

                const string SUPPORTED_MC_VERSION_1_10[] = {
                    "1.10", "1.10.1", "1.10.2"
                };

                const string SUPPORTED_MC_VERSION_1_11[] = {
                    "1.11", "1.11.1", "1.11.2"
                };

                const string SUPPORTED_MC_VERSION_1_12[] = {
                    "1.12", "1.12.1", "1.12.2"
                };

                const string SUPPORTED_MC_VERSION_1_13[] = {
                    "1.13", "1.13.1", "1.13.2"
                };

                const string SUPPORTED_MC_VERSION_1_14[] = {
                    "1.14", "1.14.1", "1.14.2", "1.14.3", "1.14.4"
                };

                const string SUPPORTED_MC_VERSION_1_15[] = {
                    "1.15", "1.15.1", "1.15.2"
                };

                const string SUPPORTED_MC_VERSION_1_16[] = {
                    "1.16", "1.16.1", "1.16.2", "1.16.3", "1.16.4", "1.16.5"
                };

                const string SUPPORTED_MC_VERSION_1_17[] = {
                    "1.17", "1.17.1"
                };

                const string SUPPORTED_MC_VERSION_1_18[] = {
                    "1.18", "1.18.1", "1.18.2"
                };

                const string SUPPORTED_MC_VERSION_1_19[] = {
                    "1.19", "1.19.1", "1.19.2", "1.19.3", "1.19.4"
                };

                const string SUPPORTED_MC_VERSION_1_20[] = {
                    "1.20", "1.20.1", "1.20.2", "1.20.3", "1.20.4"
                };
            }

            namespace JAVA_VERSION {
                const string JAVA_8  = "apt-get install -y openjdk-8-jre-headless";
                const string JAVA_11 = "apt-get install -y openjdk-11-jre-headless";
                const string JAVA_16 = "apt-get install -y openjdk-16-jre-headless";
                const string JAVA_17 = "apt-get install -y openjdk-17-jre-headless";
                const string JAVA_20 = "apt-get install -y openjdk-20-jre-headless";
            }

            namespace SERVER_JAR {

                namespace VANILLA {
                    
                }

                namespace SPIGOT {

                }

                namespace BUKKIT {
                    
                }

                namespace FORGE {
                    
                }

                namespace FABRIC {
                    
                }
            }

            namespace DOCKERFILE {
                /*const char* createMinecraftDockerfile(const char* javaVersion) {
                    std::ostringstream dockerfileContent;

                    // Contenu du Dockerfile
                    dockerfileContent << "###############################################\n"
                                    << "# Utilisation de l'image de base Ubuntu 20.04 #\n"
                                    << "###############################################\n"
                                    << "FROM ubuntu:20.04\n\n"
                                    << "################################\n"
                                    << "# Installation des dépendances #\n"
                                    << "################################\n\n"
                                    << "# Java\n"
                                    << "RUN apt-get update && " << javaVersion << "\n\n"
                                    << "# Screen\n"
                                    << "RUN apt-get update && apt-get install -y screen";

                    // Copiez le contenu dans un tableau de caractères alloué dynamiquement
                    char* result = strdup(dockerfileContent.str().c_str());

                    return result;
                }*/
            }
        }

#endif