#include <iostream>

int main() {
  int alcoholQuantity, medPackQuantity;

  std::cout << "Военный фельдшер.\n";
  std::cout << "Сколько спирта взяли (ml)? ";
  std::cin >> alcoholQuantity;
  std::cout << "Сколько аптечек взяли? ";
  std::cin >> medPackQuantity;
  if (alcoholQuantity >= 2000 || medPackQuantity >=5)
  {
    std::cout << "Все ОК.";
  } else {
    std::cout << "Вы не подготовились.";
  }
}