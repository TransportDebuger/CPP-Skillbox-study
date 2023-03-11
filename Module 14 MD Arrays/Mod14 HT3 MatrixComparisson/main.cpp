#include <iostream>

void initMatrix(int arr[4][4])
{
  for (int i=0; i<4; i++) 
  {
    for (int j=0; j<4; j++) {
      std::cin >> arr[i][j];
    }
  }
}

void printMatrix(int arr[4][4]) {
  for (int i=0; i<4; i++) 
  {
    for (int j=0; j<4; j++) {
      std::cout << arr[i][j] << " ";
    }
    std::cout << std::endl;
  }
}

bool matrixComparisson(int arr1[4][4], int arr2[4][4]) {
  for (int i=0; i<4; i++) {
    for (int j=0; j<4; j++) {
      if (arr1[i][j] != arr2[i][j]) {return false;}
    }
  }

  return true;
}

int main() {
  std::cout << "Matrix Comparisson!\n";
  
  int MatrixA[4][4], MatrixB[4][4];
  std::cout << "Enter matrix A values!\n";
  initMatrix(MatrixA);
  std::cout << "Enter matrix B values!\n";
  initMatrix(MatrixB);
  std::cout << "Matrix A\n";
  printMatrix(MatrixA);
  std::cout << "Matrix B\n";
  printMatrix(MatrixB);

  if (!matrixComparisson(MatrixA, MatrixB)) {
    std::cout << "Matrixes aren't equal! :(\n";
  } else {
    std::cout << "Matrixes are equal! :)\n";
  }
} 