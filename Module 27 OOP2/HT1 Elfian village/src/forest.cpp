//
// Created by Artem on 15.03.2023.
//
#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include "forest.h"

//Конструктор эльфа
Elf::Elf() {
    std::cout << "Enter elf name: ";
    std::cin >> this->name;
}

std::string Elf::getName() {
    return this->name;
}

//Создание эльфа
Elf* Elf::create(House* inHouse) {
    Elf* p = new Elf();
    //Передаем указатель на созданный дом
    p->residence = inHouse;
    return p;
}

House *Elf::getHouse() {
    return this->residence;
}

House::House() {
    std::cout << "Elfian house created.\n";
    //Создаем эльфа для этого дома
    this->resident = Elf::create(this);
}

//Создаем дом
House* House::create(Branch* inBranch) {
    House* p = new House();
    p->branch = inBranch;
    return p;
}

Elf* House::getResident() {
    return this->resident;
}

void House::Info() {
    std::cout << "House settled by " << this->resident->getName() << std::endl; 
}

House::~House() {
    delete this->resident;
}

Branch* House::getBranch() {
    return this->branch;
}

Branch::Branch() {
    std::cout << "Branch created.\n";
};

Branch::~Branch() {
    //Если на ветке есть дом, то удалаем его
    if (this->child != nullptr) {
        for (int i=0; i < this->branchAmount; i++) {
            delete child[i];
        }
    }
    if (this->house != nullptr) delete this->house;
}

Branch* Branch::create() {
    Branch* p = new Branch();
    std::srand(std::time(nullptr));
    p->branchAmount = std::rand()%3+3;
    p->child = new Branch *[p->branchAmount];
    for (int i = 0; i < p->branchAmount; i++) {
        p->child[i] = Branch::create(p, BranchID::Big);
    }
    return p;
}

Branch* Branch::create(Branch* inBranch, BranchID inBranchID) {
    Branch* p = new Branch();
    p->parent = inBranch;
    p->branchtype = inBranchID;
    std::srand(std::time(nullptr));
    if (inBranchID == BranchID::Big) {
        p->branchAmount = std::rand()%3+3;
        p->child = new Branch *[p->branchAmount];
        p->house = House::create(p);
        for (int i = 0; i < p->branchAmount; i++) {
            p->child[i] = Branch::create(p, BranchID::Medium);
        }
    } else if (inBranchID == BranchID::Medium) {
        p->branchAmount = std::rand()%3+3;
        p->child = new Branch *[p->branchAmount];
        p->house = House::create(p);
        for (int i = 0; i < p->branchAmount; i++) {
            p->child[i] = Branch::create(p, BranchID::Small);
        }
    }
    return p;
}

void Branch::getSettler() {
    std::cout << "This branch settled by " << this->house->getResident()->getName() << std::endl;

}

void Branch::getInfo() {
    if (branchtype == BranchID::Trunc) {
        std::cout << "Tree have " << this->branchAmount << "big branches:\n";
        for (int i =0; i<this->branchAmount; i++) {
            this->child[i]->getInfo();
        }
        return;
    }
    if (branchtype == BranchID::Big) {
        std::cout << "This big branch have " << this->branchAmount << "medium branches\n";
        this->getSettler();
        for (int i =0; i<this->branchAmount; i++) {
            this->child[i]->getInfo();
        }
        return;
    }
    if (branchtype == BranchID::Medium) {
        std::cout << "This medium branch have " << this->branchAmount << "small branches\n";
        this->getSettler();
        for (int i =0; i<this->branchAmount; i++) {
            this->child[i]->getInfo();
        }
        return;
    }
    if (branchtype == BranchID::Small) {
        std::cout << "This is small branch\n";
        return;
    }
}
Elf* Branch::findResident(std::string inName) {
    Elf* p = nullptr;
    if (this->house != nullptr && this->house->getResident()->getName() == inName) {
        return this->house->getResident();
    }
    if (this->branchAmount != 0) {
        for (int i=0; i < branchAmount; i++) {
            p = this->child[i]->findResident(inName);
            if (p != nullptr) return p;
        }
    }
    return p;
}

void Branch::findElf() {
    std::string name;
    Elf* p = nullptr;
    std::cout << "Enter elf name to search: ";
    std::cin >> name;
    p = findResident(name);
    if (p != nullptr) {
        std::cout << "Elf called " << p->getName() << " live in tree\n";
        this->printNeighbours(p);
    } else {
        std::cout << "Elf not found";
    }
}

void Branch::printNeighbours(Elf* inElf) {
    Branch* p = inElf->getHouse()->getBranch();
    if (p->branchtype == BranchID::Medium) {
        p = p->parent;
    }
    std::cout << "Neigh0: " << p->getHouse()->getResident()->getName() << std::endl;
    for (int i = 0; i < p->branchAmount; i++) {
       std::cout << "Neigh" << i+1 << ": " << p->child[i]->getHouse()->getResident()->getName() << std::endl;
    }
}

House *Branch::getHouse() {
    return this->house;
}
