#include <iostream>

int initPopIt(bool arr[12][12])
{
  int count = 0;
  for (int i=0; i<12; i++) 
  {
    for (int j=0; j<12; j++) {
      arr[i][j]=true;
      count++;
    }
  }

  return count;
}

void PrintPopBand(bool arr[12][12]) {
  for (int i=0; i<12; i++) 
  {
    for (int j=0; j<12; j++) {
      if (!arr[i][j]) {std::cout << "X ";} else {std::cout << "O ";} 
    }
    std::cout  << std::endl;
  } 
}

int popBand(int sX, int sY, int eX, int eY,bool arr[12][12]) {
  int count = 0;
  if (sX > eX) {
    sX^=eX^=sX^=eX;
  }
  if (sY > eY) {
    sY^=eY^=sY^=eY;
  }

  for (int i=sX; i<=eX; i++) {
    for (int j=sY; j<=eY; j++) {
      if (arr[i][j] == true) {
        arr[i][j] = false;
        std::cout << "Pop!\n";
        count++;
      }
    }
  }
  return count;
}

int main() {
  std::cout << "Pop It!\n";
  bool PopBand[12][12];
  int isPoped = initPopIt(PopBand);
  do {
    PrintPopBand(PopBand);
    int sRow, sCol, eRow, eCol;
    do {
      std::cout << "Enter start coordinates of region: ";
      std::cin >> sRow >> sCol;
    } while (sRow<0 || sRow>11 || sCol<0 || sCol>11); 
    do {
      std::cout << "Enter end coordinates of region: ";
      std::cin >> eRow >> eCol;
    } while (eRow<0 || eRow>11 || eCol<0 || eCol>11);
    isPoped = isPoped-popBand(sRow, sCol, eRow, eCol, PopBand);
    if (!isPoped) std::cout << "That's all! :(\n";
  } while (isPoped);
} 