#include "sshGlobals.hpp"
#include "aria.hpp"
#include "utils.hpp"
#include "config.h"
#include "commands/commands.hpp"

void version_cmd(const std::vector<std::string>& args) {
    LIBSSH2_CHANNEL *channel = getSSHChannel();

    if (args.empty()) {
        std::cout 
            << "# "
            << Utils::Colors::BLUE 
            << "Aria" 
            << Utils::Colors::RESET 
            << " System version " 
            << PROJECT_VERSION
            << " by "
            << AUTHOR
            << " #"
            << std::endl;
    } else {
        const std::string& arg = args[0];
        std::cout 
            << Utils::Colors::BLUE 
            << "Aria" 
            << Utils::Colors::RESET 
            << " System version " 
            << PROJECT_VERSION
            << " by "
            << AUTHOR
            << std::endl;
    }
}