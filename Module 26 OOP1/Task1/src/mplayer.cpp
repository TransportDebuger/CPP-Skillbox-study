//
// Created by Artem on 13.02.2023.
//

#include <iostream>
#include "mplayer.h"

int MPlayer::getListSize() {
    return trackList.size();
}

void MPlayer::showTrackList() {
    if (!getListSize()) {
        std::cout << "There are not any tracks in list. Add track for listening" << std::endl;
        return;
    }
    std::cout << "ID   Track name           Created        Length\n";
    for (int i=0; i<getListSize(); i++) {
        std::cout << i << "   " << trackList[i]->getName() << "   " << trackList[i]->getDateCreated().tm_mday << "." <<
        trackList[i]->getDateCreated().tm_mon << "." << trackList[i]->getDateCreated().tm_year << "   " << trackList[i]->getLength() << "sec.\n";
    }
}