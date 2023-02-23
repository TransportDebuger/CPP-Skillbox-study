#include <iostream>
#include <cmath>

int main() {
  std::cout << "Биолаборатория 2.0\n";

  int waterDrops;
  float antibacDrops, numberOfBac;
  do {
    std::cout << "Количество капель воды: ";
    std::cin >> waterDrops;
    if (waterDrops < 1) {
      std::cout << "Опыт не получиться. Нужно добавить воды.\n";
    } 
  } while (waterDrops < 1);
  do {
    std::cout << "Количество капель антибиотика: ";
    std::cin >> antibacDrops;
    if (antibacDrops < 1.f) {
      std::cout << "Соберись! Нужно добавить антибиотик.\n";
    }
  } while (antibacDrops < 1.f);
  do {
    std::cout << "Количество королебактерий: ";
    std::cin >> numberOfBac;
    if (numberOfBac < 1.f) {
      std::cout << "Не переводи образцы! Бактерии надо добавить.\n";
    }
  } while (numberOfBac < 1.f);
  std::cout << "Отлично. Начинаем опыт.\n";
  for (int count = 1; count <= 20; count++) {
    antibacDrops *= 0.8f;
    float concentration = antibacDrops / (float) waterDrops;
    numberOfBac = std::round(2*numberOfBac - numberOfBac * concentration);
    std::cout <<"Длительность опыта " << count << " минут. \nКонцентрация антибиотика: " << concentration << " Количество бактерий: " << numberOfBac << "\n";
  }
}