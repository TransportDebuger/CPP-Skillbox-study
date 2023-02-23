#include <iostream>
#include <cmath>

int main() {
  std::cout << "Определение большего числа!\n";

  float numberA, numberB, maxNumber;
  std::cout << "Введите первое число: ";
  std::cin >>  numberA;
  std::cout << "Введите второе число: ";
  std::cin >>  numberB;
  maxNumber = (numberA + numberB + std::abs(numberA - numberB))/2.f;
  std::cout << "Наибольшее число равно " << maxNumber << "\n";
}