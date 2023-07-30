#include <iostream>
#include "company.h"
#include "person.h"
//#include "task.h"

int main() {
    std::cout << "Company simulator!" << std::endl;
    auto* cmp_fctr = new CompanyFactory;
    auto* div_fctr = new DivisionFactory;
    auto* ceo_fctr = new CEOFactory;
    auto* tl_fctr = new TeamleadFactory;
    IUnit* cmp = cmp_fctr->createUnit();
    cmp->manager = ceo_fctr->createPerson(cmp);
    std::cout << "How many dep's  in company? ";
    int deps;
    std::cin >> deps;
    cmp->childUnit.resize(3);
    for (int i=0; i<deps; ++i) {
        cmp->childUnit[i] = div_fctr->createUnit(cmp);
        cmp->childUnit[i]->manager = tl_fctr->createPerson(cmp->childUnit[i]);
    }
    std::cout << cmp->name << std::endl;
    std::cout << cmp->manager->name << std::endl;
    std::cout << cmp->childUnit[0]->name << std::endl;
    return 0;
}
