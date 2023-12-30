#include "sshGlobals.hpp"
#include "aria.hpp"
#include "commands.hpp"

void info_cmd(const std::string& arg) {
    LIBSSH2_CHANNEL *channel = getChannel();
    if (arg.empty()) {
        std::cout << "EMPTY ARG" << std::endl;
    } else {
        std::cout << "ARGS : " << arg << std::endl;
    }
}