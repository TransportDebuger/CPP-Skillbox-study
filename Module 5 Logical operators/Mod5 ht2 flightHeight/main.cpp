#include <iostream>

int main() {
  int flightSpeed, altitude;
  std::cout << "Проверка эшелона.\n";
  std::cout << "Высота полета: ";
  std::cin >> altitude;
  std::cout << "Скорость полета: ";
  std::cin >> flightSpeed;
  if ((flightSpeed >= 750 && flightSpeed <= 850) && (altitude >= 9000 && altitude <=9500)) {
    std::cout << "Полет нормальный!\n";
  } else {
    std::cout << "Что-то пошло не так!\n";
  }
}