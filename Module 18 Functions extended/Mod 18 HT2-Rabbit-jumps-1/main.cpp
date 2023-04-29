#include <iostream>

int waysnum(int sl) {
  const int MAX_JUMP = 3;
  int wc = 0;
  if (sl==0) {
    return wc;
  } else
    for (int i=1; i<=std::min(sl,MAX_JUMP); i++) {
        if (sl-i == 0) {wc++;} 
else {wc += waysnum(sl-i);
  } }
    return wc;
  }

int main() {
  std::cout << "Rabbit jumps 1!\n";
  int steplevel=0;
  int wayscount=0;
  std::cout << "Enter number of steps for rabbit jumping: ";
  std::cin >> steplevel;
  std::cout << "Number of jamping ways - " << waysnum(steplevel);

}