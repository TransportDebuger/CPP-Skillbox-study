#include <iostream>

int main() {
  std::cout << "Duplicates search!\n";

  int numbers[] = {114,111, 106, 107, 108, 105, 115,  108, 110, 109, 112, 113, 116, 117, 118};
  int size = sizeof(numbers)/sizeof(numbers[0]);

//BruteForce
  for (int i=0; i < size; ++i) {
    for (int j=i+1; j < size; ++j) {
      if (numbers[i] == numbers[j]) {
        std::cout << "Brute Force. Duplicated value is " << numbers[i] << std::endl;
      }
    }
  }

//sum of elements (only for single duplication)
  int min=numbers[0], sum=0, elsum=0;
  for (int i=0; i<size; i++) {
    if (min > numbers[i]) {min = numbers[i];}
    sum += numbers[i];
  }

  for (int i=0; i<size-1; i++) {
    elsum += (i+min);
  }
  std::cout << "Sum of elements. Duplicated value is " << sum - elsum << std::endl;
}