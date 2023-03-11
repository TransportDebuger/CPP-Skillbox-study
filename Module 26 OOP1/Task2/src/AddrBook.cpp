//
// Created by Artem on 28.02.2023.
//
#include <iostream>
#include <map>
#include "AddrBook.h"

AddressBook::AddressBook() {
    std::cout << "Address book initialized\n";
}

AddressBook* AddressBook::instance = nullptr;

AddressBook* AddressBook::getInstance() {
    if (!instance) {
        instance = new AddressBook();
    }
    return instance;
}

bool AddressBook::addRecord(const std::string phNum, const std::string phOwn) {
    itPhone = phoneIndex.find(phNum);
    itOwner = ownerIndex.find(phOwn);
    phoneRecord newRecord = {phNum, phOwn};
    if (itPhone == phoneIndex.end()) {
        //Add phone number to addressbook
        records.push_back(newRecord);
        std::cout << "New record added\n";
        int recIdx = records.size()-1;
        phoneIndex.insert(make_pair(phNum, recIdx));
        std::cout << "New value added to phone index\n";
        if (itOwner == ownerIndex.end()) {
            std::pair<std::string, std::vector<int>> ownIdx;
            ownIdx.first = phOwn;
            ownIdx.second.push_back(recIdx);
            ownerIndex.insert(ownIdx);
            std::cout << "New value added to owner index\n";
        } else {
            itOwner->second.push_back(recIdx);
            std::cout << "Owner index updated\n";
        }
    } else {
        //Update phone record for phone
        int recIdx = itPhone->second;
        std::string prvOwn = records[recIdx].owner;
        records[recIdx].owner = phOwn;
        std::cout << "Address book record updated\n";
        if (itOwner == ownerIndex.end()) {
            std::pair<std::string, std::vector<int>> ownIdx;
            ownIdx.first = phOwn;
            ownIdx.second.push_back(recIdx);
            ownerIndex.insert(ownIdx);
            std::cout << "New value added to owner index\n";
        } else {
            itOwner->second.push_back(recIdx);
            std::cout << "Owner index updated\n";
        }
        itOwner = ownerIndex.find(prvOwn);
        for (int i = 0; i < itOwner->second.size(); i++) {
            if (itOwner->second[i] == recIdx) {
                itOwner->second.erase(itOwner->second.begin() + i);
                break;
            }
        }
        if (itOwner->second.empty()) ownerIndex.erase(itOwner);
    }
    return false;
}

void AddressBook::findName(std::string &str) {
    itPhone = phoneIndex.find(str);
    if (itPhone != phoneIndex.end()) {
        int idx = itPhone->second;
        if (itPhone != phoneIndex.end()) str = records[idx].owner + " (" + records[idx].phone + ")";
    }
}

bool AddressBook::findNumber(std::string &str) {
    itOwner = ownerIndex.find(str);
    if (itOwner == ownerIndex.end()) {
        std::cout << "Can't find phone number for " << str << std::endl;
        return false;
    }
    int idx = itOwner->second[0];
    str = records[idx].owner + " (" + records[idx].phone + ")";
    return true;
}

