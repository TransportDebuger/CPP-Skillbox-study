#include <iostream>
using namespace std;

int main() {
  cout << "Программа сложения необходимого количества чисел.\n";
  cout << "Сколько числел нужно сложить? ";
  int count, number, sum = 0, iterator = 0;
  cin >> count;
  while (iterator < count ) {
    cout << "Введите " << iterator+1 << " число: ";
    cin >> number;
    sum += number;
    ++iterator;
  }
  cout << "Итоговая сумма  - " << sum;
}