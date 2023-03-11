#include <iostream>
#include <vector>

int main() {
  std::cout << "Hello World!\n";
  int num;
  std::cout << "How many elements doy you want to save? ";
  std::cin >> num;

  std::vector<int> vec(num);
  for (int i=0; i<num; i++) {
    std::cout << "Enter #" << i+1 << " number: ";
    std::cin >> vec[i];
  }
  
  float sum=0;
  for (int i=0; i<num; i++) {
    sum += vec[i];
  }

  std::cout << "Average number is " << sum / float (num) << std::endl;

}