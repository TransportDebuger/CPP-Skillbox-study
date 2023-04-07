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
    int personID = 0;
    Person();
public:
    ~Person();
    static Person* create();
   // std::string getName();
};

#endif //COMPANY_SIMULATOR_PERSON_H
