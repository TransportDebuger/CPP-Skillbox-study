//
// Created by Artem on 22.01.2023.
//

#include "mod-cmp.h"
#include "mod-ram.h"
#include <iostream>
#include <fstream>

Computer::Computer() {
    ramSet* rs = new ramSet();
    this->ram = rs;
    this->ram->clear();
}

Computer::~Computer() {
    delete ram;
}

void Computer::gpuDisplay() {
    if (ram->size()) {
        std::cout << "Memory stored values:\n";
        for (int i=0;i<ram->size();i++) std::cout << "Value " << i << ": " << read(i) << std::endl;
    } else std::cout << "Memory empty\n";
}

void Computer::write() {
    int val;
    std::cout << "Enter value: ";
    std::cin >> val;
    ram->push_back(val);
}

int Computer::read(const int idx) {
    return ram->getValue(idx);
}

void Computer::save() {
    std::ofstream diskFile;
    diskFile.open(".//data.bin", std::ios::binary);
    if (diskFile) {
        for (int i=0; i<ram->size(); i++) {
            int value = ram->getValue(i);
            diskFile.write((char*)&value, sizeof(int));
        }
        std::cout << "Data successfully saved.\n";
    }
    diskFile.close();
}

void Computer::load() {
    ram->clear();
    std::ifstream diskFile;
    diskFile.open(".//data.bin", std::ios::binary);
    if (diskFile) {
        while (!(diskFile.eof())) {
            int value;
            diskFile.read((char*)&value, sizeof(int));
            ram->push_back(value);
        }
    } else {
        std::cout << "Hard disk drive not found!\n";
    }
    diskFile.close();
}

void Computer::sum() {
    if (!(ram->size())) {
        std::cout << "There aren't any numbers in memory!\n";
    } else {
        int sum = 0;
        for (int i=0; i<=ram->size(); i++) {
            sum += read(i);
        }
        std::cout << "Total: " << sum << std::endl;
    }
}
