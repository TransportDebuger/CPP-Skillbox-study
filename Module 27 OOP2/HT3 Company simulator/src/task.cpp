//
// Created by Artem on 02.04.2023.
//

//#include <iostream>
#include <random>
#include "task.h"

Task* Task::create(int inTaskInput, int inPersonId) {
    Task* p = new Task();
    std::srand(inTaskInput + inPersonId);
    p -> taskId.type = char(65) + (std::rand() % 3);
    if (inPersonId == 0) p -> taskId.id =  inTaskInput;
    else p -> taskId.id = std::rand();
    return p;
}
