#include <iostream>
#include <vector>

void swap(int &n1, int &n2) {
  int buff = n1;
  n1 = n2;
  n2 = buff;
}

void swapvec(std::vector<int> &va, int* par) {
  for (int i=0; i<va.size(); i++) swap(va[i], *(par+i));
}

int main() {
  std::cout << "Swap vector!\n";

  std::vector<int> vec={1,2,3,4};
  int arr[]={2,4,6,8};

  swapvec(vec, arr);
  for(int i = 0; i < vec.size(); ++i)
    std::cout << vec[i];
  std::cout << std::endl;
  for(int i = 0; i < sizeof(arr)/sizeof(arr[0]); ++i)
    std::cout << arr[i];
  std::cout << std::endl;


}