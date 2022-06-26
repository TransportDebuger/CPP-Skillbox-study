#include <iostream>

int main() {
  int itemPrice = 6400;
  int deliveryCost = 350;
  int discountValue = 700;
  int total = itemPrice + deliveryCost - discountValue;

  std::cout << "Приветствуем вас в калькуляторе! Он поможет рассчитать полную стоимость товаров с учетом скидок и доставки.\n";
  std::cout << "Введите стоимость товара: " << itemPrice << "\n";
  std::cout << "Введите стоимость доставки: " << deliveryCost << "\n";
  std::cout << "Введите размер скидки: " << discountValue << "\n";
  std::cout << "-----Считаем-----\n";
  std::cout << "Итого: " << total << "\n";
}