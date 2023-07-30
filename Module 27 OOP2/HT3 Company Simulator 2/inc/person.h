//
// Created by Artem on 29.07.2023.
//
#include <string>

#ifndef HT3_COMPANY_SIMULATOR_2_PERSON_H
#define HT3_COMPANY_SIMULATOR_2_PERSON_H

#include "company.h"
#include "task.h"

int setPersonId();
std::string setPersonName();

class IUnit;

class IPerson {
public:
    std::string name;
    int id = setPersonId();
    IUnit* appointedUnit;
    virtual void info() = 0;
    virtual ~IPerson() = default;
};

class CEO : public IPerson {
public:
    CEO(IUnit* inUnit);
    void info() override;
};

class Teamlead : public IPerson {
public:
    Teamlead(IUnit* inUnit);
    void info() override;
};

class Worker : public IPerson {
public:
    Worker(IUnit* inUnit);
    void info() override;
};

class PersonFactory {
public:
    virtual IPerson* createPerson(IUnit* inUnit) = 0;
    virtual ~PersonFactory() = default;
};

class CEOFactory : public PersonFactory {
public:
    IPerson* createPerson(IUnit* inUnit) override;
};

class TeamleadFactory : public PersonFactory {
public:
    IPerson* createPerson(IUnit* inUnit) override;
};

class WorkerFactory : public PersonFactory {
public:
    IPerson* createPerson(IUnit* inUnit) override;
};

#endif //HT3_COMPANY_SIMULATOR_2_PERSON_H
