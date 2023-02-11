#include <iostream>
using namespace std;

int main() {
  cout << "====Робот-коллектор.====\n";
  cout << "Ваше имя? ";
  string name;
  cin >> name;
  cout << "Сумма долга? ";
  int debt;
  cin >> debt;
  if (debt<0) {
    cout << name << ". Я не уверен, что успел задолжать Вам " << -debt << " рублей!\n";
  } else {
    int totalPayment = 0;
    bool isRepaid = totalPayment >= debt;
    while (!isRepaid) {
      int payment;
      cout << name << ". Какую сумму вы возвращаете? ";
      cin >> payment;
      if (payment <= 0) {
        cout << "Давайте оплачивать долг! Вам осталось внести " << debt-totalPayment <<".\n";
      } else {
        totalPayment += payment;
        isRepaid = totalPayment >= debt;
        cout << name << ", итого вы внесли " << totalPayment << ".\n";
        if (totalPayment < debt) {cout << "Вам осталось внести " << debt-totalPayment <<".\n";}
      }
    }
    cout << "Поздравляю, " << name << "! Вы ничего не должны.\n";
    if (totalPayment-debt > 0) {cout << "Остаток на счете составляет " << totalPayment-debt << " рублей!\n"; }
  }
}