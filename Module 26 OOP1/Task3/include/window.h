//
// Created by Artem on 22.02.2023.
//


#ifndef MOD26_OOP_HT3_WINDOW_H
#define MOD26_OOP_HT3_WINDOW_H

class form {
    int height;      //Specifies the vertical size of the window in pixels
    int width;       //Specifies the horizontal size of the window in pixels
    int left;        //Specifies the Y coordinate of the upper-left corner
    int top;         //Specifies the X coordinate of the upper-left corner

public:
    form();
    void resizeForm(int hsize, int wsize);  //Window resizing
    void moveForm(int tpoint, int lpoint); //New position for upper-left corner of the window
    int getTop();
    int getLeft();
    int getHeight();
    int getWidth();
};

#endif //MOD26_OOP_HT3_WINDOW_H
