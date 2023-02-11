#include <iostream>
using namespace std;

int main() {
  cout << "Мы тестируем новую систему пин-кодов.\n";
  cout << "Вам нужно последовательно ввести 4 числа.\n";
  int PCODE = 42;
  int pinSum;
  do {
    int count = 4;
    int  iterator = 0;
    int pinPart;
    pinSum = 0;
    cout << "Введите числа!\n";
    while (iterator < count){
      cout << "Введите " << iterator+1 << " число:";
      cin >> pinPart;
      pinSum += pinPart;
      ++iterator;
    }
  } while (pinSum != PCODE);
  cout << "Код принят.";
}