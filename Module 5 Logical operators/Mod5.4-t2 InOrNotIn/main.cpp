#include <iostream>

int main() {
  int length, width, height;
  int dimentionX, dimentionY;

  std::cout << "Размеры кирпича (Д Ш В): ";
  std::cin >> length >> width >> height;
  std::cout << "Размеры отверстия (Х Y): ";
  std::cin >> dimentionX >> dimentionY;
  /* Проверим на сколько подходит кирпич по размерам */
  if (dimentionX>=length && (dimentionY>=height || dimentionY>=width)) {
    std::cout << "Отлично! Кирпич входит.\n";
  } else if (dimentionX>=width && (dimentionY>=height || dimentionY>=length)) {
    std::cout << "Отлично! Кирпич входит.\n";
  } else if (dimentionX>=height && (dimentionY>=width || dimentionY>=length)) {
    std::cout << "Отлично! Кирпич входит.\n";
  } else
  {
    std::cout << "Кирпич не войдет!\n";
  }
}