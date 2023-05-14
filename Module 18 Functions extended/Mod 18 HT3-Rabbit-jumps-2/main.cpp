#include <iostream>

int waysnum(int sl, int mj =3) {
  int wc = 0;
  if (sl==0) {
    return wc;
  } else
    for (int i=1; i<=std::min(sl,mj); i++) {
        if (sl-i == 0) {wc++;} 
else {wc += waysnum(sl-i);
  } }
    return wc;
  }

int main() {
  std::cout << "Rabbit jumps 1!\n";
  int steplevel=0;
  int max_jump = 0;
  int wayscount=0;
  std::cout << "Enter number of steps on stairway: ";
  std::cin >> steplevel;
  std::cout << "Enter max length of rabbit jump: ";
  std::cin >> max_jump;
  std::cout << "Number of jamping ways - " << waysnum(steplevel, max_jump);

  }