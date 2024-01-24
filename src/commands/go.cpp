#include <iostream>
#include <sstream>

#include "sshGlobals.hpp"
#include "aria.hpp"
#include "commands/commands.hpp"

void go_cmd(const std::vector<std::string>& args) {
    LIBSSH2_CHANNEL *channel = getSSHChannel();

    if (args.empty()) {
        std::cout
            << "No directory specified"
            << std::endl;
    } else {
        const std::string& arg = args[0];
        if (checkIfDirectoryExist(arg)) {
            executeSSHCommand(channel, ("cd " + arg + "\n").c_str());
        } else {
            return;
        }
    }
}