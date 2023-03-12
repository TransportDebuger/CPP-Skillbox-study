//
// Created by Artem on 02.04.2023.
//

#include <iostream>
#include <string>
#include "task.h"

int setTaskId(int inTaskGoal, int inPersonId) {
    std::srand(inTaskGoal+inPersonId);
    return std::rand();
}

Task* Task::create() {
    Task* p = nullptr;
    p = new MainTask();
    return p;
}

Task* Task::create(int inTaskId, int inPersonId) {
    Task* p = nullptr;
    p = new SubTask(inTaskId, inPersoId);
    return p;
}

MainTask::MainTask() {
    std::cout << "Set task ID: ";
    std::cin >> this->taskId;
    std::srand(this->taskId);
    this->taskType = 65 + (std::rand() % 3);
}

SubTask::SubTask(int inTaskId, int inPersonId) {
    this->taskId = setTaskId(inTaskId, inPersonId);
    this->taskType = 65 + (std::rand() % 3);
}
