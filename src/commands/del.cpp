#include <iostream>
#include <sstream>

#include "sshGlobals.hpp"
#include "aria.hpp"
#include "commands/commands.hpp"

void del_cmd(const std::vector<std::string>& args) {
    LIBSSH2_CHANNEL *channel = getSSHChannel();
    
    if (args.empty()) {
        std::cout << "No directory specified." << std::endl;
        return;
    } else {
        const std::string &arg = args[0];
        std::cout << "Are you sure you want to delete this directory? [Y/N]: ";

        std::string userInput;
        std::getline(std::cin, userInput);

        if (userInput == "Y" || userInput == "y") {
            if (checkIfDirectoryExist(arg)) {
                executeSSHCommand(channel, ("rm -r " + arg + std::string("\n")).c_str());
                std::cout << "Directory '" << arg << "' has been deleted." << std::endl;
            } else {
                return;
            }
        } else {
            std::cout << "Deletion aborted." << std::endl;
        }
    }
}