#include <iostream>
using namespace std;


int main() {
  cout << "Треугольник Паскаля!\n";
  int lines;
  cout << "Введите число строк (1-13): ";
  cin >> lines;
  if (lines < 1 || lines>13) {
    cout << "Такое посчитать не получиться! \n";
  } else {
    for (int lcnt = 0; lcnt < lines; lcnt++) {
      // Заполнение
      for (int i = lines - lcnt; i>0; i--) {
        cout << " ";
      }
      // Вычисляем факториал line
      int lineFactorial = 1;
      for (int i = 1; i < lcnt+1; i++){
        lineFactorial *= i;
      }
      for (int member = 0; member < lcnt+1; member++) {
        //Вычисляем факториал member
        int memberFactorial = 1;
        for (int j = 1; j <= member; j++){
          memberFactorial *=j;
        } 
        //вычисление факторала загнать бы в функцию дабы не повторяться.
        int corrFactorial = 1;
        for (int k=1; k<= (lcnt)-(member); k++) {
          corrFactorial *=k;
        }
        cout << lineFactorial/(memberFactorial*corrFactorial) << " ";
      }
      cout << "\n";
    }
  }
}