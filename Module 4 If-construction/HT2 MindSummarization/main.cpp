#include <iostream>

int main() {
  int firstNumber = rand()%1000+1;
  int secondNumber = rand()%1000+1;
  int userAnswer;
  
  std::cout << "Давайте проверим как вы складываете в уме!\n" ; 
  std::cout << "Сложите число " << firstNumber << " с числом " << 
    secondNumber <<".\n";
  std::cout << "Введите результат сложения: ";
  std::cin >> userAnswer;
  if (userAnswer == (firstNumber+secondNumber))
  { std::cout << " Результат верен!";}
  else
  { std::cout << " Результат не верен!";};
}