//
// Created by Artem on 31.01.2023.
//
#include <vector>
#include <string>
#include "node.h"

#ifndef OPERATION_SIMULATOR_OPERATION_H
#define OPERATION_SIMULATOR_OPERATION_H

enum class opercmd {
    SCALPEL,
    HEMOSTAT,
    TWEEZERS,
    SUTURE,
    ENDOPER,
    UNKNOWN
};

struct lognode {
    opercmd ccode;
    node* fnode = nullptr;
};

void operate();

#endif //OPERATION_SIMULATOR_OPERATION_H
