#include <iostream>
#include <cmath>

int main() {
  std::cout << "Убийца Photoshop!\n";
  float leftBorder, rightBorder, pointPlace;

  std::cout << "Введите яркость левой границы градиента: ";
  std::cin >> leftBorder;
  std::cout << "Введите яркость правой границы градиента: ";
  std::cin >> rightBorder;
  std::cout << "Введите положение точки между границами: ";
  std::cin >> pointPlace;

  std::cout << "Вывод: \n Яркость точки: " << std::abs(rightBorder - leftBorder) * pointPlace;
}