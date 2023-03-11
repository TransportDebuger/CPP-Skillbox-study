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
  
  std::vector<int> robots = {};
  int num = 0;
  while (num!=-1) {
    std::cout << "Enter your number: ";
    std::cin >> num;
    if (num != -1) {
      robots = add(robots, num);
    }
  }

  for (int i=0; i < robots.size(); i++) {
    std::cout << robots[i] << " ";
  }
  std::cout << std::endl;
}