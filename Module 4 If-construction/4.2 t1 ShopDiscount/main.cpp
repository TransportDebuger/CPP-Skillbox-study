#include <iostream>
using namespace std;

int main() {
  float firstProdPrice, secondProdPrice, thirdProdPrice, totalPrice;
  float discount=10;

  cout << "Введите стоимость товара 1: ";
  cin >> firstProdPrice;
  cout << "Введите стоимость товара 2: ";
  cin >> secondProdPrice;
  cout << "Введите стоимость товара 3: ";
  cin >> thirdProdPrice;
  totalPrice = firstProdPrice + secondProdPrice + thirdProdPrice;
  cout << "Всего товаров на сумму: "<< totalPrice<< "\n";
  if (totalPrice > 10000) 
  {
    cout << "Сумма ваших покупок превысила 10 000 рублей!\n";
    cout << "Вы получаете скидку "<<discount<<"%\n";
    discount = 1 - discount/100;
    totalPrice *= discount;
  }
  cout<<"Итого к оплате: "<<totalPrice<<" руб.\n";
}