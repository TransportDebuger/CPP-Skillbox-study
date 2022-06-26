#include <iostream>

int main() {
  int year;

  std::cout << "Введите год? ";
  std::cin >> year;
  if (year % 4 == 0){
    if (year % 100 == 0 && year % 400 != 0)
    {
      std::cout << "Это не високосный год!\n";
    } else
    {
      std::cout << "Это високосный год!\n";
    }
  } else {
      std::cout << "Это не високосный год!\n";
  }
}