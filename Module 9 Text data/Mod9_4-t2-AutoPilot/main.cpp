#include <iostream>
#include <cmath>

int main() {
  std::cout << "Автопилот!\n";

  int degrees;
  std::cout << "Введите угол тангажа в градусах: ";
  std::cin >> degrees;
  degrees -= (degrees / 360) * 360;
  degrees += 360 * (degrees / -180);
  if (std::abs((float) degrees * 3.14f / 180.f) > .28f) {
    std::cout << "Угол небезопасен!\n";
  } else {std::cout << "Угол безопасен.\n"; };
  }