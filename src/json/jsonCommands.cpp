#include "json/jsonCommands.hpp"

using namespace std;

/**
 * @param version
 * @param model
 */
string getServerJarDownloadLink(const string &version, const string &model) {
    ifstream file("../versions.json");
    json data;
    file >> data;

    if (model == "vanilla") 
        if (data["minecraft"]["server_jar"]["vanilla"]["download_links"].contains(version))
            return data["minecraft"]["server_jar"]["vanilla"]["download_links"].at(version);
        else throw runtime_error("Version not found: " + version);
    else if (model  == "forge") return data["minecraft"]["server_jar"]["forge"]["download_links"].at(version);
    
    throw runtime_error("Unsupported model: " + model);
}

/**
 * @param version
 */
string getJavaVersionRequired(const string &version) {
    ifstream file("../versions.json");
    json data;

    if (!file.is_open()) {
        Aria::err("Le fichier versions.json n'a pas pu etre ouvert");
        return "";
    }

    try {
        file >> data;
    } catch (const exception &e) {
        Aria::err("Erreur lors du parsing du fichier JSON");
        return "";
    }

    vector<string> allVersions = data["minecraft"]["version"]["all_supported_versions"].get<vector<string>>();

    auto it = find(allVersions.begin(), allVersions.end(), version);
    if (it == allVersions.end()) {
        Aria::warn("Version non trouvée ou non supportée");
        return "";
    }

    int index = distance(allVersions.begin(), it);

    if (index >= 0 && index <= find(allVersions.begin(), allVersions.end(), "1.13.2") - allVersions.begin()) return "8";
    else if (index <= find(allVersions.begin(), allVersions.end(), "1.16.5") - allVersions.begin()) return "11";
    else if (index <= std::find(allVersions.begin(), allVersions.end(), "1.17.1") - allVersions.begin()) return "16";
    else if (index <= std::find(allVersions.begin(), allVersions.end(), "1.18.2") - allVersions.begin()) return "17";
    else return "20";
}

/**
 * @param containerType
 * @param containerName
 * @param containerVersion
 * @param containerPort
 * @param containerImage
 * @param volumes
 */
void addContainerToJson(const std::string &containerType, const std::string &containerName,
                            const std::string &containerVersion, const std::string &containerPort,
                            const std::string &containerImage, const std::vector<std::string> &volumes) {

    ifstream inputFile("../containers.json");
    json data;

    if (inputFile.is_open()) {
        inputFile >> data;
        inputFile.close();
    } else {
        data["containers"] = json::object();
    }

    json containerVolumes = json::object();
    for (size_t i = 0; i < volumes.size(); i++) {
        containerVolumes["volume" + to_string(i + 1)] = volumes[i];
    }

    json newContainer = {
        {"containerVersion", containerVersion},
        {"containerPort", containerPort},
        {"containerImage", containerImage},
        {"containerVolumes", containerVolumes}  
    };

    if (!data["containers"].contains(containerType)) {
        data["containers"][containerType] = json::object();
    }
    data["containers"][containerType][containerName] = newContainer;

    ofstream outputFile("../containers.json");
    outputFile << data.dump(4);
    outputFile.close();
}