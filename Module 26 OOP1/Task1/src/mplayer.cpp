//
// Created by Artem on 13.02.2023.
//

#include <iostream>
#include "mplayer.h"
#include "track.h"

unsigned int MPlayer::getListSize() {
    return trackList.size();
}

pState MPlayer::getPlaybackState() {
    return pstate;
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

void MPlayer::stop() {
    if (pstate == pState::STOPPED) return;
    pstate = pState::STOPPED;
    std::cout << "Playback stopped" << std::endl;
}

void MPlayer::pause() {
    if (curtrack == -1) return;
    if (pstate == pState::STOPPED) return;
    if (pstate == pState::PAUSED) {
        pstate = pState::PLAYBACK;
        std::cout << "Playback resumed" << std::endl;
        return;
    }
    pstate = pState::PAUSED;
    std::cout << "Playback paused" << std::endl;
}

void MPlayer::play() {
    if (pstate != pState::PLAYBACK and curtrack != -1) pstate = pState::PLAYBACK;
}

void MPlayer::play(int trackidx) {
    curtrack = trackidx;
    if (pstate != pState::PLAYBACK) pstate = pState::PLAYBACK;
}

void MPlayer::next() {
    if (curtrack != trackList.size()-1) {
        curtrack++;
        if (pstate != pState::PLAYBACK) pstate = pState::PLAYBACK;
        std::cout << "Now played: " << trackList[curtrack]->getName() << std::endl;
    }
}

void MPlayer::addtrack(std::string tname, std::string dateCr, unsigned int tlength) {

}