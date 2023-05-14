//
// Created by Artem on 02.04.2023.
//

#include <iostream>
#include "person.h"

int setPersonId() {
    static int counter = -1;
    return ++counter;
}

Person::Person() {
    std::cout << "Name: ";
    std::cin >> this->name;
    this->personID = setPersonId();
}

Person* Person::create() {
    Person* p = new Person();
    return p;
}

int Person::getPersonId() const {
    return this->personID;
}

std::string Person::getPersonName() {
    return this->name;
}

Person::~Person() = default;
