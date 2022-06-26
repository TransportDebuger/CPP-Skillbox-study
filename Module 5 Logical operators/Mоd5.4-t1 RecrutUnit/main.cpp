#include <iostream>

int main() {
  int height, weight, flightTime, handsCount, legsCount;
  std::string eyeColor;

  std::cout << "------------Займемся отбором призывников--------------\n";
  std::cout << "Вес призывника (кг): ";
  std::cin >> height;
  std::cout << "Рост призывника (см): ";
  std::cin >> weight;
  std::cout << "Налет часов (ч): ";
  std::cin >> flightTime;
  std::cout << "Цвет глаз: ";
  std::cin >> eyeColor;
  std::cout << "Количество рук: ";
  std::cin >> handsCount;
    std::cout << "Количество ног: ";
  std::cin >> legsCount;
  if (flightTime >= 100 || ((height >= 145 && height<=165) && (weight>=45 && weight<=65) &&  handsCount == legsCount)) {
    if (eyeColor == "зеленый") {
      std::cout << "Заключение: не годен к прохождению службы летчиком.\n";
    } else {
      std::cout << "Заключение: годен к прохождению службы летчиком.\n";
    };
  } else {
    std::cout << "Заключение: не годен к прохождению службы летчиком.\n";
  }

}