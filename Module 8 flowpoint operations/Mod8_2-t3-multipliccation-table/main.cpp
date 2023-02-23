#include <iostream>

using namespace std;

int main() {
  cout << "Таблица умножения!\n";
  int number;
  cout << "Для какого числа нужна таблица умножения? ";
  cin >> number;

  for (int multiplier = 1; multiplier <= 9; multiplier++) {
    cout << number << "х" << multiplier <<" = " << number * multiplier << "\n";
  }

}