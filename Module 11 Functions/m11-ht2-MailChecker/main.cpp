#include <iostream>

bool isCorrectUsername(std::string uname) {
    if (uname.length() > 64) {return false;}
    for (int i = 0; i<uname.length(); i++) {
        if (uname[i] == '.' || uname[i] == '-' || uname[i] == '!' || uname[i] == '#' || uname[i] == '$' ||
            uname[i] == '%' || uname[i] == '&' || uname[i] == '\'' || uname[i] == '*' || uname[i] == '+' ||
            uname[i] == '-' || uname[i] == '/' || uname[i] == '=' || uname[i] == '?' || uname[i] == '^' ||
            uname[i] == '_' || uname[i] == '`' || uname[i] == '{' || uname[i] == '|' || uname[i] == '}' ||
            uname[i] == '~' || (uname[i] >= 'A' && uname[i] <= 'Z') || (uname[i] >= 'a' && uname[i] <= 'z') ||
            (uname[i] >='0' && uname[i] <= '9')) {
            if (uname[i] == '.' && (i == 0 || i == uname.length() - 1
                || (i < uname.length() - 1 && uname[i + 1] == '.'))) { return false; }
        } else {
            return false;
        }
    }
    return true;
}

bool isCorrectDomainName(std::string dn) {
    if (dn.length() > 63) {return false;}
    for (int i = 0; i<dn.length(); i++) {
        if (dn[i] == '.' || dn[i] == '-' || (dn[i] >= 'A' && dn[i] <= 'Z') ||
            (dn[i] >= 'a' && dn[i] <= 'z') || (dn[i] >='0' && dn[i] <= '9')) {
            if (dn[i] == '.' && (i == 0 || i == dn.length() - 1 || (i < dn.length() - 1 && dn[i + 1] == '.'))) { return false; }
        } else {
            return false;
        }
    }
    return true;
}

int main() {
    std::cout << "E-mail checker!" << std::endl;
    std::string email, userName, domainName;
    std::cout << "Input e-mail here: ";
    std::cin >>email;

    int atSignPosition = -1;
    bool isMatched = false;

    for (int i = 0; i< email.length(); i++) {
        if (email[i] == '@')  {
            if (atSignPosition > -1 || i == 0 || i == email.length() - 1) {
                isMatched = false;
                break;
            } else if (atSignPosition == -1) {
                atSignPosition = i;
                isMatched = true;
            }
        }
    }

    if (isMatched) {
        isMatched = (isCorrectUsername(email.substr(0, atSignPosition)) &&
                isCorrectDomainName(email.substr(atSignPosition+1))) ? true : false;
    }

    std::cout << (isMatched ? "Yes!" : "No!") << std::endl;

    return 0;
}
