#include <iostream>

int main() {
  int day, startDayofWeek; 
  std::cout << "Майские!\n";
  std::cout << "Введите число в мае: ";
  std::cin >> day;
  std::cout << "C какого дня недели начинается месяц: ";
  std::cin >> startDayofWeek;
  if ((day + startDayofWeek-1) % 7 == 6 || (day + startDayofWeek-1) % 7 == 0 || (day >= 1 && day <=5) || (day >=8 && day <= 10)) {
    std::cout << "Выходной!\n";
  } else
  {
    std::cout << "Рабочий день.\n";
  }
}