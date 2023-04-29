#include <iostream>
#include <fstream>
using namespace std;

void printBasketFile(string fileName) {
  ifstream basketFile (fileName);
  if (!basketFile) {
    cout << "Basket is empty\n";
  } else {
    int fishCount = 0;
    while (!basketFile.eof()) {
      string  fish;
      basketFile >> fish;
      cout << fish << endl;
      if (fish != "") { 
        fishCount++;
      }
    }
    if (fishCount==0) {
      cout << "Basket is empty\n";
    } else {
      cout << "Tolally you catch " << fishCount << " fishes.\n"; 
    } 
  }
  basketFile.close();
}

void putFishIntoBasket(string fileName, string fish) {
  ofstream basketFile;
  basketFile.open(fileName, ios::ate|ios::app);
  if (!basketFile) {
    cout << "Something wrong with basket file.\n";
  } else {
    basketFile << fish << endl;
  }
  basketFile.close();
}

int main() {
  cout << "Fishing!\n";
  const string riverFileName = "river.txt";
  const string basketFileName = "basket.txt";
  cout << "Are you want to look into your basket? (y-yes): ";
  char answer;
  cin >> answer;
  if (answer=='y') {
    printBasketFile(basketFileName);
  }
  cout << "What fish are you want to catch?: ";
  string targetFish;
  cin >> targetFish;
  ifstream contentFile;
  contentFile.open(riverFileName);
  if (!contentFile) {
    cout << "You are not reach the River.";
  } else {
    cout << "Trying to catch...\n";
    while (!contentFile.eof()) {
      string tryFish;
      contentFile >> tryFish;
      if (tryFish  == targetFish) {
        putFishIntoBasket(basketFileName, tryFish);
      }
    }
  }
  contentFile.close();
  cout << "Look into your basket.\n";
  printBasketFile(basketFileName);
}