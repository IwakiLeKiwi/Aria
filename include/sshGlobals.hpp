#ifndef SSH_GLOBALS
    #define SSH_GLOBALS

    #include <libssh2.h>
    #include <libssh2_sftp.h>
    #include <WinSock2.h>

    LIBSSH2_CHANNEL *getChannel();
#endif