#include <iostream>
#include <cmath> 

int main() {
  std::cout << "Космический симулятор!\n";

  float ssWeight = 0.f, enginePower, workTime;
  //вводим массу корабля
  do {
    std::cout << "Введите массу космического корабля (кг): ";
    std::cin >> ssWeight;
    if (ssWeight <= 0.f) {
      std::cout << "Масса космического корабля не может быть отрицательной или равной 0.\n";
    }
  } while (ssWeight <= 0.f);
  // вводим силу тяги двигателя
  do {
    std::cout << "Введите силу тяги двигателя (Н): ";
    std::cin >> enginePower;
    if (ssWeight < 0.f) {
      std::cout << "Тяга двигателя космического корабля не может быть отрицательной.\n";
    }
  } while (enginePower < 0.f);
  // вводим время работы двигателя
  do {
    std::cout << "Введите время работы двигателя (сек.): ";
    std::cin >> workTime;
    if (workTime < 0.f) {
      std::cout << "Время работы двигателя космического корабля не может быть отрицательным.\n";
    }
  } while (workTime < 0.f);

  {
    float acceleration = ssWeight / enginePower;
    std::cout << "Расстояние на которое переместиться корабль составляет " << acceleration * std::pow(workTime, 2) / 2 << " метров.\n";

  }
}