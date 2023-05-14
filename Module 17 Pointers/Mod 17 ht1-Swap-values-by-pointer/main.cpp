#include <iostream>
using namespace std;

void swap(int* v1, int* v2) {
  int c;
  c = *v1;
  *v1 = *v2;
  *v2 = c;
};

int main() {
  std::cout << "Swap values by variable pointers!\n";
  int a = 10, b=20;
  cout << "a=" << a << " b=" << b << endl;
  swap(&a, &b);

  cout << "a=" << a << " b=" << b << endl;
  
}