#include <iostream>
using namespace std;

void printArray(int* arr, int count=0) {
  for (int* p=arr, i=0; p<arr+count; p++, i++) {
    cout << "num[" << i << "] address=" << p << " value=" << *p << endl;
  }
  cout << endl;
}

void mirrorArray(int* arr, int count=0) {
  for (int i=0; i<count/2; i++) {
    int c =  *(arr+i);
    *(arr+i) = *(arr+(count-1-i));
    *(arr+(count-1-i)) = c;
  }
}

int main() {
  std::cout << "Array by pointer!\n";
  const int n = 10;
  int numbers[n] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 11};
  printArray(numbers, n);
  mirrorArray(numbers, n);
  printArray(numbers, n);
}