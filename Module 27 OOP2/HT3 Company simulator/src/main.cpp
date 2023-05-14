#include <iostream>
#include <string>
#include "company.h"
<<<<<<< HEAD

int main() {
    std::cout << "Company simulator!" << std::endl;
    Company* company;
    company = Company::create();

=======
#include "task.h"


int main() {
    std::cout << "Company simulator!" << std::endl;
    Company* company = Company::create();
    company->showCompanyInfo();
>>>>>>> 2da7575d4460d3807a544cbae1e658cc4d624352
    delete company;
    return 0;
}
