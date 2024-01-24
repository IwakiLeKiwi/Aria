#include <sstream>
#include <map>

#include "aria.hpp"
#include "commands/commands.hpp"

using namespace std;

using CommandFunction = std::function<void(const std::vector<std::string>& args)>;
map<string, CommandFunction> commandMap;

/*
 * Initialize commands names with the function
 */
void initializeAriaCommands() {
    commandMap["help"] = help_cmd;
    commandMap["go"] = go_cmd;
    commandMap["del"] = del_cmd;
    commandMap["info"] = info_cmd;
    commandMap["ls"] = ls_cmd;
    commandMap["create"] = create_cmd;
}

void executeCommand(const string& command, const vector<string>& arguments) {
    auto it = commandMap.find(command);
    if (it != commandMap.end()) {
        it->second(arguments);
    } else {
        cout << "Commande non reconnue. Tapez 'help' pour plus d'informations." << endl;
    }
}

/*
 * Start the command prompt 
 */
void Commands::startCommandPrompt() {

    // Initialize Aria Commands
    initializeAriaCommands();

    string cmd;
    do {
        cout << "> ";
        getline(cin, cmd);

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

        } else {
            executeCommand(command, arguments);
        }

    } while (cmd != "exit" || cmd != "quit" || cmd != "bye");
}