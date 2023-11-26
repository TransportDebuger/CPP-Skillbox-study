#include <string>

#ifndef HT3_COMPANY_SIMULATOR_2_PERSON_H
#define HT3_COMPANY_SIMULATOR_2_PERSON_H

#include "task.h"

class IUnit;

class IPerson {
   public:
    std::string name;
    int id;
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

#endif  // HT3_COMPANY_SIMULATOR_2_PERSON_H
