#include <iostream>

int main() {
  std::cout << "Елочка!\n";
  int triangleHeight;
  std::cout << "Введите высоту треугольнника: ";
  std::cin >> triangleHeight;
  int strLength = ( triangleHeight - 1 ) * 2 + 1;
  if (triangleHeight <= 0) {
    std::cout << "Недопустимая высота треугольника.\n";
  } else {
    for (int lcnt = 0; lcnt<triangleHeight; lcnt++) {
      int startPos = strLength/2 - lcnt;
      int endPos = strLength/2 + lcnt;
      for (int scnt = 0; scnt < strLength; scnt++) {
        if (scnt<startPos) {
          std::cout <<" ";
        } else if (scnt>endPos) {
          std::cout <<  "\n";
          break;
        } else
        {
          std::cout << "#";
        }
      }
    }
    std::cout << "\n";;
  }
}