#include <iostream>

using namespace std;

int main() {
  int annualIncome;
  int taxPayment = 0;
  cout << "Введите ваш доход за год:";
  cin >> annualIncome;
  cout << "Расчитываем налоги---------\n";
  if (annualIncome > 50000)
  {
    taxPayment += (annualIncome-50000)*0.3;
    annualIncome = 50000;
  }
  if (annualIncome>10000) 
  {
    taxPayment += (annualIncome-10000)*0.2;
    annualIncome = 10000;
  }
  taxPayment += annualIncome*0.13;
  cout << "Всего к оплате налогов на сумму: " << taxPayment;
}