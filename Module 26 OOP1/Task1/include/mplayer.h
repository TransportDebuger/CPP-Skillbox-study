//
// Created by Artem on 13.02.2023.
//

#include "track.h"
#include <vector>
#include <string>

#ifndef OOP_HT1_MPLAYER_H
#define OOP_HT1_MPLAYER_H

enum class pState {
    PLAYBACK,
    PAUSED,
    STOPPED
};

class MPlayer {
    std::vector<Track *> trackList;
    int curtrack = -1;
    pState pstate = pState::STOPPED;

public:
    ~MPlayer();
    unsigned int getListSize();
    void showTrackList();
    void stop();
    void pause();
    void play();
    void play(int trackidx);
    void next();
    void addtrack();
    void deleteTrack(int trackIndex);
};

#endif //OOP_HT1_MPLAYER_H
