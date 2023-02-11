#include <iostream>

int main() {
  std::cout << "Биолаборатория.\n";
  int bacValue, abDrops;
  std::cout << "Сколько бактерий в чашке Петри: ";
  std::cin >> bacValue;
  std::cout << "Сколько капель антибиотика добавим: ";
  std::cin >> abDrops;
  for (int count = 0; count < 10 && bacValue > 0; count++) {
    bacValue *= 2;
    bacValue -= (abDrops * (10-count));
    if (bacValue < 0) bacValue = 0; 
    std::cout << "Через " << count+1 << " час. останется " << bacValue << " бактерий\n"; 
  }
}