#include "sshGlobals.hpp"
#include "aria.hpp"
#include "commands.hpp"

void ls_cmd(const std::string& arg) {
    LIBSSH2_CHANNEL *channel = getChannel();
    if (arg.empty()) {
        executeCmdOutput(channel, ("ls -l" + std::string("\n")).c_str());
    } else {
        executeCmdOutput(channel, ("ls -l " + arg + std::string("\n")).c_str());
    }
}