#include <iostream>
using namespace std;

int main() {
  cout << "Программа слоджения необходимого количества чисел.\n";
  cout << "Сколько числел нужно сложить? ";
  int count, sum = 0;
  cin >> count;
  for (int iterator = 0; iterator < count; iterator++ ) {
    cout << "Введите " << iterator+1 << " число: ";
    int number;
    cin >> number;
    sum += number;
  }
  cout << "Итоговая сумма  - " << sum;
}