#include <iostream>
#include <vector>

int main() {
  std::cout << "Task 3.\n";
  std::cout << "Enter positive values into array. For sorted print enter -1 or -2 for exit.\n";
  std::vector<int> digits;
  int val, count = 1;
  
  do {
    std::cout << "Enter integer value (value " << count << "):";
    std::cin >> val;
    if (val>=0) {
      digits.push_back(val);
      count++;
    } else if (val==-1) {
      
      if (digits.size()>=5) {
        for (int i=0; i<digits.size(); i++) {
          bool isSorted = true;
          for (int j=0; j<digits.size()-(i+1); j++) {
            if (digits[j]>digits[j+1]) {
              isSorted=false;
              int temp = digits[j];
              digits[j] = digits[j+1];
              digits[j+1]=temp;
            }
          }
          if (isSorted) {
            break;
          }
        }
        std::cout << "The fifth vector element is: " << digits[4] << std::endl;
      } else {
        std::cout << "Vector is empty or contain less than 5 values.\n";
      }

    }
  } while (val!=-2);
  



} 