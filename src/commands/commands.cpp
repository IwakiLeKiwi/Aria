#include <sstream>

#include "aria.hpp"
#include "commands.hpp"

using namespace std;

void startCommandPrompt() {

    string cmd;
    do {
        cout << "> ";
        getline(std::cin, cmd);

        istringstream iss(cmd);
        string command;
        iss >> command;
        
        vector<string> arguments;
        string argument;
        while (iss >> argument) {
            arguments.push_back(argument);
        }

        if (command == "exit" || command == "quit" || command == "bye") {
            Aria::info("SSH connection terminated.");
            Aria::ssh::closesSSHChannel();
            break;

        } else if (command == "help") {
            help_cmd(arguments.empty() ? "" : arguments[0]);

        } else if (command == "go") {
            go_cmd(arguments.empty() ? "" : arguments[0]);

        } else if (command == "del") {
            del_cmd(arguments.empty() ? "" : arguments[0]);

        } else if (command == "info") {
            info_cmd(arguments.empty() ? "" : arguments[0]);

        } else if (command == "ls") {
            ls_cmd(arguments.empty() ? "" : arguments[0]);

        } else if (command == "create") {
            create_cmd(arguments);

        } else {
            cout
                << "Commande non reconnue. Tapez 'help' pour plus d'informations."
                << endl;

        }
    } while (cmd != "exit" || cmd != "quit" || cmd != "bye");
}