#include <iostream>
#include <vector>

int main() {
  std::cout << "Task 2!\n";

  std::vector<float> priceIndex = {2.5, 4.25, 3.0, 10.0};
  std::vector<int> goodsList = {1, 1, 0, 3};
  float sum=0.f;
  
  for (int i=0; i<goodsList.size(); i++) {
    sum += priceIndex[goodsList[i]];
  }
  std:: cout << "Total: " << sum << std::endl;
}