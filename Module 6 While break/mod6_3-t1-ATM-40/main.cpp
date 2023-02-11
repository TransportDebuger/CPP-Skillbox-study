#include <iostream>
using namespace std;

int main() {
  int  PCODE = 42;
  cout << "Введите пин-код!\n";
  int pinCode, sum = 0;
  cin >> pinCode;
  while (pinCode != 0) {
    sum += pinCode % 10;
    pinCode /=  10;
  }
  if (sum != PCODE) { cout << "Ввод не верен!";} 
  else  { cout << "Ввод верен!";}
}