#include <iostream>

int main() {
  std::cout << "Метеостанция!\n";
  int hiBorder, lowBorder, step;

  std::cout << "Введите значение нижней границы (грд.С): ";
  std::cin >> lowBorder;
  std::cout << "Введите значение верхней границы (грд.С): ";
  std::cin >> hiBorder;
  std::cout << "Введите значение шага шкалы (грд.С): ";
  std::cin >> step;
  std::cout << "\nШкала соответствия (грд.С, грд.F): \n";
  
  do {
    float Fahr = 1.8f * (float) lowBorder + 32.f;
    std::cout << "грд.С: " << lowBorder << " -> грд.F: " << Fahr << "\n";
    if (lowBorder>=hiBorder) {break;}
    lowBorder +=  step; 
  } while (true);
}