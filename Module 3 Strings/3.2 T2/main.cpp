#include <iostream>

int main() {
  int itemPrice;
  int deliveryCost;
  int discountValue;
  int total;

  std::cout << "Приветствуем вас в калькуляторе! Он поможет рассчитать полную стоимость товаров с учетом скидок и доставки.\n";
  std::cout << "Введите стоимость товара: ";
  std::cin >> itemPrice;
  std::cout << "Введите стоимость доставки: ";
  std::cin >> deliveryCost;
  std::cout << "Введите размер скидки: ";
  std::cin >> discountValue;
  std::cout << "-----Считаем-----\n";
  total = itemPrice + deliveryCost - discountValue;
  std::cout << "Итого: " << total << "\n";
}