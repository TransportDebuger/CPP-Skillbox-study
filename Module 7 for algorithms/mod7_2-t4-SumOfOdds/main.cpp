#include <iostream>

using namespace std;

int main() {
  std::cout << "Суммируем нечетные.\n";

  int startNumber, endNumber, sum = 0;
  cout << "Введите начало интервала - ";
  cin >> startNumber;
  cout << "Введите конец интервала - ";
  cin >> endNumber;

  for (startNumber; startNumber<=endNumber; startNumber++) {
    if (startNumber % 2 == 1) sum += startNumber; 
  }

  cout << "Сумма нечетных чисел в указанном интервале = " << sum;
}