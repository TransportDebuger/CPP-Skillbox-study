#include <iostream>
#include <ctime>
#include <fstream>
#include <sstream>

using namespace std;

const short int CASE=6;
const short int BNCOUNT=1000;

enum nominals {
  BN100 = 0,
  BN200,
  BN500,
  BN1000,
  BN2000,
  BN5000
};

bool readATMState(string sFilePath, int* pStorArr) {
  bool err = true;
  ifstream sFile;
  sFile.open(sFilePath, ios::binary);
  if (!sFile) {
    err=false;
  } else {
    for (unsigned short int caseIndex=0; caseIndex<CASE; caseIndex++) {
      int sum;
      sFile.read((char*)&sum, sizeof(int));
      *(pStorArr+caseIndex) = sum;
    }
    err=true;
  }
  sFile.close();
  return err;
}

void saveATMState(string sFilePath, int StorArr[]) {
  ofstream sFile;
  sFile.open(sFilePath, ios::binary);
  if (!sFile) {
    cout << "Can't save storage state.\n";
  } else {
    for (unsigned short int caseIndex = 0; caseIndex<CASE; caseIndex++){
      sFile.write((char*)&StorArr[caseIndex], sizeof(int));
    }
  }
  sFile.close();
}

void fillATM(int* pStorArr, int maxLoad, int startIndex=0) {
  for (unsigned short int bCounter=startIndex; bCounter<maxLoad; bCounter++) {
      int banknote = rand() % 6;
      *(pStorArr+banknote)+=1;
    }
}

int main() {
  
  cout << "ATM (file generation!)\n";
  const string storageFile = "storage.bin";
  int storage[CASE];
  for (unsigned short int i=0; i<CASE; i++) {storage[i]=0;}
  if (!readATMState(storageFile, storage)) {
    //Если файл банкомата не обнаружен, то делаем первичную инициализацию.
    cout << "ATM have not initialized yet. Please wait for loading money.\n";
    std::srand(std::time(nullptr));
    fillATM(storage, BNCOUNT);
    saveATMState(storageFile, storage);
  } else {
    cout << "ATM loaded with next nominal of banknotes: ";
    for (unsigned short int i=0; i<CASE; i++) {
      if (storage[i]!=0) {
        switch (i) {
          case BN100: {cout << "100 "; break;}
          case BN200: {cout << "200 "; break;}
          case BN500: {cout << "500 "; break;}
          case BN1000: {cout << "1000 "; break;}
          case BN2000: {cout << "2000 "; break;}
          case BN5000: {cout << "5000 "; break;}
        }
      }
    }
    cout << endl;
    cout << "(+) Fill money storage\n";
    cout << "(-) Withdraw money\n";
    char operation;
    while (operation != '+' and operation != '-') {
      cout << "Choose operation: "; 
      cin >> operation;
    }
    if (operation == '+') {
      //Заполняем банкомат
      short int numberOfBN=0;
      for (unsigned short int caseIndex=0; caseIndex<CASE; caseIndex++) {
        numberOfBN += storage[caseIndex];
      }
      if (numberOfBN<BNCOUNT) {
        fillATM(storage, BNCOUNT, numberOfBN-1);
        saveATMState(storageFile, storage);
        cout << "Money loaded.\n";
      } else {
        cout << "ATM is full.\n";
      }
    } else {
      //Снимаем денежку.
      cout << "Withdrawed sum of money must be a multiple of 100!\n";
      int sumMoney=0;
      while (sumMoney == 0 or sumMoney % 100 != 0) {
        cout << "How much money you want to withdraw?: ";
        cin >> sumMoney;
      }
      
      int bn=CASE-1;
      stringstream textBuffer;
      
      while (bn >= 0) {
        int bnamount;
         
        switch (bn) {
          case BN5000: {
            bnamount = sumMoney / 5000;
            if (bnamount<=storage[bn] and storage[bn]!=0) {
              storage[bn] -= bnamount;
              textBuffer << " 5000-" << bnamount;
            } else if (bnamount>storage[bn]) {
              bnamount = storage[bn];
              storage[bn] -= bnamount;
              textBuffer << " 5000-" << bnamount;
            }
            sumMoney -= (bnamount * 5000);
            break;
          }
          case BN2000: {
            bnamount = sumMoney / 2000;
            if (bnamount<=storage[bn] and storage[bn]!=0) {
              storage[bn] -= bnamount;
              textBuffer << " 2000-" << bnamount;
            } else if (bnamount>storage[bn]) {
              bnamount = storage[bn];
              storage[bn] -= bnamount;
              textBuffer<< " 2000-" << bnamount;
            }
            sumMoney -= (bnamount * 2000);
            break;
          }
          case BN1000: {
            bnamount = sumMoney / 1000;
            if (bnamount<=storage[bn] and storage[bn]!=0) {
              storage[bn] -= bnamount;
              textBuffer << " 1000-" << bnamount;
            } else if (bnamount>storage[bn]) {
              bnamount = storage[bn];
              storage[bn] -= bnamount;
              textBuffer << " 1000-" << bnamount;
            }
            sumMoney -= (bnamount * 1000);
            break;
          }
          case BN500: {
            bnamount = sumMoney / 500;
            if (bnamount<=storage[bn] and storage[bn]!=0) {
              storage[bn] -= bnamount;
              textBuffer << " 500-" << bnamount;
            } else if (bnamount>storage[bn]) {
              bnamount = storage[bn];
              storage[bn] -= bnamount;
              textBuffer << " 500-" << bnamount;
            }
            sumMoney -= (bnamount * 500);
            break;
          }
          case BN200: {
            bnamount = sumMoney / 200;
            if (bnamount<=storage[bn] and storage[bn]!=0) {
              storage[bn] -= bnamount;
              textBuffer << " 200-" << bnamount;
            } else if (bnamount>storage[bn]) {
              bnamount = storage[bn];
              storage[bn] -= bnamount;
              textBuffer << " 200-" << bnamount;
            }
            sumMoney -= (bnamount * 200);
            break;
          }
          case BN100: {
            bnamount = sumMoney / 100;
            if (bnamount<=storage[bn] and storage[bn]!=0) {
              storage[bn] -= bnamount;
              textBuffer << " 100-" << bnamount;
            } else if (bnamount>storage[bn]) {
              bnamount = storage[bn];
              storage[bn] -= bnamount;
              textBuffer << " 100-" << bnamount;
            }
            sumMoney -= (bnamount * 100);
            break;
          }
        }
        bn--;
      }
      if (sumMoney !=0) {
        cout << "Can't get you this sum of money. Try another sum.\n";
      } else {
        cout << "You have got next number of banknotes (nominal - amount): ";
        cout << textBuffer.str();
        saveATMState(storageFile, storage);
      }
    }
  }
}
