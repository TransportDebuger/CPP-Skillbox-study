//
// Created by Artem on 21.01.2023.
//
#include "mod-ram.h"
#include <string>

#ifndef COMPUTER_SIMULATOR_MOD_CMP_H
#define COMPUTER_SIMULATOR_MOD_CMP_H

struct Computer {
private:
    ramSet* ram;
public:
    Computer();
    ~Computer();

    void gpuDisplay();
    void write();
    int read(const int idx);
    void load();
    void save();
    void sum();
};

#endif //COMPUTER_SIMULATOR_MOD_CMP_H
