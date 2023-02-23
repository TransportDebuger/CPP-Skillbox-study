  #include <iostream>
using namespace std;

int main() {
  cout << "Банкомат 4.1\n";
  int  PCODE = 42;
  for (bool isRightPIN = false; !isRightPIN;) {
    cout << "Введите пин-код! ";
    int pinCode, sum = 0;
    cin >> pinCode;
    while (pinCode != 0) {
      sum += pinCode % 10;
      pinCode /=  10;
    }
  isRightPIN = sum == PCODE;
  if (!isRightPIN) { cout << "Ввод не верен!\n";} 
  }
  cout << "Ввод верен!\n";
}