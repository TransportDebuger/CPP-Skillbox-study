//
// Created by Artem on 13.02.2023.
//

#include "track.h"
#include <vector>

#ifndef OOP_HT1_MPLAYER_H
#define OOP_HT1_MPLAYER_H

class MPlayer {
    std::vector<Track *> trackList;
public:
    int getListSize();
    void showTrackList();
};

#endif //OOP_HT1_MPLAYER_H
