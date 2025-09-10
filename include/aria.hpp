#ifndef ARIA_HPP
    #define ARIA_HPP
    
    #include <iostream>

    namespace Aria {
        void initStartupMessages();
        void initializeDiscord();

        template<typename T>
        void info(const T& arg) {
            std::cout << "[\u001b[32;1mINFO\u001b[0m] " << arg << std::endl;
        }
        template<typename T>
        void warn(const T& arg) {
            std::cout << "[\u001b[33;1mWARNING\u001b[0m] " << arg << std::endl;
        }
        template<typename T>
        void err(const T& arg) {
            std::cout << "[\u001b[31;1mERROR\u001b[0m] " << arg << std::endl;
        }
        template<typename T>
        void log(const T& arg) {
            std::cout << "[\u001b[35;1mLOG\u001b[0m] " << arg << std::endl;
        }
        template<typename T>
        void print(const T& arg) {
            std::cout << "\u001b[0m" << arg << std::endl;
        }

        template<typename T, typename... Args>
        void info(const T& arg, const Args... args) {
            std::cout << "[\u001b[32;1mINFO\u001b[0m] ";
            std::cout << arg;
            ((std::cout << args), ...);
            std::cout << std::endl;
        }
        template<typename T, typename... Args>
        void warn(const T& arg, const Args... args) {
            std::cout << "[\u001b[33;1mWARNING\u001b[0m] ";
            std::cout << arg;
            ((std::cout << args), ...);
            std::cout << std::endl;
        }
        template<typename T, typename... Args>
        void err(const T& arg, const Args... args) {
            std::cout << "[\u001b[31;1mERROR\u001b[0m] ";
            std::cout << arg;
            ((std::cout << args), ...);
            std::cout << std::endl;
        }
        template<typename T, typename... Args>
        void log(const T& arg, const Args... args) {
            std::cout << "[\u001b[35;1mLOG\u001b[0m] ";
            std::cout << arg;
            ((std::cout << args), ...);
            std::cout << std::endl;
        }
        template<typename T, typename... Args>
        void print(const T& arg, const Args... args) {
            std::cout << "\u001b[0m";
            std::cout << arg;
            ((std::cout << args), ...);
            std::cout << std::endl;
        }

        namespace ssh {
            void initializeLibs();
            void connectSSH();
            void createSSHChannel();
            void createSFTPChannel();
            void closeSSHChannel();
            void closeSFTPChannel();
            void closeSession();
        }
    }

#endif