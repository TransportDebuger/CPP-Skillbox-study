//
// Created by Artem on 02.04.2023.
//
#include <string>

#pragma once

#ifndef COMPANY_SIMULATOR_PERSON_H
#define COMPANY_SIMULATOR_PERSON_H

class Person //Common class for all workers
{
    std::string name; //Worker name
    int personID = 0; //It sets when Person creating setPersonId().
    Person();
public:
    ~Person();
    static Person* create();
    int getPersonId() const;
    std::string getPersonName();
};

#endif //COMPANY_SIMULATOR_PERSON_H
