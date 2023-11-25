//
// Created by Artem on 30.07.2023.
//
#include "routines.h"

#include <iostream>
#include <string>

std::string setline()
{
    std::string line;
    std::getline(std::cin, line);
    return line;
}