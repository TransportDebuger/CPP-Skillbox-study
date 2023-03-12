//
// Created by Artem on 02.04.2023.
//

#include <iostream>
#include "company.h"
#include "person.h"

Company::Company() {
    std::cout << "Name your company: ";
    std::cin >> this->name;
    std::cout << "Tell something about company head\n";
    this->companyHead = Person::create();
    std::cout << "How many teams in the company: ";
    std::cin >> this->depsAmount;
    std::cout << "\nOk. Let's work with departments\n";
    this->departments = new Department *[this->depsAmount];
    for (int i = 0; i < this->depsAmount; i++) {
        std::cout << "Creating team #" << i << std::endl;
        this->departments[i] = Department::create();
    }
}

Company::~Company() {
    delete this->companyHead;
    for (int i = 0; i < this->depsAmount; i++ ) {
        if (this->departments[i] != nullptr) delete this->departments[i];
    }
}

Company* Company::create() {
    Company* p;
    p = new Company();
    return p;
}

std::string Company::getCompanyName() {
    return this->name;
}

void Company::showCompanyInfo() {
    std::cout << "Company: " << this->getCompanyName() << std::endl;
    std::cout << "Company CEO: " << this->companyHead->getPersonName() << " " 
        << this->companyHead->getPersonId() << std::endl;
    std::cout << "Count of Departments: " << this->depsAmount << std::endl;
};

Department::Department() {
    std::cout << "How many workers in team: ";
    std::cin >> this->workersAmount;
    std::cout << "Who manage this team?\n";
    this->teamManager = Person::create();
    std::cout << "Who work in the team?\n";
    this->workers = new Person *[this->workersAmount];
    for (int i = 0; i < this->workersAmount; i++) {
        std::cout << "Create worker #" << i << std::endl;
        this->workers[i] = Person::create();
    }
}

Department *Department::create() {
    Department* p;
    p = new Department();
    return p;
}

Department::~Department() {
    delete this->teamManager;
    for (int i = 0; i < this->workersAmount; i++ ) {
        if (this->workers[i] != nullptr) delete this->workers[i];
    }
}
