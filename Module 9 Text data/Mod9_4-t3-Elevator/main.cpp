#include <iostream>
#include <cmath>

int main() {
  std::cout << "Лифт!\n";
  float height, floorheight = 3.975f;

  std::cout << "Введите высоту на которой застрял лифт: ";
  std::cin >> height;
  if (height < 0.f) {
    std::cout << "Введена неверная высота.\n";
  } else {
    std::cout << "Лифт застрял на " << std::round((height / floorheight)*1) << " этаже.\n";
  }
}