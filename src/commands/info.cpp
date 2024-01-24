#include "sshGlobals.hpp"
#include "aria.hpp"
#include "commands/commands.hpp"

void info_cmd(const std::vector<std::string>& args) {
    LIBSSH2_CHANNEL *channel = getSSHChannel();

    if (args.empty()) {
        std::cout << "EMPTY ARG" << std::endl;
    } else {
        const std::string& arg = args[0];
        std::cout << "ARGS : " << arg << std::endl;
    }
}