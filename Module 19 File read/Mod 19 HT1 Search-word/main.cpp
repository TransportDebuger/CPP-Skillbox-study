#include <iostream>
#include <fstream>

//Вариация на тему.  Поиск слов с точным соответствием паттерну.
//Без  поиска подстроки. Не учитывает наличие знаков препинания после слова.
//Соответственно такие слова в поиске не учитываются.
int main() {
  std::cout << "Word search in file !\n";
  const std::string fileName = "words.txt";
  
  std::string wordPattern;
  std::cout << "Enter word for search: ";
  std::cin >> wordPattern;
  
  std::ifstream textFile;
  textFile.open(fileName);
  int wordsCount = 0;
  if (textFile) {
    while (!textFile.eof()) {
      std::string textLine;
      textFile >> textLine;
      if (textLine == wordPattern) wordsCount++;
    }
    textFile.close();  
  } else {
    std::cout << "File " << fileName << " not found\n";
  }
  
  
  
  std::cout << "Number of searching words: " << wordsCount << std::endl;
}