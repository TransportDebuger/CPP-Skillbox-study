#include <iostream>
#include <fstream>

int main() {
  std::cout << "Sallary list!\n";
  std::string fileName;
  std::ifstream SLFile;
  std::cout << "Enter file name: ";
  std::getline(std::cin, fileName);
  SLFile.open(fileName);
  if (SLFile.is_open()) {
    std::string firstName, lastName;
    int total = 0, maxSallary = 0;
    while (!SLFile.eof()) {
      std::string fnBuffer, lnBuffer, date;
      int sallary;
      SLFile >> fnBuffer >> lnBuffer >> sallary >> date;
      std::cout << fnBuffer << " " << lnBuffer << " " << sallary << " " << date << std::endl;
      total += sallary;
      if (sallary > maxSallary) {
        firstName = fnBuffer;
        lastName = lnBuffer;
        maxSallary = sallary;
      }
    }
    std::cout << "Total sallary payment: " << total << std::endl;
    std::cout << "Higher salaried employee: " << firstName << " " << lastName << "\n";
  } else {
    std::cout << "File not found!\n";
  }
  SLFile.close();
}