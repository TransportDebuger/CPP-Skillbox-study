#include <iostream>

int main() {
  std::string answer;
  do {
    std::cout << "Ты сделал свою работу?\n";
    std::getline(std::cin, answer);
  } while (answer != "Да, конечно, сделал!");
  std::cout << "ОК";
}