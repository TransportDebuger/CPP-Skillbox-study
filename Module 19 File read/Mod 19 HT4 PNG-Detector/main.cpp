#include <iostream>
#include <fstream>

int main() {
  std::cout << "PNG Detector!\n";
  
  std::string fileName;
  std::ifstream pngFile;
  
  std::cout << "Enter file name: ";
  std::getline(std::cin, fileName);
  pngFile.open(fileName, std::ios::binary);
  if (pngFile.is_open()) {
    std::cout << "File opened!\n";
    char buffer[4];
    pngFile.read(buffer, 4);
    if (buffer[0] == -119 && buffer[1]=='P' && buffer[2]=='N' && buffer[3]=='G') {
      std::cout << "Great! This file have PNG format.\n";
    } else {
      std::cout << "Wrong format!\n";
    }
  } else {
    std::cout << "File not found!\n";
  }
  pngFile.close();
}