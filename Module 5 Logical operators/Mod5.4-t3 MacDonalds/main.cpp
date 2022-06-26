#include <iostream>

int main() {
  int macCount;
  std::cout << "Макдональдс предлагает приобрести макнаггетсы в коробках по 6 и по 9 штук.\n";
  std::cout << "Сколько макнагетсов вы хотите приобрести? ";
  std::cin >> macCount;
  if (macCount % 6 == 0 || macCount % 9 == 0 || macCount % 6 == 3) {
    std::cout << "Заказ принят!\n";
  } else
  { 
    std::cout << "Заказ не принят! Макнаггетсы продаются в коробках по 6 и по 9 штук.\n";
  }
}