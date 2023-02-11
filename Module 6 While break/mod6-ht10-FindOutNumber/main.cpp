#include <iostream>

int main() {
  std::cout << "Угадай число\n";
  int secretNumber, ansNumber = 63, delta=63;
  std::string  answer = "нет";
  std::cout << "Загадай число от 0 до 63: ";
  std::cin >> secretNumber;
  do {
    if (delta > 1) delta /=2;
    if (answer == "нет") {
      ansNumber -= delta;
    } else {
      ansNumber += delta;
    }
    std::cout << "Ваше число больше " << ansNumber << "? (да/нет): ";
    std::cin >> answer; 
  } while (ansNumber != secretNumber);
  
  // Предыдущее решение!
  /*while (ansNumber != secretNumber) {
    std::cout << "Ваше число больше " << ansNumber << "? (да/нет): ";
    std::cin >> answer;
    delta /= 2;
    if (answer == "нет") {
      ansNumber -= delta;
    } else {
      ansNumber += delta;
    } 
  } */
  std::cout << "Вы загадали число " << ansNumber;
}