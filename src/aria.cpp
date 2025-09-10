#include <iostream>
#include <chrono>
#include <thread>

#include "aria.hpp"
#include "discord.hpp"
#include "utils.hpp"
#include "config.h"

Discord *discord;

using namespace std;

void Aria::initStartupMessages() {
    cout << Utils::Colors::BLUE << R"(
    _     ____   ___     _
   / \   |  _ \ |_ _|   / \
  / _ \  | |_) | | |   / _ \
 / ___ \ |  _ <  | |  / ___ \
/_/   \_\|_| \_\|___|/_/   \_\)" << Utils::Colors::RESET << endl;
cout << 
     Utils::Colors::BLUE_BOLD_BRIGHT << ":: Aria ::"
     << "\t  "
     << Utils::Colors::YELLOW << "(" << PROJECT_VERSION << ")"
     << Utils::Colors::RESET << endl;
cout << Utils::Colors::CYAN 
     << "============================================\n"
     << "SSH connection, simplifying docker commands\n"
     << ">> Build by " << AUTHOR << "\n"
     << "============================================\n" << Utils::Colors::RESET << endl;
}

void Aria::initializeDiscord() {
    discord->initializeDiscordLibs();
    discord->update();
}