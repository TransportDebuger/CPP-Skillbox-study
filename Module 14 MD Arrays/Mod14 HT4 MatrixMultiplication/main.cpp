#include <iostream>

int main() {
  std::cout << "Matrix Multiplication!\n";

  float MatrixA[4][4],MatrixB[4], MatrixR[4][4];

  std::cout << "Enter matrix A values!\n";
  for (int i=0; i<4; i++) 
  {
    for (int j=0; j<4; j++) {
      std::cin >> MatrixA[i][j];
    }
  }
//Выводим полученную матрицу на экран.
  for (int i=0; i<4; i++) 
  {
    for (int j=0; j<4; j++) {
      std::cout << MatrixA[i][j] << "  ";
    }
    std::cout << std::endl;
  }

  std::cout << "Enter matrix B values!\n";
  for (int j=0; j<4; j++) {
      std::cin >> MatrixB[j];
  }
  
  for (int j=0; j<4; j++) {
      std::cout << MatrixB[j] << " ";
  }
  std::cout << std::endl;
//Перемножаем  
  for (int i=0; i<4; i++) {
    float elementR = 0;
    for (int j=0; j<4; j++) {
      elementR += MatrixB[i]*MatrixA[i][j];
    }
    MatrixB[i] = elementR;
  }
   std::cout << "Result vector is:\n";
  for (int j=0; j<4; j++) {
      std::cout << " | " << MatrixB[j] << " | \n";
  }
  std::cout << std::endl;

} 