#include <iostream>

int main() {
  std::cout << "Введите число!\n";
  int number;
  std::cin >> number;
  while (number !=0) {
    std::cout << number % 10;
    number /= 10;
  }
}