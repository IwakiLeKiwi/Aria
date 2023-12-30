#include <iostream>
#include <sstream>
#include <cstring>

#include "sshGlobals.hpp"
#include "aria.hpp"
#include "commands.hpp"
#include "utils.hpp"

using namespace std;

bool isFolderNameAppropriate(const string& folderName) {
    // Liste de noms de dossier inappropriés
    vector<string> inappropriateNames = {"tmp", "temp", "bin", "root", "system"};

    // Vérifier si le nom du dossier est dans la liste des noms inappropriés
    for (const string& inappropriateName : inappropriateNames) {
        if (folderName == inappropriateName) {
            return false; // Le nom du dossier est inapproprié
        }
    }

    return true; // Le nom du dossier est approprié
}

void create_cmd(const vector<string>& args) {

    LIBSSH2_CHANNEL *channel = getChannel();

    const string webDirectory = "/appli/docker/web";
    const string mcDirectory = "/appli/docker/minecraft";

    // Vérifier la présence de l'argument 1 (Nom du dossier)
    if (args.size() < 1) {
        cout << "Insufficient arguments for 'create' command." << endl;
        cout << "Usage: create <folderName> --type <typeOfContainer>" << endl;
        return;
    }

    const string& arg1 = args[0]; // Nom du dossier
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

    const string& arg3 = args[2]; // web ou minecraft

    if (arg3 == "minecraft") {
        // Vérifier la présence de l'argument 4 (--version) si arg3 est "minecraft"
        if (args.size() < 4 || args[3] != "--version") {
            cout << "No --version for minecraft" << endl;
            return;
        }

        const string& arg4 = args[3];
        if (args.size() < 5) {
            cout << "No Version for minecraft" << endl;
            return;
        }
        const string& arg5 = args[4];
        cout << "Chemin: " << mcDirectory << ", Version: " << arg4 << ", Version: " << arg5 << endl;

        string remoteFolderPath = mcDirectory + "/" + arg1 + "/";
        //executeCmd(channel, ("mkdir -p " + remoteFolderPath + "\n").c_str());
        //executeCmd(channel, ("cd " + remoteFolderPath + "\n").c_str());
    }

    else if (arg3 == "web") {
        cout << "Chemin: " << webDirectory << endl;

        // Reste du code spécifique à Web...
    } else {
        cout << "Out" << endl;
    }
        //executeCmd(channel, ("cd " + arg1 + "\n").c_str());
        //executeCmd(channel, ("mkdir " + arg2 + "\n").c_str());

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