#include <iostream>

void evendigit(long long num, int &count) {
  if (num/10!=0) {
    if (num%2 == 0) ++count;
    evendigit(num/10, count);
  }  
}

int main() {
  std::cout << "Even Digits!\n";
  long long number;
  int ans=0;
  std::cout << "Enter number: ";
  std::cin >> number;
  evendigit(number,ans);
  std::cout << "Number of event digits " << ans << std::endl;
}