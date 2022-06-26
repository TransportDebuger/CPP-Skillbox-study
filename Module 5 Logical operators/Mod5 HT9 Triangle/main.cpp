#include <iostream>

int main() {
  int firstPointX, firstPointY;
  int secondPointX, secondPointY;
  int thirdPointX, thirdPointY;
  
  std::cout << "Введите координаты точки 1 (X Y)";
  std::cin >> firstPointX >> firstPointY;
  std::cout << "Введите координаты точки 2 (X Y)";
  std::cin >> secondPointX >> secondPointY;
  std::cout << "Введите координаты точки 3 (X Y)";
  std::cin >> thirdPointX >> thirdPointY;
   
if ((firstPointX - secondPointX)*(secondPointY - thirdPointY) == (secondPointX - thirdPointX)*(firstPointY - secondPointY))
{
  std::cout << "No!";
} else {
  std::cout << "Yes!";
}
  /*  if (firstPointY - secondPointY != 0 && secondPointY - thirdPointY !=0) {
       if ((firstPointX - secondPointX)/(firstPointY - secondPointY) == (secondPointX - thirdPointX)/(secondPointY - thirdPointY)) {
         std::cout << "No!";
       } else {std::cout << "Yes!";}; 
    } else if (firstPointY - thirdPointY != 0 && secondPointY - thirdPointY !=0) {
      if ((firstPointX - thirdPointX)/(firstPointY - thirdPointY) == (secondPointX - thirdPointX)/(secondPointY - thirdPointY)) {
         std::cout << "No!";
       } else {std::cout << "Yes!";};
    } else if (firstPointY - thirdPointY != 0 && secondPointY - firstPointY !=0) {
      if ((firstPointX - thirdPointX)/(firstPointY - thirdPointY) == (secondPointX - firstPointX)/(secondPointY - firstPointY)) {
         std::cout << "No!";
       } else {std::cout << "Yes!";};
    } else {std::cout << "No!";} ; */  
  
  }
