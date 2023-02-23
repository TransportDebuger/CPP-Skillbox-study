#include <iostream>

int main() {
  std::cout << "Компьютерное зрение 2.0!\n";
  float xAxis, yAxis;

  for (bool correctCoord = false; !correctCoord; ) {
    std::cout << "Введите местоположение фигуры (X): \n";
    std::cin >> xAxis;
    if (xAxis >= 0.f && xAxis <0.8f) {
      correctCoord = true;
    } else {
     std::cout << "Значение лежит за пределами доски! \n";
    }
  }
  for (bool correctCoord = false; !correctCoord; ) {
    std::cout << "Введите местоположение фигуры (Y): \n";
    std::cin >> yAxis; 
    if (yAxis >= 0.f && yAxis <=0.8f) {
      correctCoord = true;
    } else {
     std::cout << "Значение лежит за пределами доски! \n";
    }
  }
  
  std::cout << "Фигура находится в клетке (" << (int) (xAxis*10.f) << ", " << (int) (yAxis*10.f) << ")\n";
  std::cout << "Поправьте положение фигуры на (" << (((int) (xAxis*10.f))+.5f)/10.f- xAxis << ", " <<  (((int) (yAxis*10.f))+.5f)/10.f- yAxis << ")\n";
}