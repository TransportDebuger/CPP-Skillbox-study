#include <iostream>

int main() {
  std::cout << "Колонтитул\n";
  int strLength;
  std::cout << "Введите длину колонтитула: ";
  std::cin >> strLength;
  if (strLength < 1) {
    std::cout << "Длина колонтитула не может быть меньше 1 символа.\n";
  } else {
    int exclSigns= 0;
    std::cout << "Введите число восклицательных знаков в колонтитуле: ";
    std::cin >> exclSigns;
    if (exclSigns < 0 || exclSigns > strLength) {
      std::cout << "Количество восклицательных знаков не может быть меньше 0 или больше длины строки.\n";
    } else {
      int startPos = strLength/2 - exclSigns/2;
      for (int scnt = 0; scnt < strLength; scnt++) {
         if (scnt >= startPos && scnt < startPos + exclSigns) {
           std::cout << "!";
         } else
         {
           std::cout << "~";
         }
      }
      std::cout <<"\n";
    }
  } 
}