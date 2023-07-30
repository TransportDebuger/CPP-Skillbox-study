#include <iostream>
#include "company.h"
#include "person.h"
#include "task.h"

enum navcode{
    EXIT = 0
};

auto* cmp_fctr = new CompanyFactory;
auto* ceo_fctr = new CEOFactory;
auto* div_fctr = new DivisionFactory;
auto* tl_fctr = new TeamleadFactory;
//auto* wrc_fctr = new WorkerFactory;

IUnit* initialize() {
    std::cout << "Company simulator!" << std::endl;
    std::cout << "\nLet's start!\n";
    std::cout << "First thing first! Create the Company\n";
    IUnit* company = cmp_fctr->createUnit();
    if (company->manager == nullptr) {
        std::cout << "We need CEO. ";
        company->manager = ceo_fctr->createPerson(company);
    }
    return company;
}

IUnit* addDepartment(IUnit* inUnit) {
    std::cout << "Department creation\n";
    IUnit* dep = div_fctr->createUnit(inUnit);
    dep->manager = tl_fctr->createPerson(dep);
    return dep;
}

void displayinfo(IUnit* inCompany) {
    std::cout << "=========================================\n";
    std::cout << "Company: " << inCompany->name << std::endl;
    std::cout << "CEO: " << inCompany->manager->name << std::endl;
    std::cout << "Number of departments: " << inCompany->childUnit.size() << std::endl;
    std::cout << "=========================================\n";
}

void displaynavigation(int inItem) {
    if (inItem == 0) {
        std::cout << "1) Show company info\n";
        std::cout << "2) Manage departments\n";
    } else if (inItem == 2) {
        std::cout << "1) Add department\n";
        std::cout << "2) Show department info\n";
        std::cout << "3) Manage workers\n";
    }
    std::cout << "0) Exit\n";
    std::cout << "\n\n\n=========================================\n";
    std::cout << "Choose menu item: ";
}

int action(int inItem, int inCommand, IUnit* inCompany) {
    if (inItem == 0) {
        if (inCommand == 1) inCompany->detailed();
        return inCommand;
    } else if (inItem==2) {
        if (inCommand==1) inCompany->childUnit.push_back(addDepartment(inCompany));
        else inItem = 0;
    }
    else if (inItem!=0 && inCommand!=0){
        inItem = inCommand;
    } else {
        inItem = 0;
    }
    return inItem;
}

int main() {
    IUnit* company = nullptr;
    if (!company) {
        company = initialize();
    }
    int cli, menuitem=0;
    bool isExit = false;
    do {
        displayinfo(company);
        displaynavigation(menuitem);
        std::cin >> cli;
        if (menuitem==0 && cli == EXIT) isExit=true;
        else menuitem = action(menuitem, cli, company);
    } while (!isExit);

    //std::cout << "How many departments in company? ";
    //int deps;
    //std::cin >> deps;
    //company->childUnit.resize(3);
    //for (int i=0; i<deps; ++i) {
     //   company->childUnit[i] = div_fctr->createUnit(company);
    //    company->childUnit[i]->manager = tl_fctr->createPerson(company->childUnit[i]);
    //}
    return 0;
}
