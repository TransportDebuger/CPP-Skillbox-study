#include <iostream>
#include <fstream>

using namespace std;

struct persRecord {
  string lastName;
  string firstName;
  int sallary;
  string date;
};

void listPersonalRecords(fstream &fileref) {
  int total = 0;
  fileref.seekg(0, fileref.beg);
  cout << "------------------------------------------------------------\n";
  cout << "Sallary list\n";
  cout << "------------------------------------------------------------\n";
  while (!fileref.eof()) {
    persRecord rec;
    fileref >> rec.lastName >> rec.firstName >> rec.sallary >> rec.date;
    total +=rec.sallary;
    cout << rec.lastName << " " << rec.firstName << " " << rec.sallary << " " << rec.date << endl;
  }
  cout << "------------------------------------------------------------\n";
  cout << "Total: " << total << endl;
  cout << "------------------------------------------------------------\n";
}

void addNewPersonalRecord(fstream &fileref) {
  persRecord rec;
  fileref.seekg(0, fileref.end);
  cout << "Enter record data with spaces (LName FName Sallary Date): ";
  cin >> rec.lastName >> rec.firstName >> rec.sallary >> rec.date;
  fileref  << endl << rec.lastName << " " << rec.firstName << " " << rec.sallary << " " << rec.date;
}

int main() {
  cout << "Sallary list with structures!\n";
  const string fileName = "list.txt";
  fstream sallaryList;
  sallaryList.open(fileName, fstream::in|fstream::out|fstream::app);  
  if (sallaryList) {
    bool isExit=false;
    while (!isExit) {
      cout << "Available commands: add, list, quit\n";
      string command;
      cin >> command;
      if (command == "add") {
        cout << "Add new record to sallary list.\n";
        addNewPersonalRecord(sallaryList);
      } else if (command == "list") {
        listPersonalRecords(sallaryList);
      } else if (command == "quit") {
        cout << "Bye.\n";
        isExit = true;
      } else {
        cout << "Unrecognized command. Try again.\n";
      }
    }  
  }
  sallaryList.close();
}