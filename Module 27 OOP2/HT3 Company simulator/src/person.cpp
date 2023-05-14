//
// Created by Artem on 02.04.2023.
//

#include <iostream>
#include "person.h"

int setPersonId() {
<<<<<<< HEAD
    static int counter = 0;
=======
    static int counter = -1;
>>>>>>> 2da7575d4460d3807a544cbae1e658cc4d624352
    return ++counter;
}

Person::Person() {
<<<<<<< HEAD
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

=======
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

>>>>>>> 2da7575d4460d3807a544cbae1e658cc4d624352
Person::~Person() = default;
