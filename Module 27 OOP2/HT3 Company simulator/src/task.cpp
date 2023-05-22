//
// Created by Artem on 02.04.2023.
//

<<<<<<< HEAD
#include <string>
#include "task.h"


Task* Task::create() {
    Task* p = nullptr;
=======
//#include <iostream>
#include <random>
#include "task.h"

Task* Task::create(int inTaskInput, int inPersonId) {
    Task* p = new Task();
    std::srand(inTaskInput + inPersonId);
    p -> taskId.type = char(65) + (std::rand() % 3);
    if (inPersonId == 0) p -> taskId.id =  inTaskInput;
    else p -> taskId.id = std::rand();
>>>>>>> 2da7575d4460d3807a544cbae1e658cc4d624352
    return p;
}
