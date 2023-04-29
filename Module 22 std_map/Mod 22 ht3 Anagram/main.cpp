#include <iostream>
#include <string>
#include <map>

using namespace std;

bool checkAnagram(string _cWord, string _tWord) {

    if (_cWord.length() != _tWord.length()) {
        return false;
    }
    map<char, int> spell;
    for (short int cPos=0; cPos<_cWord.length(); cPos++) {
        map<char, int>::iterator it;
        it = spell.find(_cWord[cPos]);
        if (it != spell.end()) {
            it->second += 1;
        } else {
            spell.insert(make_pair(_cWord[cPos], 1));
        }
    }

    for (short int cPos=0; cPos<_tWord.length(); cPos++) {
        map<char, int>::iterator it;
        it = spell.find(_tWord[cPos]);
        if (it == spell.end()) {
            return false;
        } else {
            if (it->second == 0) {
                return false;
            } else {
                it->second -= 1;
            }
        }
    }

    return true;
}

int main() {
    string originalWord, testedWord;
    cout << "Enter original and tested words (separator <space>): ";
    cin >> originalWord >> testedWord;
    if (checkAnagram(originalWord, testedWord)) {
        cout << "Word \"" << testedWord << "\" is the anagram of word \"" << originalWord << "\"\n";
    } else {
        cout << "Word \"" << testedWord << "\" is not the anagram of word \"" << originalWord << "\"\n";
    }
    std::cout << "Hello, World!" << std::endl;
    return 0;
}