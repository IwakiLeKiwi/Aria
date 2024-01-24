#ifndef SSH_GLOBALS
    #define SSH_GLOBALS

    #include <libssh2.h>
    #include <libssh2_sftp.h>
    #include <WinSock2.h>
    #include <string>

    LIBSSH2_CHANNEL *getSSHChannel();
    LIBSSH2_SFTP *getSFTPChannel();
    bool checkIfDirectoryExist(const std::string& remotePath);
#endif