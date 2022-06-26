#include <iostream>

int main() {
  int circleCount = 4;
  int engine = 254;
  int weels = 93;
  int steeringWeel = 49;
  int windPower = -21;
  int rainPower = -17;
  int speed = engine + weels + steeringWeel + windPower + rainPower;

  std::cout << "===================\n";
  std::cout << "\n";
  std::cout << "Супер гонки. Круг " << circleCount << "\n";
  std::cout << "\n";
  std::cout << "===================\n";
  std::cout << "\n";
  std::cout << "Шумахер (" << speed << ")\n";
  std::cout << "\n";
  std::cout << "===================\n";
  std::cout << "\n";
  std::cout << "Водитель: Шумахер\n";
  std::cout << "Скорость: " << speed << "\n";
  std::cout << "\n";
  std::cout << "-------------------\n";
  std::cout << "\n";
  std::cout << "Оснащение\n";
  std::cout << "\n";
  std::cout << "Двигатель: " << engine << "\n";
  std::cout << "Колеса: " << weels << "\n";
  std::cout << "Руль: " << steeringWeel << "\n";
  std::cout << "\n";
  std::cout << "-------------------\n";
  std::cout << "\n";
  std::cout << "Действия плохой погоды\n";
  std::cout << "\n";
  std::cout << "Ветер: " << windPower << "\n";
  std::cout << "Дождь: " << rainPower << "\n";
  std::cout << "\n";   
}