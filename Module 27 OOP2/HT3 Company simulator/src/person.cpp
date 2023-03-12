//
// Created by Artem on 02.04.2023.
//

#include <iostream>
#include "person.h"

int setPersonId() {
    static int counter = 0;
    return ++counter;
}

Person::Person() {
    std::cout << "Name of the person: ";
    std::cin >> this->name;
    this->personID = setPersonId();
    std::cout << "His person ID " << this->personID << std::endl;
}

Person* Person::create() {
    Person* p;
    p = new Person();
    return p;
}

int getPersonId() {
    return this->personID;
}

std::string getPersonName() {
    return this->name;
}

Person::~Person() = default;
