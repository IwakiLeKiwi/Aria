#include "sshGlobals.hpp"
#include "aria.hpp"
#include "commands/commands.hpp"

void ls_cmd(const std::vector<std::string>& args) {
    LIBSSH2_CHANNEL *channel = getSSHChannel();
    
    if (args.empty()) {
        executeSSHCommandWithOutput(channel, ("ls -l" + std::string("\n")).c_str());
    } else {
        const std::string& arg = args[0];
        if (checkIfDirectoryExist(arg)) {
            executeSSHCommandWithOutput(channel, ("ls -l " + arg + std::string("\n")).c_str());
        } else {
            return;
        }
    }
}