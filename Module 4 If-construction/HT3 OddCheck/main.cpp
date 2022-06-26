#include <iostream>

int main() {
  int numValue;

  std::cout << "Проверяем число на четность!\n";
  std::cout << "Введите число: ";
  std::cin >> numValue;
  if ((numValue%2) == 0) 
  { std::cout << "Введено четное число!";}
  else { std::cout << "Введено нечетное число!";}
}