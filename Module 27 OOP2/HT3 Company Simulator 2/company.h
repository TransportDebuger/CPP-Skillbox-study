//
// Created by Artem on 29.07.2023.
//
#include <string>
#include <vector>

#include "person.h"

#ifndef HT3_COMPANY_SIMULATOR_2_COMPANY_H
#define HT3_COMPANY_SIMULATOR_2_COMPANY_H

class IUnit {
   public:
    std::string name;
    IUnit* headUnit = nullptr;
    IPerson* manager = nullptr;
    std::vector<IUnit*> childUnit;
    std::vector<IPerson*> workers;
    virtual void info() = 0;
    virtual void detailed() = 0;
    virtual ~IUnit() = default;
};

class Company : public IUnit {
   public:
    Company(IUnit* inParent = nullptr);
    void info() override;
    void detailed() override;
};

class Division : public IUnit {
   public:
    Division(IUnit* inParent);
    void info() override;
    void detailed() override;
};

class IUnitFactory {
   public:
    virtual IUnit* createUnit(IUnit* inParent) = 0;
    virtual ~IUnitFactory() = default;
};

class CompanyFactory : public IUnitFactory {
   public:
    IUnit* createUnit(IUnit* inParent = nullptr) override;
};

class DivisionFactory : public IUnitFactory {
   public:
    IUnit* createUnit(IUnit* inParent) override;
};

#endif  // HT3_COMPANY_SIMULATOR_2_COMPANY_H
