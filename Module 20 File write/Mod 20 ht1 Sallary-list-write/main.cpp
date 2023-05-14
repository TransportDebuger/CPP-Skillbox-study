#include <iostream>
#include <fstream>

using namespace std;

int main() {
  cout << "Sallary list write!\n";
  const string fileName = "list.txt";
  bool isAdd = true;
  while (isAdd) {
    {
      ifstream sallaryList;
      sallaryList.open(fileName);
      if (sallaryList.is_open()) {
        string firstName, lastName;
        int total = 0;
        while (!sallaryList.eof()) {
          string fnBuffer, lnBuffer, date;
          int sallary;
          sallaryList >> fnBuffer >> lnBuffer >> sallary >> date;
          cout << fnBuffer << " " << lnBuffer << " " << sallary << " " << date << std::endl;
          total += sallary;
        }
        cout << "Total: " << total << std::endl;
      }
      sallaryList.close();
    }
    cout << "Are you want to add one more record? (y/n):";
    char answer;
    cin >> answer;
    if (answer=='y') {
      ofstream sallaryList;
      sallaryList.open(fileName, ios::ate|ios::app);
      if (sallaryList.is_open()) {
        string ans;
        cout << "Enter first name: ";
        cin >> ans;
        sallaryList << endl << ans << " ";
        cout << "Enter last name: ";
        cin >> ans;
        sallaryList << ans << " ";
        cout << "Enter payment: ";
        int answerInt;
        cin >> answerInt;
        sallaryList << answerInt << " ";
        cout << "Enter day: ";
        cin >> answerInt;
        sallaryList << answerInt<< ".";
        cout << "Enter month: ";
        cin >> answerInt;
        sallaryList << answerInt << ".";
        cout << "Enter year: ";
        cin >> answerInt;
        sallaryList << answerInt;
      }
      sallaryList.close();
    } else {
      isAdd = false; 
    }
  }
}