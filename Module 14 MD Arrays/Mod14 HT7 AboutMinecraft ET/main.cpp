#include <iostream>

void initMatrix(int arr[5][5])
{
  for (int i=0; i<5; i++) 
  {
    for (int j=0; j<5; j++) {
      bool correct=false;
      do {
        std::cout << "Height of volume [" << i+1 <<"][" << j+1 << "]:";
        std::cin >> arr[i][j];
        if (arr[i][j] < 0 || arr[i][j]>10){
          std::cout << "Wrong input. Number must be in range more or equal 0 and less or equal 10\n";
        } else {
          correct=true;
        }
      } while (!correct);
    }
  }
}

void printMatrix(int arr[5][5], int level) {
  for (int i=0; i<5; i++) 
  {
    std::string line1, line2, line3;

    for (int j=0; j<5; j++) {
      if (arr[i][j]<level) {
        line1 += "   ";
        line2 += "   ";
        line3 += "   ";
      } else {
        line1 += "---";
        line2 += "| |";
        line3 += "---";
      }
    }
    std::cout << line1 << std::endl;
    std::cout << line2 << std::endl;
    std::cout << line3 << std::endl;
  }
}

int main() {
  std::cout << "About MineCraft!\n";
  
  int volume[5][5];
  int level=0;
  char nextAction='Y';
  initMatrix(volume);
  do {
  std::cout << "What level are You want to visualize: ";
  std::cin >> level;
  std::cout << std::endl;
  printMatrix(volume, level);
  std::cout << "Do You want to print another level? (Y - YES, any other - NO): ";
  std::cin >> nextAction; 
  } while (nextAction=='Y');
} 