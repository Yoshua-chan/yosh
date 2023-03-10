#pragma once

#include <string>
#include <vector>
#include <iostream>
#include <filesystem>
#include <map>
#include "prompt.hpp"
#include "parser.hpp"

class Shell {
public:
    // Shell();
    unsigned int execute_command(std::string command);
    int loop();
    void init();
private:
    Prompt prompt;
    Parser parser;

    unsigned int execute(Command& command);

    // BUILTINS
    void welcome();
    void exit();
    void cd(std::string path);
    void help();
    void pwd();
    void export_var(std::string name, std::string value); 
    void assign_var(std::string name, std::string value);
    void display_vars(void);
    void handle_builtin(Command command);
    

    std::vector<std::string> history;
    std::map<std::string, std::string> variables;
    std::string getvar(std::string var);
};