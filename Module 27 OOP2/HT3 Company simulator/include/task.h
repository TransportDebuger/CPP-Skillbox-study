//
// Created by Artem on 02.04.2023.
//

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
};

#endif //COMPANY_SIMULATOR_TASK_H
