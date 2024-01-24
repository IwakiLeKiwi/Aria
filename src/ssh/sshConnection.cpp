#include <iostream>

#include "aria.hpp"
#include "config.h"
#include "commands/commands.hpp"
#include "commands/minecraftInfos.hpp"

SOCKET sock = NULL;
LIBSSH2_SESSION *session = libssh2_session_init();
WSADATA wsaData;

/* Channel*/
LIBSSH2_CHANNEL *sshChannel = nullptr;
void initSSHChannel() {
    sshChannel = libssh2_channel_open_session(session);
}
LIBSSH2_CHANNEL *getSSHChannel() {
    return sshChannel;
}

/* SFTP */
LIBSSH2_SFTP *sftp_session = nullptr;
void initSFTPChannel() {
    sftp_session = libssh2_sftp_init(session);
}
LIBSSH2_SFTP *getSFTPChannel() {
    return sftp_session;
}

/* --------------------------------------------------------------------------------------------------------------- */

/*
 * Initialize libraries
 */
void Aria::ssh::initializeLibs() {
    if (WSAStartup(MAKEWORD(2, 2), &wsaData) != 0) {
        Aria::err("Winsock initialization error.");
        return;
    } else if (libssh2_init(0) != 0) {
        Aria::err("Error initializing libssh2.");
        WSACleanup();
        return;
    } else if (!session) {
        Aria::err("SSH session cannot be initialized.");
        WSACleanup();
        libssh2_exit();
        return;
    } else {
        Aria::info("Aria libraries loaded succesfully!");
    }
}

/*
 * Connection in SSH
 */
void Aria::ssh::connectSSH() {
    sock = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
    if (sock == INVALID_SOCKET) {
        Aria::err("Socket creation error.");
        WSACleanup();
        libssh2_exit();
        return;
    }

    sockaddr_in sin;
    sin.sin_family = AF_INET;
    sin.sin_port = htons(PORT);
    sin.sin_addr.s_addr = inet_addr(HOSTNAME);

    if (connect(sock, (struct sockaddr*)(&sin), sizeof(struct sockaddr_in)) != 0) {
        Aria::err("SSH connection failure.");
        closesocket(sock);
        WSACleanup();
        libssh2_exit();
        return;
    } else if (libssh2_session_handshake(session, sock) != 0) {
        Aria::err("SSH connection failure.");
        closesocket(sock);
        libssh2_session_free(session);
        WSACleanup();
        libssh2_exit();
        return;
    } else if (libssh2_userauth_password(session, USERNAME, PASSWORD) != 0) {
        Aria::err("Authentication failure.");
        libssh2_session_disconnect(session, "Authentication failure.");
        libssh2_session_free(session);
        closesocket(sock);
        WSACleanup();
        libssh2_exit();
        return;
    } else { // Connexion réussie
        Aria::info("Aria connected in SHH succesfully!");
    }
}

/* ---------------------------------------------------------------------------- */

/*
 * SSH Commands
 */

// Default execution
void executeSSHCommand(LIBSSH2_CHANNEL* oChannel, const char* cmd) {
    try {
        libssh2_channel_write(oChannel, cmd, strlen(cmd));
        libssh2_channel_flush(oChannel);

        Sleep(10); 
    } catch (const std::system_error& e) {
        std::cout << "Erreur lors de l'éxécution de la commande !" << e.what() << std::endl;
    } catch (const std::exception& e) {
        std::cout << "Une exception s'est produite lors de l'éxécution de la commande !" << e.what() << std::endl;
    } catch (...) {
        std::cout << "Une exception inattendue s'est produite lors de l'éxécution de la commande !" << std::endl;
    }
}
 
// Execution with output
void executeSSHCommandWithOutput(LIBSSH2_CHANNEL* oChannel, const char* cmd) {
    try {
        executeSSHCommand(oChannel, cmd);
        
        char buffer[4096];
        int bytes = libssh2_channel_read(oChannel, buffer, sizeof(buffer));

        if (bytes > 0) {
            std::cout.write(buffer, bytes);
            std::cout.flush();
        } else if (bytes == 0) {
            Sleep(10);
        } else {
            int exit_code = 0;
            libssh2_channel_send_eof(oChannel);
            libssh2_channel_wait_eof(oChannel);

            if (libssh2_channel_get_exit_status(oChannel) != 0) {
                std::cerr << "La commande a échoué avec le code de sortie : " << libssh2_channel_get_exit_status(oChannel) << std::endl;
            }
        }

        Sleep(10);
    } catch (const std::system_error& e) {
        std::cout << "Erreur lors de l'éxécution de la commande !" << e.what() << std::endl;
    } catch (const std::exception& e) {
        std::cout << "Une exception s'est produite lors de l'éxécution de la commande !" << e.what() << std::endl;
    } catch (...) {
        std::cout << "Une exception inattendue s'est produite lors de l'éxécution de la commande !" << std::endl;
    }
}

