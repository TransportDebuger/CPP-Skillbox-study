//
// Created by Artem on 02.04.2023.
//

<<<<<<< HEAD
#ifndef COMPANY_SIMULATOR_TASK_H
#define COMPANY_SIMULATOR_TASK_H

class Task {
    char taskType;
    int taskId;
public:
    virtual void getInfo() = 0;
    virtual Task* create();
    ~Task() = default;
};

class GeneralTask : public Task {
public:
    void getInfo();
    GeneralTask();
    ~GeneralTask();
};

class SubTask : public Task {
    GeneralTask* parent;
public:
    void getInfo();
    SubTask();
    ~SubTask();
=======
#pragma once

#ifndef COMPANY_SIMULATOR_TASK_H
#define COMPANY_SIMULATOR_TASK_H

struct TaskIdentifier {
    int id;
    char type;
};

class Task {
    TaskIdentifier taskId;
    Task();
public:
    ~Task() = default;
    static Task* create(int inTaskInput, int inPersonId);
>>>>>>> 2da7575d4460d3807a544cbae1e658cc4d624352
};

#endif //COMPANY_SIMULATOR_TASK_H
