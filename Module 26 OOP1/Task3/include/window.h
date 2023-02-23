//
// Created by Artem on 22.02.2023.
//

#ifndef MOD26_OOP_HT3_WINDOW_H
#define MOD26_OOP_HT3_WINDOW_H


class window {
    int height;  //Specifies the vertical size of the window in pixels
    int width;       //Specifies the horizontal size of the window in pixels
    int left;        //Specifies the Y coordinate of the upper-left corner
    int top;         //Specifies the X coordinate of the upper-left corner

public:
    window(int hsize = 50, int wsize = 80, int lpoint = 10, int tpoint = 10);
};

#endif //MOD26_OOP_HT3_WINDOW_H
