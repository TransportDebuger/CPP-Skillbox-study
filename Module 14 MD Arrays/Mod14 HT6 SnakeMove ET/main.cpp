#include <iostream>
#include <cmath>

int main() {
  std::cout << "Snake Move!\n";
  int count = 0;
  int board[5][5]; //Наш массив
  //Инициализируем змейкой по строкам
  for (int row=0; row<5; row++)
  {
    for (int col=0; col<5; col++)
    {
      board[row][(row%2)?abs(col-5)-1:col] = count;
      count++;
    }
  }

  //Вывод массива
  for (int row=0; row<5; row++)
  {
    for (int col=0; col<5;  col++) std::cout << board[row][col] << " ";
    std::cout << std::endl;
  }
} 