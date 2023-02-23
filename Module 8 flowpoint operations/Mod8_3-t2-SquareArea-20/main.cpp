#include <iostream>
using namespace std;

int main() {
  cout << "Мы даем скидки на участки, являющиеся точными квадратами\n";
  cout << "Введите площадь участка: ";
  int area;
  cin >> area;
  
  if (area > 1000000 && area < 1) {
    cout << "Участки такой площади в продаже отсутствуют!";
  
  } else {
    int iteration=1, check=0;
  
    for (; check < area; iteration++) { 
      check = iteration * iteration;
    }
    if (check == area) {
      cout << "Ура! На этот участок есть скидка!";
    } else {
      cout << "Увы! Скидка на этот участок отсутствует.";
    }
  
  }
  
}