#include <iostream>

#include "commands.hpp"
#include "utils.hpp"

void help_cmd(const std::string& arg) {
    if (arg.empty()) {
        std::cout
            << "=============== HELP ===============\n"
            << "PROJECT NAME: " << PROJECT_NAME << "\n"
            << "PROJECT VERSION: " << PROJECT_VERSION << "\n"
            << "PROJECT AUTHOR: " << AUTHOR << "\n"
            << std::endl;
        
        std::cout 
            << "Commandes disponibles:\n"
            << "1. "
            << "===================================="
            << std::endl;
    } else {
        if (arg == "go") {
            std::cout
                << "=============== GO ===============\n"
                << "usage: go <directory>" << "\n"
                << "=================================="
                << std::endl;
        } else {
            std::cout << "Unknow argument " << arg << std::endl;
        }
    }
}