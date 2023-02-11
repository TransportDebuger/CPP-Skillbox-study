#include <iostream>
using namespace std;

int main() {
  cout << "Сапер!\n";
  cout << "Будем разминировать!\n";
  bool isBombDefused = false;
  int counter = 10;

  for (; counter>0  && !isBombDefused; counter--) {
    std::string answer;
    cout << "Осталось " << counter << " шагов. Будем резать провод ? (да/нет): ";
    cin >> answer;
    isBombDefused = answer == "да";
  }
  if (isBombDefused) {
    cout << "Бомба обезврежена за " << counter << " шагов до взрыва.";
  } else {
    cout << "Сапер ошибается только 1 раз. Покойся с миром.";
  }
}