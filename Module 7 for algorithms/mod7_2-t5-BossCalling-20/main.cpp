#include <iostream>

int main() {
  std::string answer;
  int iteration = 0;
  for (bool rightAnswer = false; !rightAnswer; iteration++) {
    std::cout << "Ты сделал свою работу?\n";
    std::getline(std::cin, answer);
    rightAnswer = answer == "Да, конечно, сделал."; 
  }
  
  std::cout << "Хорошо! ";
  if (iteration > 1) std::cout << "И почему об этом нужно было спрашивать " << iteration << " раз?"; 
}