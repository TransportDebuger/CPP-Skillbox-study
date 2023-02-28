//
// Created by Artem on 01.03.2023.
//

#include <iostream>
#include <string>
#include "phone.h"

Phone::Phone() {
    std::cout << "Cell phone is ready to use.\n";
}

Phone::~Phone() {
    std::cout << "Phone shutting down!\nBye! Bye!\n";
}

void Phone::operate() {
    std::string command;
    do {
        showMenu();
        std::cout << "CLI> ";
        std::cin >> command;
    } while (!(execute(command)));
}

bool Phone::execute(std::string &cmd) {
    int action = this->getCmdIndex(cmd);
    if (action == static_cast<int>(phoneCmd::EXIT)) return true;
    if (action == -1) {
        std::cout << "Unknown instruction\n";
    }
    return false;
}

int Phone::getCmdIndex(std::string &cmd) {
    std::string phoneMenu[] = {"call", "add", "sms", "exit"};
    for (int i=0; i<=4; i++) {
        if (phoneMenu[i] == cmd) return i;
    }
    return -1;
}

void Phone::showMenu () {
    std::cout << "Main Menu: \n";
    std::cout << "    call - make call to ...\n";
    std::cout << "    add  - add record to address book\n";
    std::cout << "    sms  - send sms to ...\n";
    std::cout << "    exit - for make\n";
}