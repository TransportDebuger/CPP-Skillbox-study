//
// Created by Artem on 29.07.2023.
//
#include <string>
#include <vector>

#ifndef HT3_COMPANY_SIMULATOR_2_COMPANY_H
#define HT3_COMPANY_SIMULATOR_2_COMPANY_H

#include "person.h"

std::string setUnitName();

class IUnit {
public:
    std::string name;;
    IUnit* headUnit;
    IPerson* manager;
    std::vector<IUnit *> childUnit;
    virtual void info() = 0;
    virtual ~IUnit() = default;
};

class Company : public IUnit {
public:
    Company(IUnit* inParent = nullptr);
    void info() override;
};

class Division : public IUnit {
public:
    Division(IUnit* inParent);
    void info() override;
};

class IUnitFactory {
public:
    virtual IUnit* createUnit(IUnit* inParent) = 0;
    virtual ~IUnitFactory() = default;
};

class CompanyFactory : public IUnitFactory {
public:
    IUnit* createUnit(IUnit* inParent=nullptr) override;
};

class DivisionFactory : public IUnitFactory {
public:
    IUnit* createUnit(IUnit* inParent) override;
};



#endif //HT3_COMPANY_SIMULATOR_2_COMPANY_H
