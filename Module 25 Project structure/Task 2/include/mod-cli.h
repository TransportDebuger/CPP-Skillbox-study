//
// Created by Artem on 28.01.2023.
//
#include <string>
#include "mod-cmp.h"

#ifndef COMPUTER_SIMULATOR_MOD_CLI_H
#define COMPUTER_SIMULATOR_MOD_CLI_H

enum class commands {
    EXIT,
    INPUT,
    READ,
    WRITE,
    SAVE,
    LOAD,
    DISPLAY,
    SUM,
    UNKNOWN
};

commands cmdconvert(const std::string &cmd);
void Execute(commands cmd, Computer *cmp);

#endif //COMPUTER_SIMULATOR_MOD_CLI_H
