#include <iostream>

using namespace std;

int main() {
  float carSpeed, timeArrival, distance;

  cout << "Расстояние до Рязани 200 км.\n";
  cout << "Введите скорость движения автомобиля (км/ч): ";
  cin >> carSpeed;
  distance = carSpeed*2;
  if (distance >= 200)
  { cout << "Вы приехали!\n"; }
  else if (distance == 0)
  { cout << "Может поедем!\n";}
  else if (distance < 0)
  { cout << "Двигаетесь задом в другую сторону!\n";}
  else
  {
    cout<< "Расстоние которое вы проедете за 2 часа - "<< distance << " км.\n";
  }
}