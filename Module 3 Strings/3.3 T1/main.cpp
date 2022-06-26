#include <iostream>

int main() {
  std::string Race;
  std::string Name;

  std::cout << "Введите расу персонажа: :";
  std::cin >> Race;
  std::cout << "Введите имя персонажа: :";
  std::cin >> Name;
  std::cout << "Родился новый " << Race << ", его зовут " << Name << ". Добро пожаловать в этот суровый мир!\n";
}