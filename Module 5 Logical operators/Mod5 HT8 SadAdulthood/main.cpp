#include <iostream>

int main() {
  int curYear, curMonth, curDay;
  int birthYear, birthMonth, birthDay;

  std::cout << "Введите текущую дату! (год, месяц, день)";
  std::cin >> curYear >> curMonth >> curDay;
  std::cout << "Введите дату рождения посетителя! (год, месяц, день)";
  std::cin >> birthYear >> birthMonth >> birthDay;
  if (curYear - birthYear > 18) {
    std::cout << "Продажа алкогольной продукции разрешена.\n";
  } else if (curYear - birthYear == 18) {
    if (curMonth - birthMonth > 0) {
      std::cout << "Продажа алкогольной продукции разрешена.\n";
    } else if (curMonth - birthMonth == 0) {
      if (curDay - birthDay > 0) {
        std::cout << "Продажа алкогольной продукции разрешена.\n";
      } else {
        std::cout << "Нельзя продавать алкогольную продукцию. Посетитель несовершеннолетний.\n";
      }
    } else {std::cout << "Нельзя продавать алкогольную продукцию. Посетитель несовершеннолетний.\n";
    }
  } else {
    std::cout << "Нельзя продавать алкогольную продукцию. Посетитель несовершеннолетний.\n";
  }

}