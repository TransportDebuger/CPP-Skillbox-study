#include <iostream>
using namespace std;

int main() {
  int heightBamboo;
  cout << "Начальная высота бамбука (см): ";
  cin >> heightBamboo;
  int heightIncrease;
  cout << "Скорость роста бамбука (см в день): ";
  cin >> heightIncrease;
  int heightDecrease;
  cout << "Скорость уничтожения побегов гусеницами бамбука (см за ночь): ";
  cin >> heightDecrease;
  int heightTarget;
  cout << "Целевая высота (см): ";
  cin >> heightTarget;

  int heightBambooNew = heightBamboo + heightIncrease * 2.5 - heightDecrease*2; 
  cout << "Высота бымбука к середине третьего дня " << heightBambooNew << " см.\n";
  int heightDelta = heightTarget - heightBamboo - heightIncrease;
  int raiseSpeed = heightIncrease - heightDecrease;
  int dayBeforeHarvest = heightDelta / raiseSpeed + 1;
  cout << "Количество дней до вырубки: " << dayBeforeHarvest << " \n";
}