#include <iostream>
#include <string>

char encrypt_caesar (char ch, int offset) {
    if (ch >= 'A' && ch<='Z') {
        if (ch + offset < 'A') {
            return 'Z' + 1 + (ch + offset - 'A');
        } else if (ch + offset > 'Z' ){
            return 'A' - 1 + (ch + offset - 'Z');
        } else {
            return ch + offset;
        }
    } else if (ch >= 'a' && ch<='z') {
        if (ch + offset < 'a') {
            return 'z' + 1 + (ch + offset - 'a');
        } else if (ch + offset > 'z' ){
            return 'a' - 1 + (ch + offset - 'z');
        } else {
            return ch + offset;
        }
    } else {return ch;}
}

char decrypt_caesar (char ch, int offset) {
    return encrypt_caesar(ch, -offset);
}

int main() {
    std::cout << "Caesar's cipher!\n";

    std::string textLine;
    int offset;
    std::cout << "Input text for encryption:\n";
    std::getline(std::cin, textLine);
    std::cout << "Input offset value (integer):\n";
    std::cin >> offset;
    if (std::abs(offset) >= 26) {offset %= 26;}
    //Encryption process
    for (int i = 0; textLine.length() > i; i++) {
        textLine[i] = encrypt_caesar(textLine[i], offset);
    }
    std::cout << "\nEncrypted text line:\n" << textLine << "\n";
    //Decryption process
    for (int i = 0; i < textLine.length(); i++) {
        //textLine[i] = encrypt_caesar(textLine[i], -offset);
        textLine[i] = decrypt_caesar(textLine[i], offset);
    }
    std::cout << "\nDecrypted text line:\n" << textLine << "\n";
}