/*
 * Check if a directory exist 
 */
bool checkIfDirectoryExist(const std::string& remotePath) {
    LIBSSH2_SFTP *sftp = getSFTPChannel();
    std::cout << "[METHOD] SFTP channel with ID: " << sftp << std::endl;
    LIBSSH2_SFTP_HANDLE *handle = libssh2_sftp_opendir(sftp, remotePath.c_str());
    if (handle) {
        std::cout << "Le répertoire existe." << std::endl;
        libssh2_sftp_closedir(handle);
        return true;
    } else {
        Aria::err("Le répertoire n'existe pas ou l'accès est refusé.");
    }


    return false;
}

/* 
 * Create the SSH channel
 */
void Aria::ssh::createSSHChannel() {

    initSSHChannel();

    LIBSSH2_CHANNEL *channel = getSSHChannel();

    const char *command = "/bin/bash";
    libssh2_channel_exec(channel, command);

    // Admin mode
    // /!\ Make sure you don't need the password!
    try {
        executeSSHCommand(channel, ("sudo su -" + std::string("\n")).c_str());
        Aria::info("Root mode OK");
    } catch (const std::exception& e) {
        Aria::err("Root mode impossible. Probably need the password");
    }

    std::cout << "Created channel with ID: " << channel << std::endl;
    Aria::info("Channel created successfully!");
}

/*const char *generateDockerfileContent() {
                    const char *dockerfileContent = 
                        "###############################################\n"
                        "# Utilisation de l'image de base Ubuntu 20.04 #\n"
                        "###############################################\n"
                        "FROM ubuntu:latest\n\n"
                        "#################################\n"
                        "# Installation des dependances #\n"
                        "#################################\n\n"
                        "# Java\n"
                        "RUN apt-get update && " "JAVA 8" "\n\n"
                        "# Screen\n"
                        "RUN apt-get update && apt-get install -y screen";

                    return dockerfileContent;
                }*/

void Aria::ssh::createSFTPChannel() {
    initSFTPChannel();

    LIBSSH2_SFTP *sftp = getSFTPChannel();
    if (!sftp) {
        std::cerr << "Erreur lors de l'initialisation de la session SFTP." << std::endl;
        return;
    }

    /*const char *remote_file_path = "/appli/docker/minecraft/Dockerfile";
    LIBSSH2_SFTP_HANDLE *sftp_handle;

    // Ouvrir un fichier en écriture sur le serveur
    sftp_handle = libssh2_sftp_open(sftp, remote_file_path, LIBSSH2_FXF_WRITE | LIBSSH2_FXF_CREAT | LIBSSH2_FXF_TRUNC, LIBSSH2_SFTP_S_IRUSR | LIBSSH2_SFTP_S_IWUSR);

    if (!sftp_handle) {
        int error_code = libssh2_session_last_errno(session);
        char *error_message;
        libssh2_session_last_error(session, &error_message, NULL, 0);

        std::cerr << "Impossible d'ouvrir le fichier sur le serveur. Code d'erreur : " << error_code << ", Message d'erreur : " << error_message << std::endl;

        libssh2_sftp_shutdown(sftp);
        return;
    }

    libssh2_sftp_write(sftp_handle, generateDockerfileContent(), strlen(generateDockerfileContent()));

    // Fermer le fichier
    libssh2_sftp_close(sftp_handle);*/

    std::cout << "Created SFTP channel with ID: " << sftp << std::endl;
}

/* ---------------------------------------------------------------------------------- */

/*
 * Close the SSH session
 */
void Aria::ssh::closeSession() {
    Aria::info("Close SSH connection...");
    libssh2_session_disconnect(session, "Closing the connection.");
    libssh2_session_free(session);
    closesocket(sock);
    WSACleanup();
    libssh2_exit();
    Aria::info("SSH session successfully closed!");
}

/*
 * Close the SSH channel
 */
void Aria::ssh::closesSSHChannel() {
    LIBSSH2_CHANNEL *channel = getSSHChannel();
    Aria::info("Close SSH channel...");
    libssh2_channel_close(channel);
    libssh2_channel_free(channel);
    Aria::info("SSH channel successfully closed!");
}

/* 
 * Close the SFTP session
 */