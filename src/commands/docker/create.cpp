#include <iostream>
#include <sstream>
#include <cstring>
#include <algorithm>
#include <regex>

#include <thread>
#include <chrono>
#include <iomanip>

#include "aria.hpp"
#include "commands/commands.hpp"
#include "commands/commandsInfos.hpp"
#include "config.h"
#include "utils/progressBar.hpp"
#include "json/jsonCommands.hpp"

using namespace std;

/**
 * @author Iwaki
 */

/* ---------------------------------------------------------------------------------------------------------------------------------- */

string dockerfileContent(string javaVersion) {
    string content = "\
    ###############################################\n\
    # Utilisation de l'image de base Ubuntu 20.04 #\n\
    ###############################################\n\
    FROM ubuntu:latest\n\
    \n\
    #################################\n\
    # Installation des dependances #\n\
    #################################\n\
    \n\
    # Java\n\
    RUN apt-get update && apt-get install -y openjdk-"+std::string(javaVersion)+"-jre-headless\n\
    \n\
    # Screen\n\
    RUN apt-get update && apt-get install -y screen\n\
    ";
    return content;
}

string dockercomposeContent(string image, string entryPort, string exitPort, string volumes, string containerName) {
    string content = "\
    version: '3'\n\
    \n\
    services:\n\
        minecraft-server:\n\
            image: "+string(image)+"\n\
            ports:\n\
            - '"+string(entryPort)+":"+string(exitPort)+"'\n\
            volumes:\n\
            - "+string(volumes)+"\n\
            tty: true\n\
            container_name: "+string(containerName)+"\n\
    ";
    return content;
}

/**
 * @param containerPort
 */
string validateAndProcessPort(const string &containerPort) {
    std::regex onlyNumbers("^[0-9]+$");
    std::regex numberColonNumber("^[0-9]+:[0-9]+$");
    std::regex numberColon("^[0-9]+:$");

    string result = containerPort;

    if (std::regex_match(containerPort, onlyNumbers)) {
        result += ":" + result;
        return result;
    } 
    else if (std::regex_match(containerPort, numberColonNumber)) return containerPort;
    else if (std::regex_match(containerPort, numberColon)) {
        result.pop_back();
        result += ":" + result;
        return result;
    }
    else Aria::warn("Le format du port est invalide.");
}

/**
 * Main function
 * 
 * @param args Arguments de la ligne de commande
 */
void create_cmd(const vector<string> &args) {

    LIBSSH2_CHANNEL *channel = getSSHChannel();
    LIBSSH2_SFTP *sftp = getSFTPChannel();

    if (args.empty()) {
        COMMANDS_INFOS::USAGE::print_create_usage();
        return;
    }

    if (args.size() < 3 || args[1] != "--type") {
        Aria::warn("Please fill in the required information to create your container. For more information, type 'help create'.");
        return;
    }

    string containerName = args[0];
    string containerType = args[2];

    if (containerType == "minecraft" || containerType == "mc") {
        if (args.size() < 11) {
            Aria::warn("Please fill in all the arguments required to create a minecraft container. For more information, type 'help create'.");
            return;
        }
        if (args[3] != "--version" || args[5] != "--port" || args[7] != "--model" || args[9] != "--dir") {
            Aria::err("Invalid arguments. Please check the order of the arguments and try again. For more information, type 'help create'.");
            return;
        }

        string containerVersion = args[4];
        string containerModel = args[8];
        string url;
        if (containerModel == "vanilla") url = getServerJarDownloadLink(containerVersion, "vanilla");
        else if (containerModel == "forge") url = getServerJarDownloadLink(containerVersion, "forge");
        else {
            Aria::warn("Non-existent or unsupported model.");
            return;
        }

        string containerPort    = args[6];
        containerPort = validateAndProcessPort(containerPort);

        string containerDirectory = args[10];
        if (!checkIfDirectoryExist(containerDirectory)) return;

        string firstDirectory = (containerDirectory.back() == '/') ? (containerDirectory + containerName + "/") : (containerDirectory + "/" + containerName + "/");
        string secondDirectory = (firstDirectory + "server/");
        string dockerfilePath = (firstDirectory + "Dockerfile");
        string dockercomposePath = (firstDirectory + "docker-compose.yml");
        string eulaFilePath = (secondDirectory + "eula.txt");

        vector<function<void()>> tasks;
        std::string content = "...";

        tasks.push_back([&]() { createDirectory(sftp, firstDirectory); });
        tasks.push_back([&]() { createDirectory(sftp, secondDirectory); });
        tasks.push_back([&]() { writeFile(sftp, dockerfilePath, content); });
        tasks.push_back([&]() { writeFile(sftp, dockercomposePath, content); });
        tasks.push_back([&]() { executeSSHCommand(channel, ("wget -P " + secondDirectory + " " + url + string("\n")).c_str()); });
        tasks.push_back([&]() { writeFile(sftp, eulaFilePath, string("eula = true")); });

        executeTaskWithProgressBar(tasks);

        Aria::log("Version        : ", containerVersion);
        Aria::log("Model          : ", containerModel);
        Aria::log("Port           : ", containerPort);
        Aria::log("Name           : ", containerName);
        Aria::log("Type           : ", containerType);
        Aria::log("Jar            : ", url);
        Aria::log("Java Version   : ", getJavaVersionRequired(containerVersion));
        Aria::log("Dir            : ", firstDirectory);
        Aria::log("Server files   : ", secondDirectory);
        Aria::log("Dockerfile     : ", dockerfilePath);
        Aria::log("docker-compose : ", dockercomposePath);
        Aria::log("eula           : ", eulaFilePath);
        Aria::log("server.jar     : ", secondDirectory + "server.jar");

    } else if (containerType == "web") {
        if (args.size() < 9) {
            Aria::warn("Please fill in all the arguments required to create a web container. For more information, type 'help create'.");
            Aria::warn("/!\\ Not implemented yet. Please wait next updates");
            return;
        }
    }
}