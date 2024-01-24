#include <iostream>
#include <vector>

#include "commands/commands.hpp"
#include "utils.hpp"
#include "config.h"

void help_cmd(const std::vector<std::string>& args) {

    if (args.empty()) {
        // Main message
        std::cout
            << "\t[Systeme d'aide " << Utils::Colors::BLUE << "Aria" << Utils::Colors::RESET << "]\n"
            << std::endl;

    } else {
        const std::string& arg = args[0];

        std::cout << "Arg: " << arg << std::endl;
    }
}
