#include <iostream>

int main() {
  std::cout << "Автограф разработчика!\n";
  std::string AuthorSign;
  std::cout << "Введите ваше имя: ";
  std::getline(std::cin, AuthorSign);
  int strLength = AuthorSign.length();
  for (int lcnt = 0; lcnt !=3; lcnt++){
    for (int scnt = 0; scnt< strLength+4; scnt++){
      if (lcnt != 0 && lcnt != 2) {
        if (scnt==0 || scnt == strLength+3) {
          std::cout <<"|";
        } else if (scnt == 2) {
          std::cout << AuthorSign;
          scnt += strLength-1;
        } else {
          std::cout << " ";
        }
      } else {
        if (scnt==0 || scnt == strLength+3) {
          std::cout << "|";
        } else {
          std::cout << "-";
        }
      }
    }
    std::cout << "\n";
  }
}