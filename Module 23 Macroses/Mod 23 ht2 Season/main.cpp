#include <iostream>
#define WINTER 0
#define SPRING 1
#define SUMMER 2
#define AUTUMN 3
#define CUR_SEASON SUMMER

int main() {
#if CUR_SEASON == WINTER 
  std::cout << "winter" << std::endl;
#elif CUR_SEASON == SPRING 
  std::cout << "spring" << std::endl;
#elif CUR_SEASON == SUMMER 
  std::cout << "summer" << std::endl;
#elif CUR_SEASON == AUTUMN
  std::cout << "autumn" << std::endl;
#else
  std::cout << "undefined" << std::endl;
#endif
  }