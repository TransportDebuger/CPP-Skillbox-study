#include <iostream>
#include <fstream>
#include <sstream>

int main() {
  std::cout << "What? Where? When?\n";
  bool inGameSectors[] = {true, true, true, true, true, true, true, true, true, true, true, true, true};
  int sectorIndex=0, playedSectorsCount=0, playerResult=0, viewerResult=0;
  std::cout << "Let's start the game!\n";
  while (playerResult<6 && viewerResult<6) {
    std::cout << "====== Turn " << playedSectorsCount+1 << " =======\n";
    std::cout << "Current score: player - " << playerResult << "  tv viewer - " << viewerResult << std::endl;
    std::cout << "Spin top (set offset): ";
    int offset;
    std::cin >> offset;
    sectorIndex += offset;
    //выбираем игровой сектор
    bool isChoosedSector = false;
    while (!isChoosedSector) {
      if (sectorIndex>12) {
        sectorIndex -= 13;
      } else if (sectorIndex<0) {
        sectorIndex += 13;
      } else {
        if (inGameSectors[sectorIndex]) {
          isChoosedSector=true;
        } else {
          sectorIndex++;
        }
      }
    }
    std::cout << "Sector in game - " << sectorIndex << std::endl << std::endl;
    
    std::stringstream fileNameBuffer;
    fileNameBuffer << "q" << sectorIndex << ".txt";
    std::string fileName;
    fileNameBuffer >> fileName;
    std::ifstream questFile;
    questFile.open(fileName, std::ios::binary);
    if (questFile.is_open()) {
      questFile.seekg(0, questFile.end);
      int length = questFile.tellg();
      questFile.seekg(0, questFile.beg);
      char buffer[length];
      questFile.read(buffer, length);
      std::cout << buffer << "\n";
    } else {
      std::cout << "Question file not found!\n" ;
      questFile.close();
      break;
    }
    questFile.close();
    
    std::cout << "Your answer: ";
    std::string answer;
    std::cin >> answer;
    fileNameBuffer.clear();
    std::ifstream answFile;
    fileNameBuffer << "a" <<sectorIndex << ".txt";
    fileNameBuffer >> fileName;
    answFile.open(fileName);
    if (answFile.is_open()) {
      std::string ansCheck;
      answFile >> ansCheck;
      if (ansCheck==answer) {
        playerResult++;
      } else {
        viewerResult++;
      }
    } else {
      std::cout << "Answer file not found!";
      answFile.close();
      break;
    }
    answFile.close();
    fileNameBuffer.clear();
    inGameSectors[sectorIndex] = false;
    playedSectorsCount++;
  }
  std::cout << "====== Game over! =======\n";
  std::cout << "Final score: player - " << playerResult << ", TV viewer - " << viewerResult << std::endl;
  if (playerResult==6) {
    std::cout << "Player WIN!\n";
  } else {
    std::cout << "TV viewers WIN!\n";
  }
}