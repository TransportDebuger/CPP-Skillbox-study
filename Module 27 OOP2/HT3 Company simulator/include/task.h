//
// Created by Artem on 02.04.2023.
//

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
};

#endif //COMPANY_SIMULATOR_TASK_H
