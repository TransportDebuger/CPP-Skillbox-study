#include <iostream>

int main() {
  std::cout << "--- Ищем знаение N члена ряда Фибоначчи.\n";
  int number1 = 0, number2 = 1, count, iteration = 0;
  std::cout << "Введите порядковый номер N члена: ";
  std::cin >> count;
  do {
    ++iteration;
    int buffer;
    buffer = number2;
    number2 += number1;
    number1 = buffer;
  } while (iteration < count-1);
  if (number2 < 0) {std::cout <<  "Значение не помещается в память.";} 
  else {std::cout << number2 << "\n";}
}