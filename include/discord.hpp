#ifndef DISCORD_HPP
    #define DISCORD_HPP

    #include <discord_register.h>
    #include <discord_rpc.h>
    #include <Windows.h>

    class Discord {
        public:
            void initializeDiscordLibs();
            void update();
    };

#endif