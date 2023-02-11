#include <iostream>
#include <math.h>

int main() {
  std::cout << "Введите число: ";
  int number;
  std::cin >> number;
  std::cout << "Введите степень числа: ";
  int power;
  std::cin >> power;
  int counter = 0;
  while (counter <= power) {
    std::cout << pow(number, counter) << "\n";
    ++counter;
  }
}