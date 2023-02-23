#include <iostream>
#include <cmath>

int main() {
  std::cout << "Red Mars 2.0!\n";

  int xAxis = (int) (0.001f * 1.496e+11f), yAxis=0;

  std::string command;
  std::cout << "Марсоход готов к движению. Стартовые координаты на удалении (X, Y) " << xAxis  << " , " << yAxis << " м. от планируемой точки высадки.\n";
  for (bool isOperate = true; isOperate; ) {
    std::cout << "Куда движемся? (W, S, A, D): ";
    std::cin >> command;
    if (command == "W" || command == "w") {
     xAxis += 1;
    } else if (command == "S" || command == "s") {
     xAxis -= 1;
    } else if (command == "D" || command == "d") {
     yAxis += 1;
    } else if (command == "A" || command == "a") {
     yAxis -= 1;
    } else {
      std::cout << "Не понял команду.\n";
    }
    std::cout << "Мы находимся на удалении (X, Y) " << xAxis << " , " << yAxis << " м. от планируемой точки высадки.\n";
  }
}