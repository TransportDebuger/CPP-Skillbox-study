#include <iostream>
#include <vector>

int main() {
  std::cout << "Find pair!\n";

  std::vector<int> digits = {2, 11, 15, 7};
  int result = 9;
  bool isFind = false;


  for (int i=0; i<digits.size()-1; i++) {
    for (int j=i+1; i<digits.size(); j++) {
      if (digits[i]+digits[j] == result) {
        isFind=true;
        std::cout << "Result can be found with values placed in: \n";
        std::cout << "Index " << i << " with value " << digits[i] << " and index " << j << " with value " << digits[j] << ".\n";
        break;
      }
    }
    if (isFind) {break;}
  } 
} 