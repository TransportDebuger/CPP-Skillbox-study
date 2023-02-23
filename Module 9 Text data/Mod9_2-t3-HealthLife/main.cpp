#include <iostream>

int main() {
  std::cout << "ЗОЖ!\n";
  float protein, carbohydrates, weight;
  std::cout << "Введите количество белка на 100 гр.: ";
  std::cin >> protein;
  std::cout << "Введите количество углеводов на 100 гр.: ";
  std::cin >> carbohydrates;
  std::cout << "Введите массу нетто : ";
  std::cin >> weight;
  protein *= 0.01f*weight;
  carbohydrates *= 0.01f*weight; 
  std::cout << "Масса белков в упаковке " << protein << " гр.\n";
  std::cout << "Масса углеводов в упаковке " << carbohydrates << " гр.\n";
  
}