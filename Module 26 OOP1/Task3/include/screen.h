//
// Created by Artem on 23.02.2023.
//

#include <string>
#include "window.h"

#ifndef MOD26_OOP_HT3_SCREEN_H
#define MOD26_OOP_HT3_SCREEN_H

class screen {
    int height; //Specifies the vertical size of the screen in pixels
    int width;  //Specifies the horizontal size of the screen in pixels
    form* pWindow;  //Pointer to window
public:
    screen(int hsize, int wsize);
    ~screen();
    int getHeight();
    int getWidth();
    void execute(std::string &cmd);
    void display();
};

#endif //MOD26_OOP_HT3_SCREEN_H
