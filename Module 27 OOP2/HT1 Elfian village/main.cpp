#include <iostream>
#include "forest.h"

int main() {
    std::cout << "Elven village!" << std::endl;
    //Соответственно создаем все деревья
    Branch* tree = Branch::create();
    tree->findElf();
    delete tree;
    return 0;
}
