//
// Created by Artem on 30.07.2023.
//
#ifndef COMPANY_SIMULATOR_TASK_H
#define COMPANY_SIMULATOR_TASK_H

//#include "person.h"

int setTaskID();

class Task {
public:
    int id = setTaskID();
    char category = 'A';
    int command = 0;
    ~Task() = default;
};

#endif //COMPANY_SIMULATOR_TASK_H
