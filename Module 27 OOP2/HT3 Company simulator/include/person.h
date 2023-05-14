//
// Created by Artem on 02.04.2023.
//
#include <string>

#pragma once

#ifndef COMPANY_SIMULATOR_PERSON_H
#define COMPANY_SIMULATOR_PERSON_H

<<<<<<< HEAD
//enum class PositionType { Head, Teamlead, Worker}; //Type of workers

class Person //Common class for all workers
{
    std::string name; //Worker name
    int personID = 0;
=======
class Person //Common class for all workers
{
    std::string name; //Worker name
    int personID = 0; //It sets when Person creating setPersonId().
>>>>>>> 2da7575d4460d3807a544cbae1e658cc4d624352
    Person();
public:
    ~Person();
    static Person* create();
<<<<<<< HEAD
   // std::string getName();
=======
    int getPersonId() const;
    std::string getPersonName();
>>>>>>> 2da7575d4460d3807a544cbae1e658cc4d624352
};

#endif //COMPANY_SIMULATOR_PERSON_H
