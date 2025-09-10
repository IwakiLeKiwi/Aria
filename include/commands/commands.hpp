#ifndef COMMANDS_HPP
    #define COMMANDS_HPP
    
    #include <vector>
    #include <functional>
    #include "sshGlobals.hpp"

    namespace Commands {
        void startCommandPrompt();
    }

    // Basics Commands
    void ls_cmd(const std::vector<std::string>& args);
    void help_cmd(const std::vector<std::string>& args);
    void cd_cmd(const std::vector<std::string>& args);
    void del_cmd(const std::vector<std::string>& args);
    void info_cmd(const std::vector<std::string>& args);
    void version_cmd(const std::vector<std::string>& args);
    // Docker commands
    void create_cmd(const std::vector<std::string>& args);
    void start_cmd(const std::vector<std::string>& args);
#endif