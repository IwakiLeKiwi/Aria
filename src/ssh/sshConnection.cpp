#include <iostream>

#include "aria.hpp"
#include "config.h"
#include "commands.hpp"

SOCKET sock = NULL;
LIBSSH2_SESSION *session = libssh2_session_init();
WSADATA wsaData;

LIBSSH2_CHANNEL *sshChannel = nullptr;
void initSSHChannel() {
    sshChannel = libssh2_channel_open_session(session);
}
LIBSSH2_CHANNEL *getChannel() {
    return sshChannel;
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
 * Connect in SSH
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



void executeCmd(LIBSSH2_CHANNEL* oChannel, const char* cmd) {
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
 
void executeCmdOutput(LIBSSH2_CHANNEL* oChannel, const char* cmd) {
    try {
        executeCmd(oChannel, cmd);
        
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

void Aria::ssh::createSSHChannel() {

    initSSHChannel();

    LIBSSH2_CHANNEL *channel = getChannel();

    const char *command = "/bin/bash";
    libssh2_channel_exec(channel, command);

    
    executeCmd(channel, ("sudo su -" + std::string("\n")).c_str());

    Aria::info("Root mode OK");

    std::cout << "Channel: " << channel << std::endl;
    /*do {
        std::cout << "$ ";
        std::getline(std::cin, cmd);

        if (cmd == "exit") {
            break;
        }

        std::istringstream iss(cmd);
        std::string command;
        iss >> command;

        if (command == "cd") {
            // Vérifie s'il y a des arguments après "cd"//
            std::string arguments;
            std::getline(iss >> std::ws, arguments);

            if (!arguments.empty()) {
                std::cout << "La commande 'cd' a été désactivée. Veuillez taper la commande 'go'." << std::endl;
            } else {
                std::cout << "La commande 'cd' a été désactivée. Veuillez taper la commande 'go'." << std::endl;
            }
        } else if (command == "go") {
            // Vérifie s'il y a des arguments après "go"
            std::string arguments;
            std::getline(iss >> std::ws, arguments);

            if (!arguments.empty()) {
                // Affiche l'argument
                std::cout << "Argument pour la commande 'go': " << arguments << std::endl;
                executeCmd(channel, ("cd " + arguments + "\n").c_str());
            } else {
                // Message si aucun argument n'est fourni
                std::cout << "Aucun argument fourni pour la commande 'go'." << std::endl;
            }
        }
        else if (command == "ls") {
            executeCmdOutput(channel, (command + " -l" + "\n").c_str());
            std::cout << "Channel: " << channel << std::endl;
        } else if (command == "ls -l") {
            executeCmdOutput(channel, (command + "\n").c_str());
        } else if (command == "create") {
            // Vérifie s'il y a au moins deux arguments après "create"
            std::string arguments;
            std::getline(iss >> std::ws, arguments);

            std::istringstream argumentsStream(arguments);
            std::string argument1, argument2;

            // Extrait les deux premiers arguments
            argumentsStream >> argument1 >> argument2;

            if (!argument1.empty() && !argument2.empty()) {
                // Traitez les deux arguments ici
                std::cout << "Arguments pour la commande 'create': " << argument1 << " et " << argument2 << std::endl;

                // Exécute la commande avec les arguments
                executeCmd(channel, ("cd " + argument1 + "\n").c_str());
                executeCmd(channel, ("mkdir " + argument2 + "\n").c_str());
                executeCmdOutput(channel, ("ls" + std::string("\n")).c_str());
            } else {
                // Message si les arguments ne sont pas fournis correctement
                std::cout << "Veuillez spécifier deux arguments pour la commande 'create'." << std::endl;
            }
        }
        else {

            executeCmd(channel, (cmd + "\n").c_str());

        }
    } while (true);
//
    libssh2_channel_close(channel);
    libssh2_channel_free(channel);*/

    Aria::info("Channel created successfully!");
}

/*void other() {
    std::string cmd;
        do {
            cmd = readLine() + "\n";
            executeCmd(channel, cmd);
        } while (cmd != "exit\n");

        libssh2_channel_close(channel);
        libssh2_channel_free(channel);
}*/

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

void Aria::ssh::closesSSHChannel() {
    LIBSSH2_CHANNEL *channel = getChannel();
    Aria::info("Close SSH channel...");
    libssh2_channel_close(channel);
    libssh2_channel_free(channel);
    Aria::info("SSH channel successfully closed!");
}

/* -----------------------------------------------------------------------------------------------------*/

/*
 * Channel fonctionnel
 */
// TODO: refactore le code en plusieur bout et implémenter des commandes perso

/*void executeCommand(const char* command) {
    LIBSSH2_CHANNEL* channel = libssh2_channel_open_session(session);

    if (channel) {
        if (command == "/bin/bash") {
            libssh2_channel_exec(channel, command);
        }
        if (libssh2_channel_exec(channel, command) == 0) {
            char buffer[4096];
            int rc;
            
            // Lire la sortie de la commande
            while ((rc = libssh2_channel_read(channel, buffer, sizeof(buffer))) > 0) {
                fwrite(buffer, 1, rc, stdout);
            }

            // Fermer le canal
            libssh2_channel_send_eof(channel);
            libssh2_channel_wait_eof(channel);
            libssh2_channel_close(channel);
        } else {
            std::cerr << "Échec de l'exécution de la commande." << std::endl;
        }

        // Libérer le canal
        libssh2_channel_free(channel);
    } else {
        std::cerr << "Échec de l'ouverture du canal." << std::endl;
    }
}*/