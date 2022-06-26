#include <iostream>

int main() {
  int weightA, weightB, weightC, weightD;
  std::cout << "Введите массу 1 машины: \n";
  std::cin >> weightA;
  std::cout << "Введите массу 2 машины: \n";
  std::cin >> weightB;
  std::cout << "Введите массу 3 машины: \n";
  std::cin >> weightC;
  std::cout << "Введите массу 4 машины: \n";
  std::cin >> weightD;
  if (weightA > 1200 || weightB > 1200 || weightC > 1200 || weightD > 1200)
  {
    std::cout << "Есть машина с превышением допустимой массы!\n";
  } else
  { std::cout << "Масса всех машин допустима.\n";}
}