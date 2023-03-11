#include <iostream>
#include <string>

using namespace std;

int main() {
  cout << "Appartment House!\n";

  string lastnames[10];

  for (int i=0; i<10; ++i) {
    cout << "Input lastname for appartment #" << i+1 << " occupier: ";
    cin >> lastnames[i];
  }
  
  bool check = true;
  int index;
  char approval; 
  do {
    cout << "Input appartment index (1-10)# ";
    cin >> index;
    if (index>=1 && index<=10)
      cout << "Occupier: " << lastnames[index-1] << endl; 
    else {
      cout << "Wrong index! Try again.";
      continue;
    }
    cout << "Do you want to check another? (Y) ";
    cin >> approval;
    if (approval != 'Y' && approval != 'y'  ) {
      check = false;
    }
  } while(check);
}