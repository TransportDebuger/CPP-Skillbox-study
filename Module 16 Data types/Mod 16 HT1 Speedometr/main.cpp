#include <iostream>
#include <string>
#include <cstdio>

int main() {
  std::cout << "Speedometr!\n";

  float speed = 0;
  
  do {
    std::cout << "Set speed delta: ";
    float delta;
    std::cin >> delta;
    speed += delta;
    if (speed > 150) {speed = 150;}
    else if (speed < 0.01f) {speed = 0;} 
    char text[25];
    std:sprintf(text, "Current speed %.1f kmph", speed); 
    std::cout << text << std::endl;
  } while (speed>0);

} 