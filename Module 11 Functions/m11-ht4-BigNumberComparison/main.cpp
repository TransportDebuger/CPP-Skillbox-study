#include <iostream>

std::string delUnvaluedZeros(std::string str) {
    std::string result;
    bool isNotLeading = false;
    for (int i=0; i < str.length(); i++) {
      if (!isNotLeading) {
          if (str[i] == '-') {
              result += '-';
          } else if (str[i] == '.' || (str[i] >= '1' && str[i]<='9')) {
              result += str.substr(i);
              break;
          }
      } else {
          result += str[i];
      }
    }
    int dotPos = result.find('.');
    if (dotPos >= 0) {
        while (result[result.length() - 1] == '0') {
            result = result.substr(0, result.length()-1);
        }
    }
    if (result == "-" || result == "." || result == "-."  || result.empty()) {
        result ='0';
    }
    if (result[0] != '-') {result = '/' + result;}
    return result;
}

int compareNumbers(std::string BN1, std::string BN2){
    BN1 = delUnvaluedZeros(BN1);
    BN2 = delUnvaluedZeros(BN2);
    int dotPos1 = BN1.find('.');
    int dotPos2 = BN2.find('.');
    int fullPart1 = (dotPos1 >= 0) ? dotPos1 : BN1.length();
    int fullPart2 = (dotPos2 >= 0) ? dotPos2 : BN2.length();
    while (fullPart1 != fullPart2) {
        if (fullPart1 < fullPart2) {
            BN1 = BN1.substr(0, 1) +'0' + BN1.substr(1);
            fullPart1++;
        } else {
            BN2 = BN2.substr(0, 1) + '0' + BN2.substr(1);
            fullPart2++;
        }
    };
    dotPos1 = BN1.find('.');
    dotPos2 = BN2.find('.');
    if (dotPos1 < 0) {BN1 += '.';}
    if (dotPos2 < 0) {BN2 += '.';}
    dotPos1 = BN1.find('.');
    int fractPart1 = BN1.length() - dotPos1;
    int fractPart2 = BN2.length() - dotPos1;
    while (fractPart1 != fractPart2) {
        if (fractPart1 < fractPart2) {
            BN1 += '0';
            fractPart1++;
        } else {
            BN2 += '0';
            fractPart2++;
        }
    }
    std::cout << BN1 << std::endl;
    std::cout << BN2 << std::endl;
    for (int i = 0; i < BN1.length(); i++) {
        if (BN1[0] == '-' && BN2[0] == '-') {
            if ((int)BN1[i] > (int)BN2[i]) {
                return 2;
            } else if ((int)BN1[i] < (int)BN2[i]) {
                return 1;
            }
        } else {
            if ((int)BN1[i] > (int)BN2[i]) {
                return 1;
            } else if ((int)BN1[i] < (int)BN2[i])  {
                return 2;
            }
        }
    }
    return 0;
}

bool checkNumber(std::string realNumber) {
    bool dotPresent = false;
    for (int count = 0; count < realNumber.length() ; count++) {
        if ((realNumber[count] >= '0' && realNumber[count] <= '9') ||
            realNumber[count] == '.' || realNumber[count] == '-') {
            if (realNumber[count] == '.' && dotPresent) {
                return false;
            } else if (realNumber[count] == '.') {
                dotPresent = true;
                continue;
            }
            if (realNumber[count] == '-' && count != 0) {
                return false;
            }
        } else {
            return false;
        }
    }
    return true;
}

int main() {
    std::cout << "Big numbers comparison!" << std::endl;
    std::string bigNumber1, bigNumber2;
    std::cout << "Input first real number:" << std::endl;
    std::cin >> bigNumber1;
    while (!checkNumber(bigNumber1)) {
        std::cout << "Wrong input! Try again." << std::endl;
        std::cout << "Input first real number:" << std::endl;
        std::cin >> bigNumber1;
    }
    std::cout << "Input second real number:" << std::endl;
    std::cin >> bigNumber2;
    while (!checkNumber(bigNumber2)) {
        std::cout << "Wrong input! Try again." << std::endl;
        std::cout << "Input second real number:" << std::endl;
        std::cin >> bigNumber2;
    }
    int compResult = compareNumbers(bigNumber1, bigNumber2);
    if (compResult == 1) {
        std::cout << "First number is bigger!" << std::endl;
    } else if (compResult == 2) {
        std::cout << "Second number is bigger!" << std::endl;
    } else {
        std::cout << "Numbers are equal." << std::endl;
    }
    return 0;
}
