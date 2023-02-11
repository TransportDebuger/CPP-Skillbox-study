#include <iostream>
using namespace std;

int main() {
  cout << "Сократитель дробей.\n";
  int numerator, denominator, gcd1, gcd2;
  cout << "Введите числитель и знаменатель дроби: ";
  cin >> numerator >> denominator;
  gcd1 = numerator;
  gcd2 = denominator;
  while (gcd1 != gcd2) {
    if (gcd1 > gcd2) {
      gcd1 -= gcd2;
    }
    else {
      gcd2 -= gcd1;
    } 
  }
  cout << "Результат сокращения дроби - " << numerator / gcd1 << "/" << denominator / gcd1 << "\n";
}