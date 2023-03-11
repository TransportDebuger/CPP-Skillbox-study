#include <iostream>

void printBoard(char arr[3][3]) {
  std::cout << "-------" << std::endl;
  for (int i=0; i<3; i++)
  {
    for (int j=0; j<3; j++)
    {
      std::cout << "|" << arr[i][j];
    }
    std::cout << "|" << std::endl << "-------" << std::endl;
  }
}

int analiseGame(char arr[3][3]) {
  //проверяем столбцы
  for (int i=0; i<3; i++){
    if (arr[i][0] == 'X' && arr[i][1] == 'X' && arr[i][2] == 'X')
      {return 1;} else if (arr[i][0] == 'O' && arr[i][1] == 'O' && arr[i][2] == 'O') {return 2;}
  }
  //проверяем строки
  for (int i=0; i<3; i++){
    if (arr[0][i] == 'X' && arr[1][i] == 'X' && arr[2][i] == 'X')
      {return 1;} else if (arr[0][i] == 'O' && arr[1][i] == 'O' && arr[2][i] == 'O') {return 2;}
  }
  //проверяем диагонали
  if ((arr[0][0] == 'X' && arr[1][1] == 'X' && arr[2][2] == 'X') || (arr[2][0] == 'X' && arr[1][1] == 'X' && arr[0][2] == 'X')) {return 1;} 
  else if ((arr[0][0] == 'O' && arr[1][1] == 'O' && arr[2][2] == 'O') || (arr[2][0] == 'X' && arr[1][1] == 'O' && arr[0][2] == 'O')) {return 2;}
  //проверяем поле на заполнение
  for (int i=0; i<3; i++) {
    for (int j=0; j<3; j++) {
      if (arr[i][j]==' ') {return -1;}
    }
  }
  return 0;
}

int main() {
  std::cout << "Cross and Zeroes!\n";
  int result=-1;
  int turnCount = 0;
  //Инициализация поля
  char board[3][3] = {{' ', ' ',' '},
                      {' ', ' ',' '},
                      {' ', ' ',' '}};
  
  std::cout << "Game started!" << std::endl; 
  printBoard(board);
  //погнали циклом смотреть ход за зодом
  do {
    turnCount++;
    std::cout << "Turn number " << turnCount ;
    if (turnCount%2 == 0) 
      {std::cout << " (Player 2)\n";} else 
      {std::cout << " (Player 1)\n";}  
    int row, col;
    bool isEmptyField=false;
    do {
      std::cout << "Enter coordinates (Row Col): ";
      std::cin >> row >> col;
      if (row < 0 || row > 2 || col < 0 || col > 2) {
        std::cout << "Whrong coordinates.  Choose another!\n";
      } else if (board[row][col] == ' ' && turnCount % 2 == 0) {
        board[row][col]='O';
        isEmptyField = true;
      } else if (board[row][col] == ' ' && turnCount%2!=0) {
        board[row][col]='X';
        isEmptyField = true;
      } else {
        std::cout << "This field is not empty. Try another.\n";
      }
    } while (!isEmptyField);
    printBoard(board);
    result = analiseGame(board);
  } while (result == -1);
  //определяем победителя
  if (result == 1) {std::cout << "Player 1 win!\n";}
  else if (result == 2) {std::cout << "Player 2 win!\n";}
  else {std::cout << "No winer.\n";}
} 