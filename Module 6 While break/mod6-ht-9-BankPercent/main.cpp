#include <iostream>

int main() {
  std::cout << "Посчитаем деньги в банке.\n";
  int deposit, bankPercent, goal, count = 0;
  std::cout << "Введите сумму денежных средств, размещенных в банке (руб.): ";
  std::cin >> deposit;
  std::cout << "Введите величину банковских процентов(%): .";
  std::cin >> bankPercent;
  std::cout << "Какую сумму необходимо получить в результате размещения? ";
  std::cin >> goal;
  while (deposit < goal) {
      deposit += (deposit * bankPercent / 100);
      ++count;
  }
  std::cout << "Для достиженияя вашей цели вам необходимо разместить денежные средства на " << count << " (года) лет.";
}