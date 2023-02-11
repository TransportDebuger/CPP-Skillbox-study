#include <iostream>
using namespace std;

int main() {
  cout << "Это часы c кукушкой.\n";
  cout << "Который час?\n";
  int hours;
  cin >> hours;
  if (hours >= 0 and hours < 13) {
    int cooCoo = 0;
    if (hours == 0) {
      hours = 12;
    }
    while (cooCoo < hours) {
      cout << "Coo! Coo!\n";
      ++cooCoo;
    }
  }
}