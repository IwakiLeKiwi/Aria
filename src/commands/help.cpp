#include <iostream>
#include <vector>

#include "commands/commands.hpp"
#include "aria.hpp"
#include "utils.hpp"
#include "config.h"

void help_cmd(const std::vector<std::string>& args) {
    if (args.empty()) {
        // Main message
        std::cout
            << "┌─────────────────────────────────────────────────────┐\n"
            << "│                     " << Utils::Colors::BLUE << "Aria" << Utils::Colors::RESET << " System                     │\n"
            << "└─────────────────────────────────────────────────────┘\n"
            << std::endl;

        std::cout
            << "Available commands:\n"
            << "  " << Utils::Colors::CYAN << "help" << Utils::Colors::RESET << "            - Display this help message\n"
            << "  " << Utils::Colors::CYAN << "version" << Utils::Colors::RESET << "         - Display the system version\n"
            << "  " << Utils::Colors::CYAN << "cd" << Utils::Colors::RESET << "              - Change the current directory\n"
            << "  " << Utils::Colors::CYAN << "ls" << Utils::Colors::RESET << "              - List the contents of a directory\n"
            << "  " << Utils::Colors::CYAN << "create" << Utils::Colors::RESET << "          - Create a new file or directory\n"
            << "  " << Utils::Colors::CYAN << "stop" << Utils::Colors::RESET << "            - Stop a running process\n"
            << "  " << Utils::Colors::CYAN << "rm" << Utils::Colors::RESET << "              - Remove a file or directory\n"
            << "  " << Utils::Colors::CYAN << "exit, quit, bye" << Utils::Colors::RESET << " - Quit and disconnect Aria\n"
            << std::endl;

    } else {
        const std::string& arg = args[0];

        if (arg == "help") {
            Aria::print("Usage:");
            Aria::print("  help [command]\n");
            Aria::print("Comand:");
            Aria::print("  all commands available on the Aria System\n");
            Aria::print("Description:");
            Aria::print("  displays help on the commands available in the Aria System.");
            Aria::print("  for help with a specific command, use 'help [command]'.");
        } else if (arg == "cd") {
            Aria::print("Usage: cd [directory]\n");
            Aria::print("Description: Change the current directory");
        } else if (arg == "ls") {
            Aria::print("Usage: ls [directory]\n");
            Aria::print("Description: List the contents of a directory (or the current directory if none is specified)");
        } else if (arg == "create") {
            Aria::print("Usage:");
            Aria::print("  create {name} --type [type] [arguments]\n");
            Aria::print("Types:");
            Aria::print("  minecraft, mc    - using arguments to create a minecraft container");
            Aria::print("  web              - using arguments to create a web container (NGINX)\n");
            Aria::print("Arguments:");
            Aria::print(" minecraft usage   - create {name} --type minecraft --version [version] --port [port] --model [model] --dir [dir]");
            Aria::print("  version          - version of minecraft (1.8 - 1.20.4)");
            Aria::print("  port             - " + Utils::Colors::PURPLE + "[NO INFORMATIONS]");
            Aria::print("  model            - vanilla, " + Utils::Colors::PURPLE + "forge\u001b[0m, " + Utils::Colors::PURPLE + "fabric\u001b[0m, " + Utils::Colors::PURPLE + "spigot\u001b[0m, " + Utils::Colors::PURPLE + "bukkit");
            Aria::print("  dir              - a valid directory of your server\n");
            Aria::print(" web usage         - create {name} --type web --port [port] --dir [dir]");
            Aria::print("  port             - " + Utils::Colors::PURPLE + "[NO INFORMATIONS]");
            Aria::print("  dir              - a valid directory of your server\n");
            Aria::print("Description:");
            Aria::print("  create a container for a minecraft server or a web server with docker in few lines");
        } else if (arg == "stop") {
            Aria::print("Usage: cd [directory]\n");
            Aria::print("Description: Change the current directory");
        } else if (arg == "rm") {
            Aria::print("Usage: cd [directory]\n");
            Aria::print("Description: Change the current directory");
        } else if (arg == "version") {
            Aria::print("Usage: version\n");
            Aria::print("Description: Display the system version");
        } else {
            std::cout << "Unknown command: " << arg << std::endl;
        }
    }
}