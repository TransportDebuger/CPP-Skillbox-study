#include <iostream>
#include <fstream>

int main() {
  std::cout << "File reader!\n";
  std::string fileName;
  std::ifstream textFile;
  std::cout << "Enter file name: ";
  std::getline(std::cin, fileName);
  textFile.open(fileName, std::ios::binary);
  if (textFile.is_open()) {
    std::cout << "\n----File content------\n\n";
    //textFile.seekg(0, textFile.end);
    const int bufferSize = 1024;
    int position = textFile.tellg();
    while (!textFile.eof()) {
      char buffer[bufferSize];
      textFile.read(buffer, bufferSize);
      std::string s(buffer, textFile.gcount());
      std::cout << s;
    }
    std::cout << "\n\n----End file content------\n";
  } else {
    std::cout << "File not found!\n";
  }
  textFile.close();
}