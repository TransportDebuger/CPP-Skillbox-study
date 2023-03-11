#include <iostream>
#include <string>
#include "screen.h"

#define SCREEN_MAX_HEIGHT 80
#define SCREEN_MAX_WIDTH 50

int main() {
    std::cout << "Window management simulatuion!" << std::endl;
    screen* scr = new screen(SCREEN_MAX_HEIGHT, SCREEN_MAX_WIDTH);
    bool isOperate = true;
    while (isOperate) {
        std::string cmd;
        std::cout << "move X Y - set new position for left-top corner of the window\n";
        std::cout << "resize H W - set new size of window\n";
        std::cout << "display - draw screen\n";
        std::cout << "exit - for exit\n";
        std::cout << "CLI> ";
        std::getline(std::cin, cmd);
        if (cmd =="exit") isOperate = false;
        else if (cmd == "display") scr->display();
        else scr->execute(cmd);
    }
    delete scr;
    return 0;
}
