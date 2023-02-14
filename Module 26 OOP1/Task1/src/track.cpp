//
// Created by Artem on 13.02.2023.
//
#include "track.h"

Track::Track(std::string tName, std::tm tDateCreated, int tLength) {
    setName(tName);
    setDateCreated(tDateCreated);
    setLength(tLength);
}

int Track::getLength() {
    return length;
}

std::string Track::getName() {
    return name;
}

std::tm Track::getDateCreated() {
    return dateCreated;
}

void Track::setLength(int tLength) {
    length = tLength;
}

void Track::setName(std::string tName) {
    if (tName.size()<=30) {
        name = tName;
    } else {
        name = tName.substr(0, 29);
    }
}

void Track::setDateCreated(std::tm tDateCreated) {
    dateCreated = tDateCreated;
}