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
    AddressBook* addrinstance = nullptr;
    void showMenu();
    int getCmdIndex(std::string &cmd);
    void makeCall();
    void call(std::string &str);
//    std::string getPhone();
    void sendSMS();
    void addRecord();
    friend bool isCorrectPhone(const std::string &str);
public:
    Phone();
    ~Phone();
    void operate();
    bool execute(std::string &cmd);
};

#endif //CELLPHONE_PHONE_H
