#include <iostream>

int main() {
  int passengerTotal = 0;
  int passengerCount = 0;
  int passengerEnter = 0;
  int passengerExit = 0;
  int ticketPrice = 20;
  int totalIncome = 0;
  
  std::cout << "Прибываем на остановку Улица Программистов. В салоне пассажиров:" << passengerTotal << "\n";
  std::cout << "Сколько пассажиров вышло на остановке?";
  std::cin >> passengerExit;
  std::cout << "Сколько пассажиров зашло на остановке?";
  std::cin >> passengerEnter;
  passengerTotal = passengerTotal - passengerExit + passengerEnter;
  passengerCount += passengerEnter;
  std::cout << "Отправляемся с остановки Улица Программистов. В салоне пассажиров: "<< passengerTotal << "\n";
  std::cout << "-------- Едем ----------";
 std::cout << "Прибываем на остановку Улица Алгоритмов. В салоне пассажиров:" << passengerTotal << "\n";
  std::cout << "Сколько пассажиров вышло на остановке?";
  std::cin >> passengerExit;
  std::cout << "Сколько пассажиров зашло на остановке?";
  std::cin >> passengerEnter;
  passengerTotal = passengerTotal - passengerExit + passengerEnter;
  passengerCount += passengerEnter;
  std::cout << "Отправляемся с остановки Улица Алгоритмов. В салоне пассажиров: "<< passengerTotal << "\n";
  std::cout << "-------- Едем ----------";
  std::cout << "Прибываем на остановку Улица Переменых. В салоне пассажиров:" << passengerTotal << "\n";
  std::cout << "Сколько пассажиров вышло на остановке?";
  std::cin >> passengerExit;
  std::cout << "Сколько пассажиров зашло на остановке?";
  std::cin >> passengerEnter;
  passengerTotal = passengerTotal - passengerExit + passengerEnter;
  passengerCount += passengerEnter;
  std::cout << "Отправляемся с остановки Улица Переменных. В салоне пассажиров: "<< passengerTotal << "\n";
  std::cout << "-------- Едем ----------";
  std::cout << "Прибываем на остановку Площадь Логики. В салоне пассажиров:" << passengerTotal << "\n";
  std::cout << "Сколько пассажиров вышло на остановке?";
  std::cin >> passengerExit;
  std::cout << "Сколько пассажиров зашло на остановке?";
  std::cin >> passengerEnter;
  passengerTotal = passengerTotal - passengerExit + passengerEnter;
  passengerCount += passengerEnter;
  std::cout << "Отправляемся с остановки Площадь Логики. В салоне пассажиров: "<< passengerTotal << "\n";
  
  totalIncome = ticketPrice * passengerCount;
  std::cout << "Всего заработали: " << totalIncome << " руб.\n";
  int driverSalary = totalIncome / 4;
  std::cout << "Зарплата водителя: " << driverSalary << " руб.\n";
  int fuelPayment = totalIncome / 5;
  std::cout << "Расходы на топливо: " << fuelPayment << " руб.\n";
  int taxes = totalIncome / 5;
  std::cout << "Налоги: " << taxes << " руб.\n";
  int renovationPayment = totalIncome / 5;
  std::cout << "Расходы на ремонт машины: " << renovationPayment << " руб.\n";
  int totalProfit = totalIncome - driverSalary - fuelPayment - taxes - renovationPayment;
  std::cout << "Итого доход: " << renovationPayment << " руб.\n";
}