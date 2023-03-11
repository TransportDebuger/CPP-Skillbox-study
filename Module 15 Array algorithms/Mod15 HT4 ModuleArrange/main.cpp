#include <iostream>
#include <vector>

int main() {
  std::cout << "Task 4. Range by module.\n";
  //Input test vector.
  std::vector<int> vec = {-100,-50, -5, 1, 10, 15};
  //Output entered vetor to  console
  std::cout << "Entered vector:\n";
  for (int i=0; i<vec.size(); i++) {
    std::cout << vec[i] << " ";
  }
  std::cout << std::endl;

  //Optimized bubble sort for vector.
  for (int i=0; i<vec.size(); i++) {
    bool isSorted = true;
    for (int j=0; j<vec.size()-(i+1); j++) {
      if (abs(vec[j]) > abs(vec[j+1])) {
        int temp;
        isSorted = false;;
        temp = vec[j];
        vec[j] = vec[j+1];
        vec[j+1] = temp;
      }
    }
    if (isSorted) {
      break;
    }
  }

  //Output sorted vector to console
  std::cout << "Sorted vector:\n";
  for (int i=0; i< vec.size(); i++) {
    std::cout << vec[i] << " ";
  }
  std:: cout << std::endl;
  
} 