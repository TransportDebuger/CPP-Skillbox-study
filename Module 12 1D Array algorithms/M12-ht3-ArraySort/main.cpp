#include <iostream>

int main() {
  std::cout << "Sorting!\n";

  float numbers[15];

  std::cout << "Input 15 float numbers" << std::endl;
  for (int i=0; i<15; i++) {
    std::cin >> numbers[i];
  }
  
  for (int lag = sizeof(numbers)/sizeof(numbers[0])/1.24f; lag>0; --lag) {
    for (int i=0; i+lag<15; ++i) {
      if (numbers[i]>numbers[i+lag]) {
        numbers[i] += numbers[i+lag];
        numbers[i+lag] = numbers[i] - numbers[i+lag];
        numbers[i] -= numbers[i+lag];
      } 
    }
  }
  
  std::cout << "Sorted array: ";
  for (int i=0; i<15; ++i) {
    std::cout << numbers[i] << " ";
  }
  std::cout << std::endl;
}