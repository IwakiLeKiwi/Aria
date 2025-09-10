#ifndef SSH_GLOBALS
    #define SSH_GLOBALS

    #include <libssh2.h>
    #include <libssh2_sftp.h>
    #include <WinSock2.h>
    #include <string>

    LIBSSH2_CHANNEL *getSSHChannel();
    LIBSSH2_SFTP *getSFTPChannel();

    bool checkIfDirectoryExist(const std::string& remotePath);
    void executeSSHCommand(LIBSSH2_CHANNEL* oChannel, const char* cmd);
    void executeSSHCommandWithOutput(LIBSSH2_CHANNEL* oChannel, const char* cmd);
    void writeFile(LIBSSH2_SFTP *sftp, const std::string &filePath, const std::string &fileContent);
    void createDirectory(LIBSSH2_SFTP *sftp, const std::string &path);
    
#endif