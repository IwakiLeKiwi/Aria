#include <iostream>
#include <sstream>

#include "sshGlobals.hpp"
#include "aria.hpp"
#include "commands/commands.hpp"
#include "json/jsonCommands.hpp"

void start_cmd(const std::vector<std::string>& args) {
    LIBSSH2_CHANNEL *channel = getSSHChannel();
    
    if (args.empty()) {
        Aria::err("");
        return;
    } else {
        const std::string containerName = "paladium";
        const std::string volumeToDelete = "volume1";

        updateContainerJson(containerName, [&volumeToDelete](json& container) {
            // Vérifier si la clé (volume) existe avant de la supprimer
            if (container["volumes"].contains(volumeToDelete)) {
                container["volumes"].erase(volumeToDelete);
            } else {
                std::cerr << "Le volume '" << volumeToDelete << "' n'existe pas pour le conteneur '" << "'" << std::endl;
            }
        });
    }
}