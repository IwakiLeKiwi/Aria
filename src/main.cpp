#include <iostream>
#include <chrono>

#include "aria.hpp"
#include "commands/commands.hpp"
#include "sshGlobals.hpp"

#pragma comment(lib, "ws2_32.lib")

using namespace std;

/* ------------------------------------------------------------------------------------------------- */

int main() {

    Aria::initStartupMessages();

    Aria::info("Aria booting...");

    Aria::initializeDiscord();

    Aria::info("Try to initialize libraries...");
    Aria::ssh::initializeLibs();
    Aria::info("Aria connecting in SSH...");
    Aria::ssh::connectSSH();
    Aria::info("Creating SSH channel...");
    Aria::ssh::createSSHChannel();
    Aria::ssh::createSFTPChannel();
    Commands::startCommandPrompt();
    Aria::ssh::closeSession();
    
    Aria::info("Aria is shutting down...");
    
    return 0;
}