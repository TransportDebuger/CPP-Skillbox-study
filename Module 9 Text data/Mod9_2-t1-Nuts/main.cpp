#include <iostream>

int main() {
  std::cout << "Орехи!\n";
  float price, weight;
  std::cout << "Введите цену за 100 гр. товара: ";
  std::cin >> price;
  std::cout << "Введите массу товара в гр. : ";
  std::cin >> weight;
  std::cout << "Стоимость товара составляет " << weight*.01f*price << " рублей.\n";
}