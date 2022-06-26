#include <iostream>

int main() {
  int value;

  std::cout << "Расчитаем квадрат числа!\n";
  std::cout << "Введите число: ";
  std::cin >> value;
  value = value * value;
  std::cout << "Квадрат введенного числа = " << value << "\n";
}