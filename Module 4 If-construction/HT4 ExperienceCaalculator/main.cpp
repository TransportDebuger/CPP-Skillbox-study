#include <iostream>

using namespace std;

int main() {
  int experience;

  cout << "Посмотрим какого уровня достиг Ваш персонаж!\n";
  cout << "Введите количество очков опыта: ";
  cin >> experience;
  if (experience >= 5000)
  { cout << "Вы достигли 4 уровня. Высшее достижение в этой игре!\n"; }
  else if (experience >= 2500)
  {  cout << "Вы достиги 3 уровня. Неплохо!\n";}
  else if (experience >= 1000)
  { cout << "Вы достиги 2 уровня. Продолжайте в том же духе!\n"; }
  else { cout << "Вы в начале пути. Уровень персонажа 1.\n"; }
}