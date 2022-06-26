#include <iostream>

int main() {
  int markAxisX, markAxisY;
  std::cout << "Введите координаты точки (X Y): ";
  std::cin >> markAxisX >> markAxisY;
  if (markAxisX > 0 && markAxisY > 0)
  {
      std::cout << "Точка расположена в первой четверти.\n";
  } else if (markAxisX > 0 && markAxisY < 0) 
  {
    std::cout << "Точка расположена в четвертой четверти.\n";
  } else if (markAxisX > 0 && markAxisY == 0)
  {
    std::cout << "Точка расположена на границе первой и четвертой четвертей.\n";
  } else if (markAxisX < 0 && markAxisY > 0)
  {
    std::cout << "Точка расположена во второй четверти.\n";
  } else if (markAxisX < 0 && markAxisY < 0) 
  {
    std::cout << "Точка расположена в третьей четверти.\n";
  } else if (markAxisX < 0 && markAxisY == 0) 
  {
    std::cout << "Точка расположена на границе второй и третьей четверти четвертей.\n";
  } else if (markAxisX == 0 && markAxisY > 0)
  {
    std::cout << "Точка расположена на границе первой и второй четверти.\n";
  } else if (markAxisX == 0 && markAxisY < 0) 
  {
    std::cout << "Точка расположена на границе третьей и четвертой четверти.\n";
  } else 
  {
    std::cout << "Точка расположена в начале координат.\n";
  }
}