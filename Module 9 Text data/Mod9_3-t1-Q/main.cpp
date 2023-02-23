#include <iostream>

int main() {
  std::cout << "Ку!\n";
  int chatls;

  std::cout << "Сколько чатлов есть? ";
  std::cin >> chatls;
  float gravicaps = (float) chatls / 2200.0f;
  float kcs = gravicaps * .5f;

  std::cout << "Можно поменять на " << kcs << " КЦ.\n";
  std::cout << "Можно поменять на " << gravicaps << " гравицап.\n";
}