//
// Created by Artem on 29.07.2023.
//
#include <iomanip>
#include <iostream>
#include <sstream>

#include "company.h"
#include "routines.h"

std::string setUnitName() {
    std::cout << "Set name: ";
    return setline();
}

Company::Company(IUnit* inParent) {
    this->headUnit = inParent;
    this->name = setUnitName();
    info();
}

void Company::info() { std::cout << "Company " << name << " created.\n"; }

void Company::detailed() {
    std::cout << "Company name: " << name << std::endl;
    std::cout << "Company CEO: " << manager->name << " (personal ID: " << manager->id << ")\n";
    if (!childUnit.size()) {
        std::cout << "There are not any departments in company " << name << std::endl;
    } else {
        std::cout << "Departments: " << childUnit.size() << std::endl;
        std::cout << "Department                  Manager                         Workers\n";
        for (unsigned int i = 0; i < childUnit.size(); i++) {
            std::stringstream mngr;
            mngr << childUnit[i]->manager->name << " (personal ID: " << childUnit[i]->manager->id << ")";
            std::cout << std::setw(28) << std::left << childUnit[i]->name << std::setw(32) << std::left
                      << mngr.str() << childUnit[i]->workers.size() << std::endl;
        }
    }
}

Division::Division(IUnit* inParent) {
    this->name = setUnitName();
    this->headUnit = inParent;
    info();
}

void Division::info() { std::cout << "Division " << name << " created\n"; }

void Division::detailed() {
    std::cout << "Company name: " << name << std::endl;
    std::cout << "Company CEO: " << manager->name << "(personal ID: " << manager->id << ")\n";
}

IUnit* CompanyFactory::createUnit(IUnit* inParent) { return new Company(nullptr); }

IUnit* DivisionFactory::createUnit(IUnit* inParent) { return new Division(inParent); }