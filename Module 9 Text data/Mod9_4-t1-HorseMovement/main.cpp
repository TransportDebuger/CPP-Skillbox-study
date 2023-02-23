#include <iostream>
#include <cmath>

int main() {
  std::cout << "Ход конём!\n";
  float xAxis, yAxis, xMove, yMove;
  for (bool correctCoord = false; !correctCoord; ) {
    std::cout << "Введите местоположение коня (X): \n";
    std::cin >> xAxis;
    if (xAxis >= 0.f && xAxis <0.8f) {
      correctCoord = true;
    } else {
     std::cout << "Значение лежит за пределами доски! \n";
    }
  }
  for (bool correctCoord = false; !correctCoord; ) {
    std::cout << "Введите местоположение коня (Y): \n";
    std::cin >> yAxis; 
    if (yAxis >= 0.f && yAxis <=0.8f) {
      correctCoord = true;
    } else {
     std::cout << "Значение лежит за пределами доски! \n";
    }
  }

  for (bool correctCoord = false; !correctCoord; ) {
    std::cout << "Координаты точки на доске (X): \n";
    std::cin >> xMove;
    if (xMove >= 0.f && xMove <0.8f) {
      correctCoord = true;
    } else {
     std::cout << "Значение лежит за пределами доски! \n";
    }
  }
  for (bool correctCoord = false; !correctCoord; ) {
    std::cout << "Координаты точки на доске (Y): \n";
    std::cin >> yMove; 
    if (yMove >= 0.f && yMove <=0.8f) {
      correctCoord = true;
    } else {
     std::cout << "Значение лежит за пределами доски! \n";
    }
  }
  std::cout << "Конь в клетке (" << (int) (xAxis*10.f) << ", " << (int) (yAxis*10.f) << ")\n";
  std::cout << "Точка в клетке (" << (int) (xMove*10.f) << ", " << (int) (yMove*10.f) << ")\n";
  if ((std::abs((int) (xAxis*10.f) - (int) (xMove*10.f)) == 2 && (std::abs((int) (yAxis*10.f) - (int) (yMove*10.f)) == 1)) || (std::abs((int) (xAxis*10.f) - (int) (xMove*10.f)) == 1 && (std::abs((int) (yAxis*10.f) - (int) (yMove*10.f)) == 2))) {
    std::cout << "Да, конь может ходить в эту точку.\n";
  } else {
    std::cout << "Нет, конь не может ходить в эту точку.\n";
  }
  
}