#include <chrono>

#include "config.h"
#include "discord.hpp"

void Discord::initializeDiscordLibs() {
    DiscordEventHandlers handle;
    memset(&handle, 0, sizeof(handle));
    Discord_Initialize(DISCORD_APP_ID, &handle, 1, NULL);
}

void Discord::update() {
    DiscordRichPresence discordPresence;
    memset(&discordPresence, 0, sizeof(discordPresence));

    auto now = std::chrono::system_clock::now();
    auto duration = now.time_since_epoch();
    discordPresence.startTimestamp = std::chrono::duration_cast<std::chrono::seconds>(duration).count();

    discordPresence.state = "🧠 Braining...";
    discordPresence.details = "By Iwaki 👑";
    discordPresence.largeImageKey = "logo";
    discordPresence.largeImageText = "SSH connection, simplifying docker commands";
    Discord_UpdatePresence(&discordPresence);
}