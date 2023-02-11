#include <iostream>

int main() {
  std::cout << "--= Является ли число степенью двойки. =--\n";
  std::cout << "Введите проверяемое число: ";
  int number;
  std::cin >> number;
  bool isFault = false;
  while (!isFault && number > 1) {
    isFault = number % 2 != 0;
    number /= 2;
  }
  if (!isFault && number == 1) {std::cout << "Число является степенью двойки!";} 
  else {std::cout << "Число не является степенью двойки!";}
}