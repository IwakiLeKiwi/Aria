#ifndef COMMANDS_INFOS
    #define COMMANDS_INFOS

    #include <string>
    #include "aria.hpp"
    #include "utils.hpp"

    namespace COMMANDS_INFOS {

        namespace DESCRIPTION {
            
        }

        namespace USAGE {
            void print_create_usage() {
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
            } 
        }
    }

#endif