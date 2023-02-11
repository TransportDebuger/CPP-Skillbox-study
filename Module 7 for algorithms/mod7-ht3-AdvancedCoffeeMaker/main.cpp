#include <iostream>

int main() {
  std::cout << "Кофемашина 2.0\n";
  int waterVolume = 0, milkVolume = 0, amCups = 0, capCups = 0;

  std::cout << "\n======== Обслуживание ========\n";
  std::cout << "Какой объем воды зальем? (мл): ";
  std::cin >> waterVolume;
  std::cout << "Какой объем молока зальем? (мл): ";
  std::cin >> milkVolume;

  for (bool isPowerOn = true; isPowerOn;) {
    
    std::cout << "\n========       Отчет об ингредиентах      ========\n";
    std::cout << "Емкость 1 содержит " << waterVolume << " мл. воды.\n";
    std::cout << "Емкость 2 содержит " << milkVolume << " мл. молока.\n";
    bool americano = waterVolume >= 300;
    bool capuchino = waterVolume >= 30 && milkVolume >=270;
    if (!americano && !capuchino) {
      std::cout << "\n======== Закончились ингредиенты для кофе ========\n";
      std::cout << "Остаток: " << waterVolume << " мл. воды, " << milkVolume << " мл. молока.\n";
      std::cout << "За смену приготовлено (чашек): " << amCups << " американо, " << capCups << " капучино.\n";
      std::cout << "========            Выключение!           ========\n";
      isPowerOn = false;
    } else {
      std::cout << "\n========   Доступные опции приготовления  ========\n";
      if (americano) std::cout << "1 - Американо\n";
      if (capuchino) std::cout << "2 - Капучино\n";
      std::cout << "Какой кофе приготовить ? ";
      int chooseDrink;
      std::cin >> chooseDrink;
      if (chooseDrink == 1) {
        if (americano) {
          std::cout << "Ваш американо готов.\n";
          waterVolume -= 300;
          ++amCups;
        }
      } else if (chooseDrink == 2) {
        if (capuchino) {
          std::cout << "Ваш капучино готов.\n";
          milkVolume -= 270;
          waterVolume -= 30;
          ++capCups;
        }
      }
    }
  }
}