#include <iostream>

int main() {
  std::cout << "Давайте запрограммируем робота!\n";
  std::cout << "Введите программу используя только 0 и 1.\n";
  int code;
  std::cin >> code;
  std::cout << "Загрузка ";
  while (code != 0) {
    if (code % 10 !=0 && code % 10 != 1) {
      std::cout << "Инструкция не корректна.\n";
      break;
    } else {
      code /= 10;
      std::cout << "=";
    }
  }
}