#include <iostream>

using namespace std;

int main() {
  int firstNumber, secondNumber;
  cout << "Введите первое число: ";
  cin >> firstNumber;
  cout << "Введите второе число: ";
  cin >> secondNumber;
  if (firstNumber>secondNumber)
  { cout << "Второе число меньше первого!\n"; }
  else if (firstNumber == secondNumber)
  { cout << "Числа равны!\n"; }
  else { cout << "Первое число меньше второго!\n"; }
}