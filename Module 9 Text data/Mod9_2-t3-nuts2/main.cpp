#include <iostream>

int main() {
  std::cout << "Орехи!\n";
  float price, weight, discount;
  std::cout << "Введите цену за 100 гр. товара: ";
  std::cin >> price;
  std::cout << "Введите массу товара в гр. : ";
  std::cin >> weight;
  std::cout << "Скидка (%): ";
  std::cin >> discount;
  price -= (price/100*discount);
  std::cout << "Стоимость товара составляет " << weight*.01f*price << " рублей.\n";
}