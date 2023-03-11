#include <iostream>

//анализируем поле на предмет выйгрыша.
bool analizeField(int arr[10][10]) {
  int decs=0;
  //посчитаем пробитые палубы
  for (int row=0; row<10; row++) {
    for (int col=0; col<10; col++) {
      if (arr[row][col]==3) {
        decs++;
      } 
    }
  }
  //если пробили все, то усе..
  if (decs<20) {return false;} 
  return true;
}

//Вывод поля на экран.
//первая переменная массив, вторая false - выводит карту расстановки кораблей, true - карту обстрела
void printField(int arr1[10][10], bool type) {
  std::cout << "  0 1 2 3 4 5 6 7 8 9\n";
  for (int row=0; row<10; row++) {
    std::string line1 = " |";
    std::string line2 = "|";
    for (int col=0; col<10; col++) {
      line1 += "-|";
      if (!type) {
        if (arr1[row][col]==0) {
          line2 += " |";  
        } else if (arr1[row][col]==2){
          line2 += "+|";
        }
      } else {
        if (arr1[row][col]==1) {
          line2 += "*|";  
        } else if (arr1[row][col]==3){
          line2 += "X|";
        } else {
          line2 += " |";
        }
      }              
    }
    std::cout << line1 << std::endl;
    std::cout << row << line2 << std::endl;
  }
  std::cout << " |-|-|-|-|-|-|-|-|-|-|\n";
}

//Расстановка кораблей на поле!
void initField(int arr[10][10]) {
  //типы кораблей и их количество
  int fourDeck=1, threeDeck=2, twoDeck=3, oneDeck=4;
  // Переменные координат корабля
  int Xb, Xe, Yb, Ye;
  printField(arr, false);
  do {
    std::cout << "Enter ship coordinates (Xb, Yb, Xe, Ye):";
    std::cin >> Xb >> Yb >> Xe >> Ye;
    //проверка и перестановка если переутали корму и нос.
    if (Xe < Xb) { Xb^=Xe^=Xb^=Xe;}
    if (Ye < Yb) { Yb^=Ye^=Yb^=Ye;}
    //если область больше чем 1 клетка по Х и больше чем 1 клетка по У, то ...
    if (Xb != Xe & Yb != Ye || Xe - Xb > 4 || Ye-Yb > 4){
      std::cout << "Unknown ship type. Reenter coordinates.\n";
    } else {
      //проверяем правильность ввода координат...
      if (Xb <0 || Xb>9 || Xe<0 || Xe>9 || Yb <0 || Xb>9 || Xe<0 || Xe>9) {
        std::cout << "Wrong coordinates. Please reenter coordinates.\n";
      } else {
        
        //проверяем коллизии с другими кораблями. Проверяем и смежность.
        bool collision=false;
        int decs=0; 
        for (int xs=Xb-1; xs<=Xe+1; xs++) {
          if (xs>=0 && xs<=9) {
            for (int ys=Yb-1; ys<=Ye+1; ys++) {
              if (ys>=0 && ys<=9) {
                if (arr[xs][ys]!=0) {
                  collision = true; 
                  break;
                } else {
                  if (xs>=Xb && xs<=Xe && ys>=Yb && ys<=Ye) {decs++;}
                }
              }
            }
          }
        }
        if (collision) {
          std::cout << "Your ship collaided with another one. Please reenter coordinates.\n";
        } else {
  // Если все ОК, размещаем корабль.
          bool isPlaced=true;
          //смотрим остались ли корабли данного типа
          if (decs==4 && fourDeck) { fourDeck -= 1;}
          else if (decs==3 && threeDeck) {threeDeck -=1;}
          else if (decs==2 && twoDeck) {twoDeck -=1;}
          else if (decs==1 && oneDeck) {oneDeck -=1;} 
          else {
            std::cout << "This type of ships is over. Please choose another one.\n"; isPlaced=false;}
            //если все ОК, заполняем массив.
          if (isPlaced) {
            for (int xs=Xb; xs<=Xe; xs++) {
              for (int ys=Yb; ys<=Ye; ys++) {
                arr[xs][ys]=2;
              }
            }
          }
          //выведем сводочку по размещению и игровое поле.
          std::cout << "You have next unplaced ships:\n";
          std::cout << "Four-decks ship -  "<< fourDeck << std::endl;
          std::cout << "Three-decks ships -  "<< threeDeck << std::endl;
          std::cout << "Two-decks ships -  "<< twoDeck << std::endl;
          std::cout << "One-deck ships -  "<< oneDeck << std::endl;
          printField(arr, false);
        }
      }
    }
  } while (oneDeck || twoDeck || threeDeck || fourDeck);
  std::cout << "OK. You are ready to play.\n";
}

