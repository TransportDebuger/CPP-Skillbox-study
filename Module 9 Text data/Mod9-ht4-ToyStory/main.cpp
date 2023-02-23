#include <iostream>
#include <cmath>

int main() {
  std::cout << "Игрушечная история!\n";

  float length, height, width;
  std::cout << "Введите параметры бруска (Д Ш В) см.: ";
  std::cin >> length >> width >> height;
  if (length <= 0.f or width <= 0.f or height <= 0.f) {
    std::cout << "Таких брусков не бывает!\n";
  } else if (length<5.f or width<5.f or height< 5.f) {
    std::cout << "Нам такой брусок не нужен.\n";
  } else {
    float numberOfCubes = (float) ((int) length/5 * (int) width/5 * (int) height / 5);
    std::cout << "Из бруска можно вырезать " << numberOfCubes << " кубиков.\n";
    std::cout << "Можно сложить набор из " << std::pow(std::floor(std::cbrt(numberOfCubes)), 3) << " кубиков.\n";
  }
}