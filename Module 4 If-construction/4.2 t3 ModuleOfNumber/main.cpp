#include <iostream>
using namespace std;

int main() {
  float number;
  cout << "Введите число: ";
  cin >> number;
  cout << "Модуль числа " << number << " равен ";
  if (number < 0) {
    number = -number;
  }
  cout << number;
}