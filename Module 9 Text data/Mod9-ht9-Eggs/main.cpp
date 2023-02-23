#include <iostream>
#include <cmath>

int main() {
  std::cout << "Яйца!\n";
  float dangerLevel, lowdeep=0.f, highdeep=4.f, deep = (lowdeep + highdeep)/2.f;
  bool isHarmless = false;

  std::cout << "Введите максимально допустимый уровень опасности: ";
  std::cin >> dangerLevel;
  std::cout << deep << "\n";
  
  do {
    float currentLevel = std::pow(deep, 3) - 3.f  *  std::pow(deep, 2) - 12.f * deep + 10.f;
    std::cout << "Проба грунта с глубины " << deep << " м. Уровень опасности " << currentLevel << "\n";
    isHarmless = (dangerLevel >= std::abs(currentLevel));
    if (currentLevel < 0 && isHarmless == false) {
        highdeep = deep;
    } else if (currentLevel > 0 && isHarmless == false) {
        lowdeep = deep;
    }
    deep = (highdeep + lowdeep)/2.f;
  } while (!isHarmless);
  
  std::cout << "Приблизительная глубина безопасной кладки: " << deep << " м.\n";
}