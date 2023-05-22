//
// Created by Artem on 02.04.2023.
//
#include "person.h"
#pragma once

#ifndef COMPANY_SIMULATOR_TASK_H
#define COMPANY_SIMULATOR_TASK_H

struct TaskIdentifier {
    int id;
    char type;
};

class Task {
    TaskIdentifier taskId;
    Task() = default;
public:
    ~Task() = default;
    static Task* create(int inTaskInput, int inPersonId);
};

struct TaskRecord {
    Person* worker;
    Task* taskRecord;
}

class TaskBroker {
    Person* manager = nullptr;
    TaskRecord** taskList;
};

#endif //COMPANY_SIMULATOR_TASK_H
