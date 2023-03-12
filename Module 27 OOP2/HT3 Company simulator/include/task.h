//
// Created by Artem on 02.04.2023.
//

#pragma once

#ifndef COMPANY_SIMULATOR_TASK_H
#define COMPANY_SIMULATOR_TASK_H

class Task {
    char taskType;
    int taskId;
public:
    virtual void getInfo() = 0;
    virtual Task* create();
    virtual Task* create(int inTaskId, int inPersonId);
    ~Task() = default;
};

class MainTask : public Task {
public:
    void getInfo();
    MainTask();
    ~MainTask();
};

class SubTask : public Task {
    MainTask* parent;
public:
    void getInfo();
    SubTask();
    SubTask(int inTaskId);
    ~SubTask();
};

class TaskManager {
    TaskManager* instance = nullptr;
    TaskManager()
public:
    static TaskManager* TaskManager::create();
    ~TaskManager();
}

#endif //COMPANY_SIMULATOR_TASK_H
