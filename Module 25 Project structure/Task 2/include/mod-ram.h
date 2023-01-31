//
// Created by Artem on 21.01.2023.
//

#ifndef COMPUTER_SIMULATOR_MOD_RAM_H
#define COMPUTER_SIMULATOR_MOD_RAM_H

struct ramSet {
public:
    ramSet();
    int size();
    void clear();
    void push_back(int val);
    int getValue(int idx);
private:
    int valArray[8];
    int valCount;
};

#endif //COMPUTER_SIMULATOR_MOD_RAM_H
