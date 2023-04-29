#include <iostream>
#include <iomanip>
#include <string>
#include <sstream>

int main() {

  //Реализация с помощью stringstream
  std::cout << "Bring me to the Double!\n";
  std::string answer;
  std::stringstream number;
  double result;

  std::cout << "Enter integer part of number: ";
  std::cin >> answer;
  number << answer;
  std::cout << "Enter fractional part of number: ";
  std::cin >> answer;
  number << "." << answer;
  number >> result;
  //выводим результат за одно и устанавливаем его точность в 16 знаков, что бы знаки не терять.
  std::cout << "Result number is: "<< std::setprecision(16) << result << std::endl;


} 