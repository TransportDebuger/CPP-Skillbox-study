//
// Created by Artem on 02.04.2023.
//
#include <string>

#pragma once

#ifndef COMPANY_SIMULATOR_PERSON_H
#define COMPANY_SIMULATOR_PERSON_H

//enum class PositionType { Head, Teamlead, Worker}; //Type of workers

class Person //Common class for all workers
{
    std::string name; //Worker name
    int personID = 0; //Personal ID setted automaticaly setPersonId().
    Person();
public:
    ~Person();
    int getPersonId();
    std::string getPersonName();
    static Person* create();
};

#endif //COMPANY_SIMULATOR_PERSON_H
