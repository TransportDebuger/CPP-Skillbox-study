#include <iostream>
using namespace std;

int main() {
  cout << "Мы даем скидки на участки, являющиеся точными квадратами\n";
  cout << "Введите площадь участка: ";
  int area;
  cin >> area;
  int iteration=1, check=0;
  if (area > 1000000) {
    cout << "Участки такой площади в продаже отсутствуют!";
  } else {
    while (check < area) {
      check = iteration * iteration;
      ++iteration;
    }
    if (check == area) {
      cout << "Ура! На этот участок есть скидка!";
    } else {
      cout << "Увы! Скидка на этот участок отсутствует.";
    }
  }
}