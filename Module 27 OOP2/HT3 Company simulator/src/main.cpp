#include <iostream>
#include <string>
#include "company.h"
#include "task.h"


int main() {
    std::cout << "Company simulator!" << std::endl;
    Company* company = Company::create();
    company->showCompanyInfo();
    delete company;
    return 0;
}
