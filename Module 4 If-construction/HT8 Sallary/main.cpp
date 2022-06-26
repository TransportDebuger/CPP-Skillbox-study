#include <iostream>

using namespace std;

int main() {
  int firstPersonSallary, secondPersonSallary, thirdPersonSallary;

  cout << "Зарплата сотрудника 1: ";
  cin >> firstPersonSallary;
  cout << "Зарплата сотрудника 2: ";
  cin >> secondPersonSallary;
  cout << "Зарплата сотрудника 3: ";
  cin >> thirdPersonSallary;
  cout <<"---------------------------\n";
  cout << "Средняя зарплата составляет " << (firstPersonSallary + secondPersonSallary + thirdPersonSallary) / 3 << "\n";
  if (firstPersonSallary >= secondPersonSallary)
  {
    if (secondPersonSallary >= thirdPersonSallary)
    {
      cout << "Разница между максимальной и минимальной зарплатой составляет " << (firstPersonSallary - thirdPersonSallary) << "\n";
    } else 
    {
      if (firstPersonSallary >= thirdPersonSallary)
      {
        cout << "Разница между максимальной и минимальной зарплатой составляет " << (firstPersonSallary - secondPersonSallary) << "\n";
      }
      else
      {
        cout << "Разница между максимальной и минимальной зарплатой составляет " << (thirdPersonSallary - secondPersonSallary) << "\n";
      }
    }
  }
  else 
  {
    if (firstPersonSallary >= thirdPersonSallary)
    {
      cout << "Разница между максимальной и минимальной зарплатой составляет " << (secondPersonSallary - thirdPersonSallary) << "\n";
    }
    else
    {
      if (thirdPersonSallary < firstPersonSallary)
      {
        cout << "Разница между максимальной и минимальной зарплатой составляет " << (secondPersonSallary - firstPersonSallary) << "\n";
      }
      else
      {
        cout << "Разница между максимальной и минимальной зарплатой составляет " << (thirdPersonSallary - firstPersonSallary) << "\n";
      }
    }
  }
  
}