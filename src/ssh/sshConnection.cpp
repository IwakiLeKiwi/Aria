#include <iostream>

#include "aria.hpp"
#include "config.h"
#include "commands/commands.hpp"
#include "sshGlobals.hpp"

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
using namespace std;
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
 * Create the SSH channel
 */
void Aria::ssh::createSSHChannel() {

    initSSHChannel();

    LIBSSH2_CHANNEL *channel = getSSHChannel();
    if (!channel) {
        Aria::err("Erreur lors de l'initialisation du channel SSH.");
    }

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

    Aria::info("Channel created successfully!");
}


void Aria::ssh::createSFTPChannel() {

    initSFTPChannel();

    LIBSSH2_SFTP *sftp = getSFTPChannel();
    if (!sftp) {
        Aria::err("Erreur lors de l'initialisation de la session SFTP.");
        return;
    }

    Aria::info("SFTP session created successfully!");
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
void Aria::ssh::closeSSHChannel() {
    LIBSSH2_CHANNEL *channel = getSSHChannel();
    Aria::info("Close SSH channel...");
    libssh2_channel_close(channel);
    libssh2_channel_free(channel);
    Aria::info("SSH channel successfully closed!");
}

/* 
 * Close the SFTP channel
 */
void Aria::ssh::closeSFTPChannel() {
    LIBSSH2_SFTP *sftp = getSFTPChannel();
    Aria::info("Close SFTP channel...");
    libssh2_sftp_shutdown(sftp);
    Aria::info("SFTP channel successfully closed!");
}