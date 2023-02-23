#include <iostream>

int main() {
  std::cout << "Инопланетная пища!\n";
  std::cout << "У Вас всего 100 килограммов гречки. Ваше потребление должно составлять не более 4 кг. в месяц.\n";
  std::cout << "Сколько месяцев прошло? ";
  int passedMonths, totalWeight=100;
  std::cin >> passedMonths;
  
  for (int iteration = 0; iteration<passedMonths; iteration++) {
    totalWeight -= 4;
    if (totalWeight <= 0) {
      totalWeight = 0;
      std::cout << "Месяц " << iteration+1 << ": Остаток гречки " << totalWeight << " кг.\n";
      std::cout << "Надо было смотреть фильм \"Марсианин\"\n";   
      break;
    } else {
      std::cout << "Месяц " << iteration+1 << ": Остаток гречки " << totalWeight << " кг.\n";
    }
  }
}