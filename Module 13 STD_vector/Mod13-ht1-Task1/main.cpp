#include <iostream>
#include <vector>

std::vector<int> pop_pos(std::vector<int> vec, int pos) {
  for (int i=pos; i<vec.size(); i++) {
    vec[i] = vec[i+1];
  }
  vec.resize(vec.size()-1);
  return vec;
}

void print(std::vector<int> vec){
  for (int i=0; i<vec.size(); i++) {
    std::cout << vec[i] << " ";
  }
  std::cout << std::endl;
}

int main() {
  std::cout << "Task 1!\n";

  int num;

  std::cout << "Enter number of elements: ";
  std::cin >> num;

  std::vector<int> numbers;

  for (int i=0; i<num; i++) {
    int val;
    std::cout << "Enter number #" << i+1 << ": ";
    std::cin >> val;
    numbers.resize(numbers.size()+1);
    numbers[i] = val;
  } 

  print(numbers);

  int delVal, count=0;
  std::cout << "What value will be deleted from vector: ";
  std::cin >> delVal;
  while (count<numbers.size()) {
    if (numbers[count] != delVal) {
      count++;
    } else {
      numbers = pop_pos(numbers, count);
    }
  }

  print(numbers);
}