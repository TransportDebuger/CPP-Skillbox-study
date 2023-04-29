#include <iostream>

bool substr(char *pch1, char *pch2) {
  int i = 0;
  while (*(pch1 + i) != '\0') {
    if (*(pch1 + i) == *(pch2)) {
      bool match = true;
      int j = 1;
      while (*(pch2 + j) != '\0') {
        if (*(pch2 + j) != *(pch1 + i + j) ||
            (*(pch1 + i + j + 1) == '\0' && *(pch2 + j + 1) != '\0')) {
          match = false;
          break;
        }
        j++;
      }
      if (match) {
        return match;
      } else {
        i += j;
      }
    } else {
      i++;
    }
  }
  return false;
}

int main() {
  std::cout << "String pointer!\n";
  char* a = "Hello world";
  char* b = "wor";
  char* c = "banana";

  std::cout << substr(a, b) << " " << substr(a, c) << std::endl;
}