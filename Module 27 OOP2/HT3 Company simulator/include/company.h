//
// Created by Artem on 02.04.2023.
//
#include <string>
#include "person.h"
#include "task.h"

#pragma once

#ifndef COMPANY_SIMULATOR_COMPANY_H
#define COMPANY_SIMULATOR_COMPANY_H

class Department {
    int workersAmount = 0;
    Person* teamManager = nullptr;
    Person** workers;
    Department();
public:
    ~Department();
    static Department* create();
};

class Company {
    std::string name; //Company name
    Person* companyHead;
    int depsAmount = 0; //Amount of teams (deps) in company
    Department** departments = nullptr; //Array of departments;
    Company();
public:
    static Company* create();
    void showCompanyInfo();
    std::string getCompanyName();
    ~Company();
};

#endif //COMPANY_SIMULATOR_COMPANY_H
