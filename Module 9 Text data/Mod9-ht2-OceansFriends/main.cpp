#include <iostream>
#include <cmath>

int main() {
  std::cout << "Друзья Оушена!\n";

  int knobQuantity, numberOfPositions;
  float checkTime;
  //вводим количество ручек на сейфе
  do {
    std::cout << "Введите количество ручек на сейфе: ";
    std::cin >> knobQuantity;
    if (knobQuantity < 1) {
      std::cout << "Количество ручек не может быть меньше одной.\n";
    }
  } while (knobQuantity < 1);
  //вводим количество позиций а ручке
  do {
    std::cout << "Введите количество позиций на ручке сейфа: ";
    std::cin >> numberOfPositions;
    if (numberOfPositions < 2) {
      std::cout << "Странные ручки. Количество позиций не может быть меньше двух.\n";
    }
  } while (numberOfPositions < 2);
  //вводим проверки комбинации
  do {
    std::cout << "Введите количество времени необходимое для проверки комбинации (сек.): ";
    std::cin >> checkTime;
    if (checkTime <= 0.f) {
      std::cout << "Время проверки не может быт меньше или равно 0.\n";
    }
  } while (checkTime <= 0.f);

  std::cout << "Время необходимое для перебора всех комбинаций составляет " << (float)std::pow(numberOfPositions, knobQuantity) * checkTime << " сек.\n";
}