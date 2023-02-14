//
// Created by Artem on 13.02.2023.
//
#include <string>
#include <ctime>

#ifndef OOP_HT1_TRACK_H
#define OOP_HT1_TRACK_H

class Track {
    std::string name;
    std::tm dateCreated;
    int length;
public:
    Track(std::string tName, std::tm tDateCreated, int tLength);
    int getLength();
    std::string getName();
    std::tm getDateCreated();
    void setLength(int tLength);
    void setName(std::string tName);
    void setDateCreated(std::tm tDateCreated);
};

#endif //OOP_HT1_TRACK_H
