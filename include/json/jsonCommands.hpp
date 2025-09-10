#ifndef JSON_COMMANDS_HPP
    #define JSON_COMMANDS_HPP

    #include <nlohmann/json.hpp>
    #include <fstream>
    #include <string>
    #include <vector>
    #include "aria.hpp"

    using json = nlohmann::json;

    std::string getServerJarDownloadLink(const std::string &version, const std::string &model);
    std::string getJavaVersionRequired(const std::string &version);
    void addContainerToJson(const std::string &containerType, const std::string &containerName,
                            const std::string &containerVersion, const std::string &containerPort,
                            const std::string &containerImage, const std::vector<std::string> &volumes);

#endif