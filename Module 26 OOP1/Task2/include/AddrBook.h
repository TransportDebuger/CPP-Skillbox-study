//
// Created by Artem on 28.02.2023.
//

#include <string>
#include <map>
#include <string>
#include <vector>


#ifndef CELLPHONE_ADDRBOOK_H
#define CELLPHONE_ADDRBOOK_H

class AddressBook {
private:
    static AddressBook* instance;
    std::map<std::string, std::string> phoneIndex;
    std::map<std::string, std::string>::iterator itPhone;
    AddressBook();
public:
    static AddressBook* getInstance();
    bool addRecord(const std::string phNum, const std::string phOwn);
    bool findNumber(const std::string phNum, std::map<std::string, std::string>::iterator &it);
};

#endif //CELLPHONE_ADDRBOOK_H
