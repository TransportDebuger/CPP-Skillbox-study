#include <iostream>
#include <string>
#include <cmath>

bool checkOctet(std::string oct) {
    if (oct[oct.length()-1] != '.') {oct += '.';}
    if (oct == "." || (oct[0]== '0' && oct[1]!='.')) {return false;}
    int value = 0, power=0;
    for (int i = oct.length() - 1; i >= 0; i--) {
        if (oct[i] != '.') {
            if (oct[i]>='0' && oct[i]<='9') {
                value += ((int)oct[i] - 48) * (int)std::pow(10, power);
                power++;
            } else {
                return false;
            }
        }
    }
    if (value> 255) {
        return false;
    } else {
        return true;
    }
}

bool checkIP(std::string ip) {
    if (ip.length() < 7 || ip.length() > 15 || ip[0]=='.' || ip[ip.length()-1]=='.') {return false;}
    std::string octet;
    for (int i = 0; i < ip.length(); i++) {
            octet += ip[i];
            if (ip[i] == '.' || i == ip.length()-1) {
                if (!checkOctet(octet)) {return false;}
                octet.clear();
            }
    }
    return true;
}

int main() {
    std::cout << "IP validation!" << std::endl;
    std::string ipv4;
    std::cout << "Input IPv4 address for validation:" << std::endl;
    std::cin >> ipv4;

    std::cout << (checkIP(ipv4) ? "IP is valid!" : "IP is\'t valid!") << std::endl;

    return 0;
}
