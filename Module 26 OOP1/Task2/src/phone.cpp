//
// Created by Artem on 01.03.2023.
//

#include <iostream>
#include <string>
#include "phone.h"
#include "AddrBook.h"

bool isCorrectPhone(const std::string &str) {
    int sCounter = 0;
    if (str[sCounter] != '+') return false;
    sCounter = 1;
    //if (str.size()!=11) return false;
    while (sCounter<str.size()) {
        if (!(str[sCounter]>='0' && str[sCounter]<='9')) return false;
        sCounter++;
    }
    return true;
}

Phone::Phone() {
    this->addrinstance = AddressBook::getInstance();
    std::cout << "Cell phone is ready to use.\n";
    std::cout << addrinstance << std::endl;
}

Phone::~Phone() {
    std::cout << "Phone shutting down!\nBye! Bye!\n";
    delete addrinstance;
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
    if (action == static_cast<int>(phoneCmd::CALL)) this->makeCall();
    else if (action == static_cast<int>(phoneCmd::ADD)) this->addRecord();
    else if (action == static_cast<int>(phoneCmd::SMS)) this->sendSMS();
    else std::cout << "Unknown instruction\n";
    return false;
}

int Phone::getCmdIndex(std::string &cmd) {
    std::string phoneMenu[] = {"call", "add", "sms", "exit"};
    for (int i=0; i<=4; i++) {
        if (phoneMenu[i] == cmd) return i;
    }
    return -1;
}

void Phone::makeCall() {
    std::string str;
    std::cout << "Enter number (with leading +7) or name for call: ";
    std::cin >> str;
    //Нужно устранить проблему с getline
    //std::getline(std::cin, str);
    if (isCorrectPhone(str)) {
        addrinstance->findName(str);
        call(str);
    } else std::cout << "Is not correct phone number\n";
}

void Phone::call(std::string &str) {
    std::cout << "Attempt to call to " << str << std::endl;
}

void Phone::sendSMS() {
    std::cout << "Enter number (with leading +7) or name to send SMS:";
    std::string str;
    std::cin >> str;
    //std::getline(std::cin, str);
    if (isCorrectPhone(str)) {
        addrinstance->findName(str);
        std::cout << "Send SMS to " << str << std::endl;
    } else std::cout << "Is not correct phone number\n";
    std::cout << "SMS\n";
}

void Phone::addRecord() {
    std::cout << "Enter record (number name) to add to address book:";
    std::string phone, owner;
    std::cin >> phone >> owner;
    addrinstance->addRecord(phone, owner);
    std::cout << "Record\n";
}

void Phone::showMenu () {
    std::cout << "Main Menu: \n";
    std::cout << "    call - make call to ...\n";
    std::cout << "    add  - add record to address book\n";
    std::cout << "    sms  - send sms to ...\n";
    std::cout << "    exit - for make\n";
}

