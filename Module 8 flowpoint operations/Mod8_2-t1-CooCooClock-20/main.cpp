#include <iostream>
using namespace std;

int main() {
  cout << "Это часы c кукушкой 2.0\n";
  cout << "Который час?\n";
  int hours;
  cin >> hours;
  if (hours >= 0 and hours < 13) {
    if (hours == 0) hours = 12; 
    for (int cooCoo = 0; cooCoo < hours; cooCoo++) cout << "Coo! Coo!\n"; 
  } else {
    cout << "А так бывает?.";
  }
}