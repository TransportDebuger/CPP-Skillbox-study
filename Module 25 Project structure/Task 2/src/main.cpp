#include <iostream>
#include "mod-cmp.h"
#include "mod-cli.h"

int main() {
    std::cout << "Computer simulator!" << std::endl;
    Computer* comp =  new Computer();
    commands command;
    do {
        std::cout << "CLI > ";
        std::string sCmd;
        std::cin >> sCmd;
        command = cmdconvert(sCmd);
        Execute(command, comp);
    } while (command != commands::EXIT);
    delete comp;
    return 0;
}
