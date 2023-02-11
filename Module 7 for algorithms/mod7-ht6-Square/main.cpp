#include <iostream>

int main() {
  std::cout << "Прямоугольник\n";

  int strLength, strCount;
  std::cout << "Ввведите ширину прямоугольника: ";
  std::cin >> strLength;
  std::cout << "Введите количество строк: ";
  std::cin >> strCount;
  for (int linesCount = 0; linesCount < strCount; linesCount++ ) {
    for (int simCount = 0; simCount < strLength; simCount++) {
      if (simCount == 0) {std::cout << "|";}
      else if (simCount == strLength-1) {std::cout << "|\n";}
      else if (linesCount == 0 || linesCount == strCount-1) {std::cout << "-";}
      else {std::cout << " ";}
    }
  }
}