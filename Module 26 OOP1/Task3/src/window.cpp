//
// Created by Artem on 22.02.2023.
//

#include <iostream>
#include "window.h"

#define DEFAULT_HEIGHT 10
#define DEFAULT_WIDTH 10
#define DEFAULT_TOP 10
#define DEFAULT_LEFT 10

form::form() {
    this->height = DEFAULT_HEIGHT;
    this->width = DEFAULT_WIDTH;
    this->left = DEFAULT_LEFT;
    this->top = DEFAULT_TOP;
    std::cout << "New window created t:" << top << " l:" << left << "h:" << height << " w:" << width << std::endl;
}

void form::resizeForm(const int hsize, const int wsize) {
    height = hsize;
    width = wsize;
    std::cout << "Window have new measures h:" << height << " w:" << width << ")\n";
}

void form::moveForm(const int tpoint, const int lpoint) {
    top = tpoint;
    left = lpoint;
    std::cout << "Window moved to position t:" << top << " l:" << left << std::endl;
}

int form::getTop() {
    return top;
}

int form::getLeft() {
    return left;
}

int form::getHeight() {
    return height;
}

int form::getWidth() {
    return width;
}