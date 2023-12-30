#include <iostream>
#include <sstream>

#include "sshGlobals.hpp"
#include "aria.hpp"
#include "commands.hpp"

void go_cmd(const std::string& arg) {
    LIBSSH2_CHANNEL *channel = getChannel();
    if (arg.empty()) {
        std::cout
            << "No directory specified"
            << std::endl;
    } else {
        executeCmd(channel, ("cd " + arg + "\n").c_str());
    }
}