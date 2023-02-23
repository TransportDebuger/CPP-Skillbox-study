#include <iostream>
#include <cmath>

int main() {
  std::cout << "Кенийский бегун!\n";

  std::cout << "Сколько километров пробежали? ";
  int distance;
  std::cin >> distance;
  if (distance < 1) {
    std::cout << "Это разве дистанция?\n";
  } else {
    float avgPace = 0.f;
    for (int count = 1; count <= distance; count++) {
      float currentValue = 0.f;
      do {
        std::cout << "Какой у тебя был темп на километре " << count << " ? ";
        std::cin >> currentValue;
        if (currentValue <= 0.f) {
          std::cout << "Не расслышал. Повтори.\n";
        } 
      } while (currentValue <= 0.f);
      avgPace += currentValue;
    }
    avgPace /= distance;
    std::cout << avgPace <<"\n";
    std::cout << "Средний темп бега составляет " << (int) (avgPace/60.f) << " минуты " << std::round(avgPace - ((int) (avgPace/60.f)*60)) << " секунды.\n";
  }
}