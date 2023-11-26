#include <iostream>
#include <sstream>
#include <iomanip>

#include "company.h"
#include "person.h"

enum navcode { EXIT = 0 };

auto* cmp_fctr = new CompanyFactory;
auto* ceo_fctr = new CEOFactory;
auto* div_fctr = new DivisionFactory;
auto* tl_fctr = new TeamleadFactory;
auto* wrc_fctr = new WorkerFactory;

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

void showDepInfo(IUnit* inCompany) {
    std::cout << "Detailed departments information\n";
    if (inCompany->childUnit.size() == 0) {
        std::cout << "There aren't any department in company\n";
    } else {
        for (unsigned int i = 0; i < inCompany->childUnit.size(); i++) {
            std::stringstream mngr;
            mngr << inCompany->childUnit[i]->manager->name << " (personal ID: " << inCompany->childUnit[i]->manager->id << ")";
            std::cout << std::setw(28) << std::left << inCompany->childUnit[i]->name << std::setw(32) << std::left
                      << mngr.str() << "workers: " << inCompany->childUnit[i]->workers.size() << std::endl;
            if (inCompany->childUnit[i]->workers.size() == 0) std::cout << "There aren't any workers in department\n";
            else {
                std::cout << "Department workers:\n";
                for (unsigned int j = 0; j < inCompany->childUnit[i]->workers.size(); j++) {
                    std::stringstream wrkr;
                    wrkr << inCompany->childUnit[i]->workers[j]->name << " (personal ID: " << inCompany->childUnit[i]->workers[j]->id << ")";
                    std::cout << std::setw(28) << std::left << wrkr.str() << "task: \n";
                }
            }
        }
    }
}

void addWorker(IUnit* inDepartment) {
    IPerson* wrkr = wrc_fctr->createPerson(inDepartment);
    inDepartment->workers.push_back(wrkr);
}

void manageWorker(IUnit* inCompany) {
    unsigned int choice;
    if (inCompany->childUnit.size() == 0) 
        std::cout << "There aren't any departmenet for management\n";
    else {
        for (unsigned int i = 0; i < inCompany->childUnit.size(); i++) {
            std::cout << i+1 << ") " << inCompany->childUnit[i]->name << std::endl;
        }
    }
    std::cout << "Enter dep. number: ";
    std::cin >> choice;
    std::cin.ignore();
    addWorker(inCompany->childUnit[choice-1]);
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
        std::cout << "2) Show departments info\n";
        std::cout << "3) Manage workers\n";
    } else if (inItem == 3) {
        std::cout << "1) Add task\n";
        std::cout << "2) Show tasks\n";
    }
    std::cout << "0) Exit\n";
    std::cout << "\n\n\n=========================================\n";
    std::cout << "Choose menu item: ";
}

int action(int inItem, int inCommand, IUnit* inCompany) {
    if (inItem == 0) {
        if (inCommand == 1) inCompany->detailed();
        return inCommand;
    } else if (inItem == 2) {
        if (inCommand == 1)
            inCompany->childUnit.push_back(addDepartment(inCompany));
        else if (inCommand == 2) 
            showDepInfo(inCompany);
        else if (inCommand == 3) 
            manageWorker(inCompany);
        else
            inItem = 0;
    } else if (inItem == 3) {
        if (inCommand == 1) {
            std::cout << "Task management\n";
        } else if (inCommand == 1) {
            std::cout << "Task management\n";
        }
    } else if (inItem != 0 && inCommand != 0) {
        inItem = inCommand;
    } else {
        inItem = 0;
    }
    return inItem;
}

int main() {
    IUnit* company = nullptr;
    int cli, menuitem = 0;
    bool isExit = false;

    if (!company) {
        company = initialize();
    }

    do {
        displayinfo(company);
        displaynavigation(menuitem);
        std::cin >> cli;
        std::cin.ignore();
        if (menuitem == 0 && cli == EXIT)
            isExit = true;
        else
            menuitem = action(menuitem, cli, company);
    } while (!isExit);

    return 0;
}