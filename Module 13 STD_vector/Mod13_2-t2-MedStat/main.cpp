#include <iostream>
#include <vector>

std::vector<int> add(std::vector<int> vec, int val) {
  std::vector<int> newVec(vec.size()+1);
  
  if (vec.size()!=0) {
    for (int i = 0; i <= vec.size(); i++) {
      newVec[i] = vec[i];
    }
  }
  newVec[vec.size()] = val;

  return newVec;
}

int main() {
  std::cout << "Hello World!\n";
  
  std::vector<int> ages = {};
  int age = 0;
  while (age!=-1) {
    std::cout << "Enter visitor age: ";
    std::cin >> age;
    if (age != -1) {
      ages = add(ages, age);
    }
  }

  int sum = 0;
  for (int i=0; i < ages.size(); i++) {
    sum += ages[i];  
  }
  std::cout << "Average age of visitors: " << sum/ages.size() << std::endl;
  std::cout << "Number of visitors: " << ages.size() << std::endl;
}