//
// Created by Artem on 15.03.2023.
//
#pragma once

#include <string>

#ifndef MOD27_1_FOREST_H
#define MOD27_1_FOREST_H

enum class BranchID {Trunc, Big, Medium, Small};

class House; //Опережающее объявление класса

class Elf {
    std::string name; //Имя эльфа
    House* residence; //Дом в котором он живет
    Elf();
public:
    std::string getName();
    House* getHouse();
    static Elf* create(House* inHouse);
};

class Branch;

class House {
    Elf* resident;  //Эльф, проживающий в этом доме
    Branch* branch; //Ветка на которой расположен дом
    House();
public:
    void Info(); 
    Elf* getResident();
    Branch* getBranch();
    static House* create(Branch* inBranch);
    ~House(); 
};

class Branch {
    BranchID branchtype = BranchID::Trunc;
    Branch* parent = nullptr; //Ветка-родитель
    Branch** child = nullptr; //Массив веток потомков
    House* house = nullptr;   //Размещенный дом для эльфа
    int branchAmount = 0;
    Branch();
public:
    ~Branch();
    static Branch* create(); //Создает дерево
    static Branch* create(Branch* inBranch, BranchID inBranchID); //Создает дочерние ветки
    void findElf();
    House* getHouse();
    Elf* findResident(std::string inName);
    void printNeighbours(Elf* inElf);
    void getInfo();
    void getSettler();
};

#endif //MOD27_1_FOREST_H