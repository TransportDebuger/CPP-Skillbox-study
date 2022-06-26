#include <iostream>

int main() {
  int workDayLength = 480;
  int clientTime = 2;
  int cashierTime = 4;
  int clientsCount = workDayLength / (clientTime + cashierTime) ;

  std::cout << "Эта программа рассчитает, сколько клиентов успеет обслужить кассир за смену.\n";
  std::cout << "Введите длительность смены в минутах: " << workDayLength << "\n";
  std::cout << "Сколько минут клиент делает заказ? " << clientTime <<  "\n";
  std::cout << "Сколько минут кассир собирает заказ? " << cashierTime << "\n";
  std::cout << "-----Считаем-----\n";
  std::cout << "За смену длиной " << workDayLength << " минут кассир успеет обслужить " << clientsCount << " клиентов\n";

}