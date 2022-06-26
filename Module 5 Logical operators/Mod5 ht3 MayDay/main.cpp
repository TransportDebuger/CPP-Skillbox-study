#include <iostream>

int main() {
  int day; 
  std::cout << "Майские!\n";
  std::cout << "Введите число в мае: ";
  std::cin >> day;
  if (day % 7 == 6 || day % 7 == 0 || (day >= 1 && day <=5) || (day >=8 && day <= 10)) {
    std::cout << "Выходной!\n";
  } else
  {
    std::cout << "Рабочий день.\n";
  }
}