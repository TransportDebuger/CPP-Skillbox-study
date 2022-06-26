#include <iostream>

int main() {
  std::cout << "Приветствуем вас в калькуляторе квартплаты! \n";
  int fullPrice = 4000000;
  std::cout << "Введите сумму, указанную в квитанции: " << fullPrice << "\n";
  int entranceCount = 10;
  std::cout << "Сколько подъездов в вашем доме? " << entranceCount  << "\n";
  int appartmentCount = 40;
  std::cout << "Сколько квартир в каждом подъезде? " << appartmentCount << "\n";
  std::cout << "----Считаем-----\n";
  int appartmentPayment = fullPrice / (entranceCount * appartmentCount);
  std::cout << "Каждая квартира должна заплатить по " << appartmentPayment << " руб.\n";
}