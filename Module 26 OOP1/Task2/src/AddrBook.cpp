//
// Created by Artem on 28.02.2023.
//
#include <iostream>
#include "AddrBook.h"

AddressBook::AddressBook() {
    std::cout << "Address book initialize\n";
};

AddressBook* AddressBook::instance = nullptr;

AddressBook* AddressBook::getInstance() {
    if (!instance) {
        instance = new AddressBook();
    }
    return instance;
}

bool AddressBook::addRecord(const std::string phNum, const std::string phOwn) {
    return false;
}

bool findNumber(const std::string phNum, std::map<std::string, std::string>::iterator &it) {
    return false;
}
