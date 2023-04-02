#include <iostream>
#include <string>
#include "company.h"

int main() {
    std::cout << "Company simulator!" << std::endl;
    Company* company;
    company = Company::create();

    delete company;
    return 0;
}
