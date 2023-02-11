#include <iostream>

int main() {
  std::cout << "Координатные оси!\n";
  int Xlength, Ylength;
  std::cout << "Какой длины нарисовать ось Х: ";
  std::cin >> Xlength;
  std::cout  << "Какой длины нарисовать ось Y: ";
  std::cin >> Ylength;
  if (Ylength<2)
  {
    std::cout << "Длина оси Y слишком короткая для рисования.\n";
  } else if (Xlength<2) {
    std::cout << "Длина оси X слишком короткая для рисования.\n";
  } else {
    for (int linesCount = 0; linesCount < Ylength; linesCount++)
    {
      for(int symbolCount = 0;  symbolCount < Xlength; symbolCount++)
      {
        if (linesCount == 0 && ((symbolCount == Xlength/2-1 && Xlength % 2 == 0) || (symbolCount == Xlength/2 && Xlength % 2 == 1))) {
          std::cout << "^";
        } else if (symbolCount == Xlength-1 && linesCount == Ylength/2) {
          std::cout << ">";
        } else if (((symbolCount == Xlength/2-1 && Xlength % 2 == 0) || (symbolCount == Xlength/2 && Xlength % 2 == 1)) && linesCount != Ylength/2) {
          std::cout << "|";
        } else if (linesCount == Ylength/2 && ((symbolCount == Xlength/2-1 && Xlength % 2 == 0) || (symbolCount == Xlength/2 && Xlength % 2 == 1))) {
          std::cout << "+";
        } else if (linesCount == Ylength/2) {
          std::cout << "-";
        } else {
          std::cout << " ";
        } 
      }
      std::cout << "\n";
    }

  }
}