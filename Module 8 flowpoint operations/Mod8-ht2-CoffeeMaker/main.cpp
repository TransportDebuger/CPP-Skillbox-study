#include <iostream>

int main() {
  std::cout << "Кофемашина.\n";
  int waterVolume = 0, milkVolume = 0;
  
  for (bool isPowerOn = true; isPowerOn;) {
    
    std::cout << "\n======== Проверка емкостей ========\n";

    std::cout << "Емкость 1 содержит " << waterVolume << " мл. воды.\n";
    if (waterVolume < 30) {
      std::cout << "Нехватает воды для приготовления кофе. Какой объем воды зальем? (мл): ";
      int addedWater;
      std::cin >> addedWater;
      waterVolume += addedWater;
    } else if (waterVolume < 300) {
      std::cout << "Без воды не все напитки возможно приготовить. Добавим воды? (мл): ";
      int addedWater;
      std::cin >> addedWater;
      waterVolume += addedWater;
    }

    std::cout << "Емкость 2 содержит " << milkVolume << " мл. молока.\n";
    if (milkVolume < 270 ) {
       std::cout << "Нехватает молока для приготовления кофе. Какой объем молока зальем? (мл): ";
       int addedMilk;
       std::cin >> addedMilk;
       milkVolume += addedMilk;
    
    }

    if (waterVolume >= 300 || (waterVolume >=30 && milkVolume >= 270)) {
      std::cout << "======== Доступные опции приготовления ========\n";
      if (waterVolume >= 300) std::cout << "1 - Американо\n";
      if (waterVolume >= 30 && milkVolume >=270) std::cout << "2 - Капучино\n";
      std::cout << "Какой кофе приготовить ? ";
      int chooseDrink;
      std::cin >> chooseDrink;
      if (chooseDrink == 1) {
        std::cout << "Ваш американо готов.\n";
        waterVolume -= 300;
      } else {
        std::cout << "Ваш капучино готов.\n";
        milkVolume -= 270;
        waterVolume -= 30;
      }
    }
    std::string answer;
    std::cout << "Продолжить обслуживание? (да/нет):\n";
    std::cin >> answer;
    if (answer == "нет") isPowerOn = false;
  }
}