#include <iostream>
#include <string>
#include "company.h"
#include "task.h"


int main() {
    std::cout << "Company simulator!" << std::endl;
    Company* company = Company::create();
    std::string command;
    do {
        std::cout << "CLI > ";
        std::cin >> command;
        if (command == "info") company->showCompanyInfo();
    } while (command != "exit");


    delete company;
    return 0;
}