//собственно выстрел и возврат результата.
int makeShot(int arr[10][10], int X, int Y) {
  //увеличиваем значение поля на 1. Пригодится.
  arr[X][Y] += 1;
  if (arr[X][Y] == 1) { std::cout << "You missed!\n";} else {std::cout << "Good job! \n";}
  return arr[X][Y];
}

int main() {
  std::cout << "Sea Battle!\n";
  //Объявляем поля игроков!
  int field1[10][10] = {{0,0,0,0,0,0,0,0,0,0},
                        {0,0,0,0,0,0,0,0,0,0},
                        {0,0,0,0,0,0,0,0,0,0},
                        {0,0,0,0,0,0,0,0,0,0},
                        {0,0,0,0,0,0,0,0,0,0},
                        {0,0,0,0,0,0,0,0,0,0},
                        {0,0,0,0,0,0,0,0,0,0},
                        {0,0,0,0,0,0,0,0,0,0},
                        {0,0,0,0,0,0,0,0,0,0},
                        {0,0,0,0,0,0,0,0,0,0}}, 
      field2[10][10] = {{0,0,0,0,0,0,0,0,0,0},
                        {0,0,0,0,0,0,0,0,0,0},
                        {0,0,0,0,0,0,0,0,0,0},
                        {0,0,0,0,0,0,0,0,0,0},
                        {0,0,0,0,0,0,0,0,0,0},
                        {0,0,0,0,0,0,0,0,0,0},
                        {0,0,0,0,0,0,0,0,0,0},
                        {0,0,0,0,0,0,0,0,0,0},
                        {0,0,0,0,0,0,0,0,0,0},
                        {0,0,0,0,0,0,0,0,0,0}};
  //для определения игрока которому нужно делать выстрел
  bool player = false;
  //служебная переменная для определения конца игры
  bool endGame = false;
  std::cout << "Player 1, place your ships into battle filed!\n";
  initField(field1);
  //Не мешало бы очистить экран. Надо посмотреть ка это делать.
  std::cout << "Player 2, place your ships into battle filed!\n";
  initField(field2);
  //Не мешало бы очистить экран. Надо посмотреть ка это делать.
  std::cout << "Let's play!\n";
  do {
    int result = 0;
    int Xs, Ys;
    bool isCShot = false;
    //Если false - то ход игрока 1 иначе 2
    if (!player) {
      printField(field2, true);
      std::cout << "Player 1! Make shot!\n";
      do {
        std::cout << "Enter coordinates (X Y):";
        std::cin >> Xs >> Ys;
        //проверим в поле ли попали..
        if (Xs<0 || Xs>9 || Ys<0 || Ys>9) {
          std::cout << "You shot is out of battle field. Try again!\n";
        } 
        //если в поле, то стреляли ли мы уже сюда
        else if (field2[Xs][Ys]%2==1) {
          std::cout << "This point attacked by you. Try another point.\n";
        } else {isCShot = true;}
      } while (!isCShot);
      // Если все проверки прошли получаем результат выстрела.
      result = makeShot(field2, Xs, Ys);
      //анализируем поле, вдруг выйграли.
      if (analizeField(field2)) { 
        endGame = true;
        std::cout << "Congratulations? Player 1! You win!\n";}
      // Если мимо, то меняем игрока 
      else if (result==1) {player=true;} 
      //а иначе ходим еще раз.
    } else {
      //То же для второго игрока.
      printField(field1, true);
      std::cout << "Player 2! Make shot!\n";
      do {
        std::cout << "Enter coordinates (X Y):";
        std::cin >> Xs >> Ys;
        if (Xs<0 || Xs>9 || Ys<0 || Ys>9) {
          std::cout << "You shot is out of battle field. Try again!\n";
        } else if (field1[Xs][Ys]%2==1) {
          std::cout << "This point attacked by you. Try another point.\n";
        }{isCShot = true;}
      } while (!isCShot);
      result = makeShot(field1, Xs, Ys);
      if (analizeField(field1)) { 
        endGame = true;
        std::cout << "Congratulations? Player 2! You win!\n";} else if (result==1) {player=false;}
    }
  } while (!endGame);
} 