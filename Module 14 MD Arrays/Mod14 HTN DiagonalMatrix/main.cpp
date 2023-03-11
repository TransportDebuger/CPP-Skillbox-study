#include <iostream>
#include <cmath>

void initMatrix(float arr[4][4])
{
  for (int i=0; i<4; i++) 
  {
    for (int j=0; j<4; j++) {
      std::cout << "Element [" << i <<"][" << j << "]:";
      std::cin >> arr[i][j];
    }
  }
}

void printMatrix1(float arr[4][4]) {
  for (int i=0; i<4; i++) 
  {
    for (int j=0; j<4; j++) {
      if (i != j) {
        std::cout << "0 ";
      } else {
        std::cout << arr[i][j] << " ";
      }
    }
    std::cout << std::endl;
  }
}

void printMatrix2(float arr[4][4]) {
  for (int i=0; i<4; i++) 
  {
    for (int j=0; j<4; j++) {
      std::cout << arr[i][j] << " ";
    }
    std::cout << std::endl;
  }
}

void Gauss(float arr[4][4]) {
  
  //Переставляем строки местами, что бы на главной диагонали оказались наибольшие модули чисел.
  for (int col=0; col<4; col++) {
    float a = std::abs(arr[col][col]);
    int index = col;
    for (int raw=index+1; raw<4; raw++) {
      if (std::abs(arr[raw][col])>a) {
        a = arr[raw][col];
        index = raw;
      }
    }
    int r = col;
    for (int i=0; i<4; i++) {
      float buffer;
      buffer = arr[r][i];
        arr[r][i] = arr[index][i];
        arr[index][i] = buffer;
      }
    }
  //Приводим матрицу к верхне-тругольному виду.
   for (int col=0; col<4; col++) {
      for (int i=col+1; i<4; i++) {
        float m = arr[i][col]/arr[col][col];
        for (int j=col; j<4; j++) {
          arr[i][j] -= m * arr[j][col];
        }
      }
   }
   
   for (int i=0; i<4; i++) {
     for (int j=i+1; j<4; j++) {
       arr[i][j] = 0;
     }
   }

    std::cout << "Diagonalized matrix:\n"; 
    printMatrix2(arr);
    std::cout << std::endl;

    
}



int main() {
  std::cout << "Matrix diagonalization! (Gauss method)\n";

  float matrix[4][4];
  std::cout << "Enter matrix values\n";
  initMatrix(matrix);
  std::cout << "Matrix view:\n";
  printMatrix2(matrix);
  std::cout << std::endl;
  std::cout << "Simple method:\n";
  printMatrix1(matrix);
  std::cout << std::endl;
  Gauss(matrix);

} 