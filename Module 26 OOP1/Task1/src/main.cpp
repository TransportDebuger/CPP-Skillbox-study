#include <iostream>
#include "mplayer.h"

int main() {
    std::cout << "Media Player!" << std::endl;
    MPlayer* mplayer = new MPlayer();
    std::cout << "Tracks in list: " << mplayer->getListSize() << std::endl;
    mplayer->showTrackList();
    delete mplayer;
    return 0;
}
