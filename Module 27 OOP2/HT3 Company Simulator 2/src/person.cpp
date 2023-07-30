//
// Created by Artem on 29.07.2023.
//
#include <iostream>
#include <string>
#include "routines.h"
#include "company.h"
#include "person.h"

int setPersonId() {
    static int id = 0;
    return id++;
}

std::string setPersonName() {
    std::cout << "Set person name: ";
    return setline();
}

void CEO::info() {
    std::cout << name << " created and appointed as head of " << appointedUnit->name << std::endl;
}

void Teamlead::info() {
    std::cout << name << " created (pid: " << id << ") and appointed as head of " << appointedUnit->name << std::endl;
}

void Worker::info() {
    std::cout << name << "created (pid: " << id << ") and appointed to " << appointedUnit->name << std::endl;
}

CEO::CEO(IUnit* inUnit) {
    this->name = setPersonName();
    this->appointedUnit = inUnit;
    info();
}

Teamlead::Teamlead(IUnit* inUnit) {
    this->name = setPersonName();
    this->appointedUnit = inUnit;
    info();
}

Worker::Worker(IUnit* inUnit) {
    this->name = setPersonName();
    this->appointedUnit = inUnit;
    info();
}

IPerson* CEOFactory::createPerson(IUnit* inUnit) {
    return new CEO(inUnit);
}

IPerson* TeamleadFactory::createPerson(IUnit* inUnit) {
    return new Teamlead(inUnit);
}

IPerson* WorkerFactory::createPerson(IUnit* inUnit) {
    return new Worker(inUnit);
}