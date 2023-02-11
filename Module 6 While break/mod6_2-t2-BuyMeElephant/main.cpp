#include <iostream>

int main() {
  std::cout << "Как тебя зовут?\n";
  std::string reply;
  std::cin >> reply;
  std::cout << reply << ", купи слона!\n";
  while (1<2) {
      std::getline(std::cin, reply);
      std::cout << "Все говорят \"" << reply << "\", а ты купи слона!\n";
  };
}