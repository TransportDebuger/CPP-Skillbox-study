#include <iostream>

int main() {
  int money, hund, diff;
  std::cout << "Склонение русских слов.\n";
  std::cout << "Какая сумма денег? ";
  std::cin >> money;
  if (money < 10) {
    diff = money;
  } else {
  diff = money / 10*10;
  diff = money % (diff);
  hund = money / 100*100;
  }
  if (diff >= 5 || diff==0 || (money-hund >= 11 && money-hund <= 14)) {
    std::cout << money << " рублей.\n";
  } else if (diff >= 2 && diff <= 4) {
    std::cout << money << " рубля.\n";
  } else {
    std::cout << money << " рубль.\n";
  }
}