#include <iostream>
#include <vector>

int main() {
  std::cout << "Find Indexes!\n";
  std::vector<int> digits = {-2,1,-3,4,-1, 2,1,-5,4};
  int leftIndex=0, rightIndex=0, leftPIndex=0;
  int maxSum=digits[0], preSum=digits[0];

  for (int i=1; i<digits.size(); i++) {
    preSum += digits[i];
    if (preSum < digits[i]) {
      preSum=digits[i];
      leftPIndex = i;
    }

    if (maxSum < preSum) {
      maxSum = preSum;
      leftIndex = leftPIndex;
      rightIndex = i;
    }
  }
  
  std::cout << "Max sum: "<< maxSum << " Left index: " << leftIndex << " Right index: " << rightIndex << std::endl;

} 