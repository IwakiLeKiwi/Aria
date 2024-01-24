#ifndef COMMANDS_HPP
    #define COMMANDS_HPP
    
    #include <vector>
    #include <functional>
    #include <unordered_map>
    #include "sshGlobals.hpp"

    namespace Commands {
        void startCommandPrompt();
    }

    void executeSSHCommand(LIBSSH2_CHANNEL* oChannel, const char* cmd);
    void executeSSHCommandWithOutput(LIBSSH2_CHANNEL* oChannel, const char* cmd);

    // Command list
    void ls_cmd(const std::vector<std::string>& args);
    void help_cmd(const std::vector<std::string>& args);
    void go_cmd(const std::vector<std::string>& args);
    void del_cmd(const std::vector<std::string>& args);
    void info_cmd(const std::vector<std::string>& args);
    void create_cmd(const std::vector<std::string>& args);
#endif