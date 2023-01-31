//
// Created by Artem on 21.01.2023.
//
#include "mod-ram.h"
#include <iostream>

ramSet::ramSet() {
    this->valCount = 0;
    for (int i = 0; i<8; i++)
        this->valArray[i] = 0 ;
}

int ramSet::size() {
    return valCount;
}

void ramSet::clear() {
    valCount = 0;
}

int ramSet::getValue(int idx) {
    return valArray[idx];
}

void ramSet::push_back(int val) {
    if (size() !=8) {
        valArray[size()] = val;
        valCount++;
    }
    else std::cout << "Not enough memory!!!\n";
}