#ifndef ARIA_HPP
    #define ARIA_HPP
    
    #include <iostream>
    #include <string>

    namespace Aria {
        void initStartupMessages();
        void initializeDiscord();
            
        void info(const char* msg);
        void warn(const char* msg);
        void err(const char* msg);
        void log(const char* msg);

        namespace ssh {
            void initializeLibs();
            void connectSSH();
            void createSSHChannel();
            void closesSSHChannel();
            void closeSession();
        }
    }

#endif