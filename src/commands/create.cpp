#include <iostream>
#include <sstream>
#include <cstring>
#include <algorithm>

#include "sshGlobals.hpp"
#include "aria.hpp"
#include "commands/commands.hpp"
#include "commands/minecraftInfos.hpp"

using namespace std;

bool isFolderNameAppropriate(const string &folderName) {
    vector<string> inappropriateNames = {"tmp", "temp", "bin", "root", "system"};

    for (const string &inappropriateName : inappropriateNames) {
        if (folderName == inappropriateName) {
            return false;
        }
    }

    return true;
}

int findMinecraftVersionIndex(const std::string &version) {
    int index = -1;
    for (int i = 0; i < sizeof(MINECRAFT::MINECRAFT_VERSION::ALL_MC_SUPPORTED_VERSION) / sizeof(MINECRAFT::MINECRAFT_VERSION::ALL_MC_SUPPORTED_VERSION[0]); ++i) {
        if (version == MINECRAFT::MINECRAFT_VERSION::ALL_MC_SUPPORTED_VERSION[i]) {
            index = i;
            break;
        }
    }
    return index;
}

void create_cmd(const vector<string> &args) {

    LIBSSH2_CHANNEL *channel = getSSHChannel();

    const string webDirectory = "/appli/docker/web";
    const string mcDirectory = "/appli/docker/minecraft";

    // Vérifier la présence de l'argument 1 (Nom du dossier)
    if (args.size() < 1) {
        cout << "Insufficient arguments for 'create' command." << endl;
        cout << "Usage: create <folderName> --type <typeOfContainer>" << endl;
        return;
    }

    const string &arg1 = args[0]; // Nom du dossier
    if (!isFolderNameAppropriate(arg1)) {
        Aria::err("Inappropriate folder name.");
        return;
    }

    // Vérifier la présence de l'argument 2 (--type)
    if (args.size() < 2 || args[1] != "--type") {
        Aria::warn("Invalid argument. Try --type");
        return;
    }

    // Vérifier la présence de l'argument 3 (web ou minecraft)
    if (args.size() < 3) {
        cout << "Invalid argument.\nArguments:\n1. Web\n2. Minecraft" << endl;
        return;
    }

    const string &arg3 = args[2]; // web ou minecraft

    if (arg3 == "minecraft" || arg3 == "mc") {
        // Vérifier la présence de l'argument 4 (--version) si arg3 est "minecraft"
        if (args.size() < 4 || args[3] != "--version") {
            cout << "No --version for minecraft" << endl;
            return;
        }

        const string &arg4 = args[3];
        if (args.size() < 5) {
            cout << "No Version for minecraft" << endl;
            return;
        }

        // Version
        const string &arg5 = args[4];

        int index = findMinecraftVersionIndex(arg5);

        if (index != -1) { // Version trouvée et existante
            
            if (index >= 0 && index <= 26) {

                std::cout << "Version de Java nécessaire : Java 8" << std::endl;
            } else if (index >= 27 && index <= 40) {

                std::cout << "Version de Java nécessaire : Java 11" << std::endl;
            } else if (index >= 41 && index <= 42) {

                std::cout << "Version de Java nécessaire : Java 16" << std::endl;
            } else if (index >= 43 && index <= 50) {

                std::cout << "Version de Java nécessaire : Java 17" << std::endl;
            } else {

                std::cout << "Version de Java nécessaire : Java 20" << std::endl;
            }
        } else { // Version non trouvée et/ou non existante
            
            cout << "Vesion de minecraft inexistante ou non trouvee" << endl;
        }
    } else if (arg3 == "web") {
        cout << "Chemin: " << webDirectory << endl;

    }  else {
        cout << "Other" << endl;

    }

    /*
     * Commandes
     */
    /*
    1. create <folderName> --type <typeOfContainer>
    -> <folderName>: can be anything you want excepted é, è, à, ^, ¨, ù, ç
    -> <typeOfContainer>: web or minecraft
    if <typeOfContainer> is web: print the web docker folder
    if <typeOfContainer> is minecraft: create <folderName> --type minecreaft --version
    -> --version: the version of minecraft
    */
}