#include <iostream>
#include "phone.h"

int main() {
    std::cout << "Cellphone simulator!" << std::endl;
    Phone* _phone = new Phone();
    _phone->operate();
    delete _phone;
    return 0;
}
