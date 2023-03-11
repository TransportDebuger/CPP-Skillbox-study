//
// Created by Artem on 28.02.2023.
//

#include <string>
#include <map>
#include <string>
#include <vector>


#ifndef CELLPHONE_ADDRBOOK_H
#define CELLPHONE_ADDRBOOK_H

struct phoneRecord {
    std::string phone;
    std::string owner;
};

class AddressBook {
private:
    static AddressBook* instance;
    std::vector<phoneRecord> records;
    std::map<std::string, int> phoneIndex;
    std::map<std::string, int>::iterator itPhone;
    std::map<std::string, std::vector<int>> ownerIndex;
    std::map<std::string, std::vector<int>>::iterator itOwner;
    AddressBook();
public:
    static AddressBook* getInstance();
    bool addRecord(const std::string phNum, const std::string phOwn);
    bool findNumber(std::string &str);
    void findName(std::string &str);
};

#endif //CELLPHONE_ADDRBOOK_H
