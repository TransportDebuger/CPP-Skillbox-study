//
// Created by Artem on 29.07.2023.
//
#include <iostream>
#include "company.h"
#include "routines.h"

std::string setUnitName() {
    std::cout << "Set name: ";
    return setline();
}

Company::Company(IUnit *inParent) {
    this->headUnit = inParent;
    this->name = setUnitName();
    info();
}

void Company::info() {
    std::cout << "Company " << name << " created.\n";
}

Division::Division(IUnit *inParent) {
    this->headUnit=inParent;
    this->name = setUnitName();
    info();
}

void Division::info() {
    std::cout << "Division " << name << " created\n";
}

IUnit* CompanyFactory::createUnit(IUnit* inParent) {
    return new Company(nullptr);
}

IUnit* DivisionFactory::createUnit(IUnit* inParent) {
    return new Division(inParent);
}