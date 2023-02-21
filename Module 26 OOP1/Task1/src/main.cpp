#include <iostream>
#include <sstream>
#include "mplayer.h"

int main() {
    std::cout << "Media Player!" << std::endl;
    MPlayer* mplayer = new MPlayer();
    std::string command;
    do {
        std::cout << "cli>";
        std::getline(std::cin, command);
        if (command == "stop") mplayer->stop();
        else if (command == "pause") mplayer->pause();
        else if (command == "play") mplayer->play();
        else if (command == "next") mplayer->next();
        else if (command == "list") mplayer->showTrackList();
        else if (command == "add") mplayer->addtrack();
        else if (command.substr(0,4) == "play") {
            if (command.size()==4) mplayer->play();
            else {
                std::istringstream ss(command);
                int idx;
                ss >> command >> idx;
                mplayer->play(idx);
            }
        }
        else if (command.substr(0, 6) == "delete") {
            std::istringstream ss(command);
            int idx;
            ss >> command >> idx;
            mplayer->deleteTrack(idx);
        }
        else std::cout << "Unknown command" << std::endl;
    } while (command != "exit");
    delete mplayer;
    return 0;
}
