#include <iostream>


bool findLine(std::string line, char symbol) {
    //Find Line in a raw
    std::string tmplLine = {symbol, symbol, symbol};
    for (int i=0; i<=6; i += 3) {
        if (line.substr(i, 3) == tmplLine) {
            return true;
        }
    }
    //find Line in a col
    for (int i=0; i<3; i++) {
        std::string setLine = {line[i], line[i+3], line[i+6]};
        if (setLine == tmplLine) {
            return true;
        }
    }
    //find line in diagonals
    {
        std::string setLine = {line[0], line[4], line[8]};
        if (setLine == tmplLine) {
            return true;
        }
        setLine = {line[2], line[4], line[6]};
        if (setLine == tmplLine) {
            return true;
        }
    }
    return false;
}

int countSymbols(std::string line, char symbol) {
    int result = 0;
    for (int i = 0; i< line.length(); i++) {
        if (line[i] == symbol) {result++;}
    }
    return result;
}

bool checkLine(std::string line){
    if (line.length() != 3) {
        return false;
    }
    for (int i = 0; i < line.length(); i++) {
        if (line[i] != '.' && line[i] != 'X' && line[i] != 'O') {
            return false;
        }
    }
    return true;
}

int analyseGame(std::string line1, std::string line2, std::string line3) {
    if (!checkLine(line1) || !checkLine(line2) || !checkLine(line3)) {
        return -1;
    }
    int Crosses = countSymbols(line1+line2+line3, 'X');
    int Noughts = countSymbols(line1+line2+line3, 'O');
    if (Noughts  > Crosses || Crosses - Noughts > 1) {return -1;}
    std::string fullLine = line1+line2+line3;
    if (findLine(fullLine, 'X') && findLine(fullLine, 'O')) {
        return -1;
    } else if (findLine(fullLine, 'X') && !findLine(fullLine, 'O') && Noughts < Crosses) {
        return 1;
    } else if (findLine(fullLine, 'O') && !findLine(fullLine, 'X')) {
        return 2;
    }
    return 0;
}

int main() {
    std::cout << "Noughts and Crosses analysis!" << std::endl;
    std::string lineA, lineB, lineC;
    //input first line
    std::cout << "Input line A: ";
    std::cin >> lineA;
    //input second line
    std::cout << "Input line B: ";
    std::cin >> lineB;
    //input third line
    std::cout << "Input line C: ";
    std::cin >> lineC;
    //start game analysis
    int result = analyseGame(lineA, lineB, lineC);
    if (result == 0) {
        std::cout << "Nobody!" << std::endl;
    } else if (result == 1) {
        std::cout << "Petya won!" << std::endl;
    } else if (result == 2) {
        std::cout << "Vasia won!" << std::endl;
    } else {
        std::cout << "Incorrect!" << std::endl;
    }
    return 0;
}
