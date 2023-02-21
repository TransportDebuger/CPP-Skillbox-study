//
// Created by Artem on 13.02.2023.
//

#include <iostream>
#include <ctime>
#include <sstream>
#include <iomanip>
#include "mplayer.h"
#include "track.h"

MPlayer::~MPlayer() {
    if (trackList.size()) {
        for (int i=trackList.size()-1; i<0; i--) {
            Track* track = trackList[i];
            delete track;
            trackList.pop_back();
        }
    }
}

unsigned int MPlayer::getListSize() {
    return trackList.size();
}

void MPlayer::showTrackList() {
    if (!getListSize()) {
        std::cout << "There are not any tracks in list. Add track for listening" << std::endl;
        return;
    }
    std::cout << "Tracks in list: " << getListSize() << std::endl;
    if (curtrack != -1) {
        std::cout << "Now played: " << trackList[curtrack]->getName() << " ";
        if (pstate == pState::STOPPED) std::cout << "(STOPPED)";
        else if (pstate == pState::PAUSED) std::cout << "(PAUSED)";
    }
    std::cout << std::endl;
    std::cout << "ID   Track name           Created        Length" << std::endl;
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
    if (pstate != pState::PLAYBACK && curtrack != -1) pstate = pState::PLAYBACK;
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

void MPlayer::addtrack() {
    struct std::tm dc;
    std::cout << "Track name: ";
    std::string tname;
    std::getline(std::cin, tname);
    std::cout << "Track length (sec.): ";
    int tlength;
    std::cin >> tlength;
    std::cout << "Date of creation: ";
    std::string dateCr;
    std::cin >> dateCr;
    std::istringstream ss(dateCr);
    ss >> std::get_time(&dc, "%d.%m.%Y");
    Track* track = new Track(tname, dc, tlength);
    trackList.push_back(track);
}

void MPlayer::deleteTrack(int trackIndex) {
    if (trackIndex<0 || trackIndex>=trackList.size()) {
        std::cout << "Wrong track index." << std::endl;
        return;
    }
    Track* track = trackList[trackIndex];
    delete track;
    trackList.erase(trackList.begin()+trackIndex);
}