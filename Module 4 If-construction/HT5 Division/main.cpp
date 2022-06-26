#include <iostream>

int main() {
  int firstNumber, secondNumber;

  std::cout << "Проверим, делится ли одно число на второе без остатка!\n";
  std::cout << "Введите первое число: ";
  std::cin >> firstNumber;
  std::cout << "Введите второе число: ";
  std::cin >> secondNumber;
  if (firstNumber % secondNumber == 0)
  { std::cout << "Поделили без остатка.";}
  else 
  {std::cout << "Остаток есть!";}
   
}

