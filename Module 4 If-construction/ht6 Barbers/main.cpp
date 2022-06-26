#include <iostream>

using namespace std;

int main() {
  int manPopulation, manPerDay, numberOfBarbers, menToBarbers, barbersNeeds;
  int clientPerHour = 2;
  int workTime = 8;
  int numberOfVisitPerMonth = 1;

  cout << "Сколько мужчин проживает в городе: ";
  cin >> manPopulation;
  cout << "Сколько барберов работает в барбершопах: ";
  cin >> numberOfBarbers;
  manPerDay = manPopulation/(30*numberOfVisitPerMonth);
  if (manPopulation%(30*numberOfVisitPerMonth) != 0)
  { 
    manPerDay += 1;
  }
  menToBarbers = clientPerHour * workTime * numberOfBarbers;
  if (menToBarbers >=manPerDay)
  {
    cout << "Барберов достаточно!\n";
  } else 
  {
    barbersNeeds = manPerDay / workTime;
    if (manPerDay % workTime != 0) { barbersNeeds += 1;}
    barbersNeeds /= clientPerHour;
    if (barbersNeeds % clientPerHour != 0)
    { barbersNeeds += 1; }
    numberOfBarbers = barbersNeeds - numberOfBarbers;
    cout << "Увы. Но Вам нехватает еще "  << numberOfBarbers << " барберов.\n";
  }
}
