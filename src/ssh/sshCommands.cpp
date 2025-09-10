#include <iostream>
#include <thread>
#include <chrono>

#include "aria.hpp"
#include "config.h"
#include "sshGlobals.hpp"

using namespace std;

/*
 * SSH Commands
 */

const int PERMISSIONS_DIR = 0777;
const int PERMISSIONS_FILE = 0666;

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
        Aria::err("Erreur lors de l'éxécution de la commande ! ", e.what());
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
    LIBSSH2_SFTP_HANDLE *handle = libssh2_sftp_opendir(sftp, remotePath.c_str());
    if (handle) {
        libssh2_sftp_closedir(handle);
        return true;
    } else {
        Aria::err("Directory does not exist or access denied. " + remotePath);
    }

    return false;
}

void writeFile(LIBSSH2_SFTP *sftp, const std::string &filePath, const std::string &fileContent) {
    LIBSSH2_SFTP_HANDLE *fileHandle = libssh2_sftp_open(sftp, filePath.c_str(), LIBSSH2_FXF_WRITE | LIBSSH2_FXF_CREAT, PERMISSIONS_FILE);
    if (!fileHandle) {
        printf("Erreur lors de l'ouverture du fichier : %d\n", libssh2_sftp_last_error(sftp));
        return;
    }
    size_t fileContentLen = fileContent.size();
    int writeRc = libssh2_sftp_write(fileHandle, fileContent.c_str(), fileContentLen);
    if (writeRc != fileContentLen) {
        printf("Erreur lors de l'écriture du fichier : %d\n", libssh2_sftp_last_error(sftp));
        return;
    }
    libssh2_sftp_close(fileHandle);
}

void createDirectory(LIBSSH2_SFTP *sftp, const std::string &path) {
    libssh2_sftp_mkdir(sftp, path.c_str(), PERMISSIONS_DIR);
    if (libssh2_sftp_last_error(sftp) != LIBSSH2_FX_OK) {
        printf("Erreur lors de la création du répertoire : %d\n", libssh2_sftp_last_error(sftp));
        return;
    }
}