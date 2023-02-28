//
// Created by Artem on 01.03.2023.
//

#include <string>
#include "AddrBook.h"

#ifndef CELLPHONE_PHONE_H
#define CELLPHONE_PHONE_H
enum class phoneCmd {
    CALL=0,
    ADD,
    SMS,
    EXIT
};

class Phone {
    AddressBook* addrinstance = 0;
    void showMenu();
    int getCmdIndex(std::string &cmd);
    void makeCall();
    void sendSMS();
    void addRecord();
public:
    Phone();
    ~Phone();
    void operate();
    bool execute(std::string &cmd);
};

#endif //CELLPHONE_PHONE_H
