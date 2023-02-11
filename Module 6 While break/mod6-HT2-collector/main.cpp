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
    cout << name << ". Я не уверен, что успел задолжать Вам " << -debt << " рублей!";
  } else {
    int payment = 0;
    bool isRepaid = payment >= debt;
    while (!isRepaid) {
        cout << name << ". Какую сумму вы возвращаете? ";
        cin >> payment;
        isRepaid = payment >= debt;
        if (!isRepaid) {cout << "Этого не достаточно для погашения долга!\n";}
    }
    cout << "Поздравляю, " << name << "! Ваш долг полностью выплачен.\n";
  }
}