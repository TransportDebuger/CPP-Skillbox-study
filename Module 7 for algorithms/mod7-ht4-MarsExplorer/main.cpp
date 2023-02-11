#include <iostream>
using namespace std;

int main() {
  cout << "Красный марс.\n\n";
  int length, width,xPos, yPos;
  
  cout << "Введите длину помещения (м): ";
  cin >> length;
  cout << "Ведите ширину помещенния (м): ";
  cin >> width;
  xPos = length  / 2;
  yPos = width / 2;
  cout << "Передаем управление оператору!\n";
  for (;true;) {
    cout << "Марсоход находится на позиции " << xPos << ", " << yPos << ", введите команду: ";
    string direction;
    cin >> direction;
    bool xMoveUp = xPos != 0, xMoveDown = xPos != length;
    bool yMoveLeft = yPos != 0, yMoveRight = yPos != width;
    if (direction == "w") {
      if (xMoveUp) --xPos;
    } else if (direction == "s") {
      if (xMoveDown) ++xPos;
    } else if (direction == "a") {
      if (yMoveLeft) --yPos;
    } else if (direction == "d") {
      if (yMoveRight) ++yPos;
    } else {
      cout << "Не понял команду.\n";
    }
  }
}