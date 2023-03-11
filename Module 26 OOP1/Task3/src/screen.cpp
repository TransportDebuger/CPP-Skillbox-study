//
// Created by Artem on 23.02.2023.
//

#include <sstream>
#include <iostream>
#include "screen.h"
#include "window.h"

screen::screen(int hsize, int wsize) {
    this->height = hsize;
    this->width = wsize;
    pWindow = new form();
    display();
}

screen::~screen() {
    delete pWindow;
}

int screen::getHeight() {
    return height;
}

int screen::getWidth() {
    return width;
}

void screen::execute(std::string &cmd) {
    std::stringstream ss;
    ss.str(cmd);
    int first, second;
    ss >> cmd >> first >> second;
    if (cmd == "move") {
        if (first < 0) first = 0;
        else if (first > getHeight()) first = getHeight()-1;
        if (second < 0) second = 0;
        else if (second > getWidth()) second = getWidth()-1;
        pWindow->moveForm(first, second);
    } else if (cmd == "resize") {
        if (first < 1) first = 1;
        if (second < 1) second = 1;
        pWindow->resizeForm(first, second);
    }
}

void screen::display() {
    for (int t = 0; t<getHeight(); t++) {
        for (int l = 0; l<getWidth(); l++) {
            if (t >= pWindow->getTop()
                && t < pWindow->getTop()+pWindow->getHeight()
                && l >= pWindow->getLeft()
                && l < pWindow->getLeft()+pWindow->getWidth()) std::cout << "1";
            else std::cout << "0";
        }
        std::cout << std::endl;
    }
}

