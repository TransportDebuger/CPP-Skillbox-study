#include <iostream>
#include <vector>
#include <map>

void printSeating(int arr[2][6][3]) {
  for (int i=0; i<2; i++) {
    std::cout << "Line " << i+1 << ": \n";
    for (int j=0; j<6; j++) {
      std::cout << "Seat " << j+1 << " -> Chairs - " << arr[i][j][0] << " Plates - " 
      << arr[i][j][2] << " Cutlery - " << arr[i][j][1] << std::endl;
    }
  }
}

int main() {
  std::cout << "Dinner!\n\n";
  
  int tableArr[2][6][3];

  //Инициализируем стол
  for (int i=0; i<2; i++) {
    for (int j=0; j<6; j++) {
      tableArr[i][j][0]=1;
      tableArr[i][j][1]=3;
      tableArr[i][j][2]=2;
      if (i==0 && (j==0|| j==1)) {
        tableArr[i][j][1] += 1;
        tableArr[i][j][2] += 1;
      }
    }
  }
  
  std::cout << "Initial seating\n";
  printSeating(tableArr);
  std::cout << std::endl;
  // первое событие;
  tableArr[0][4][0] *= 2;
  std::cout << "First action\n";
  printSeating(tableArr);
  std::cout << std::endl;

  tableArr[1][2][1] -= 1;
  std::cout << "Second action\n";
  printSeating(tableArr);
  std::cout << std::endl;

  
  tableArr[0][1][1] -= 1;
  tableArr[0][1][2] -= 1;
  tableArr[1][2][1] += 1;
  std::cout << "Third action\n";
  printSeating(tableArr);
  std::cout << std::endl;

  std::cout << "Dinner continued without any accidents! :)\n";

}