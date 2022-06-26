#include <iostream>

int main() {
int length, width, height;
  int dimX, dimY, dimZ;

  std::cout << "Размеры коробки 1 (Д Ш В): ";
  std::cin >> length >> width >> height;
  std::cout << "Размеры коробки 2 (Д Ш В): ";
  std::cin >> dimX >> dimY >> dimZ;
  /* Проверим на сколько подходит Коробка по размерам */
  if (dimX>length && ((dimY>height && dimZ>width) || (dimZ>height && dimY>width))) 
  {
    std::cout << "Отлично! Коробка входит.\n";
  } else if (dimX>width && ((dimY>height && dimZ>length) || (dimZ>height && dimY>length))) {
    std::cout << "Отлично! Коробка входит.\n";
  } else if (dimX>height && ((dimY>width && dimZ>length) || (dimZ>width && dimY>length))) {
    std::cout << "Отлично! Коробка входит.\n";
  } else
  {
    std::cout << "Коробка не войдет!\n";
  }
}