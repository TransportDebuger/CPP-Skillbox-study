//
// Created by Artem on 02.04.2023.
//

#include <iostream>
#include "person.h"

Person::Person() {
    std::cout << "Name of the person: ";
    std::cin >> this->name;
}

Person* Person::create() {
    Person* p;
    p = new Person();
    return p;
}

Person::~Person() = default;
