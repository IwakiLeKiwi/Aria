#ifndef COMMANDS_HPP
    #define COMMANDS_HPP
    
    #include <vector>
    #include "sshGlobals.hpp"

    void startCommandPrompt();

    void executeCmd(LIBSSH2_CHANNEL* oChannel, const char* cmd);
    void executeCmdOutput(LIBSSH2_CHANNEL* oChannel, const char* cmd);

    void ls_cmd(const std::string& arg);
    void help_cmd(const std::string& arg);
    void go_cmd(const std::string& arg);
    void del_cmd(const std::string& arg);
    void info_cmd(const std::string& arg);
    void create_cmd(const std::vector<std::string>& args);
#endif