#include <iostream>
#include <ctime>
#include <fstream>
using namespace std;

int main() {
  cout << "Picture writing!\n";
  int width, height;
  std::srand(std::time(nullptr));
  cout << "Input picture height and width (h w): ";
  cin >> height >> width;
  const string fileName = "picture.txt";
  ofstream pictureFile;
  pictureFile.open(fileName);
  if (pictureFile) {
    for (int hPos=0; hPos<height; hPos++) {
      for (int wPos=0; wPos<width; wPos++) {
        pictureFile << rand() % 2;
      }
      pictureFile << '\n';
    }
  }
  pictureFile.close();
}