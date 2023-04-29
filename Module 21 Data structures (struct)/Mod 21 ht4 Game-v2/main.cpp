#include <iostream>
#include <string>
#include <vector>
#include <fstream>

//Файл сохранения игры
const std::string fName = "save.bin";
//Количество акторов в игре
const int actorCount = 6;
//Размер поля
const int fieldDim = 40;


//Структура игрового персонажа
struct actor {
    bool type=0; //false - player, true - computer;
    std::string aName;
    int aHp=0,
        aArmor=-1,
        aDamage=0,
        aPosX,
        aPosY;
};

//Очистка экрана для Linux
void clrscr() {
    // std::cout << "\033[2J\033[1;1H";
}

//Конструктор для персонажа
actor createActor(bool aType, std::string aName, int aHp, int aArmor, int aDamage, int aPosX, int aPosY) {
    actor person = {aType, aName, aHp, aArmor, aDamage, aPosX, aPosY};
    return person;
}

//Сохранение данных одного персонажа
void saveActor(std::ofstream& sFile, actor& person) {
  sFile.write((char*)&person.type, sizeof(person.type));
  int len = person.aName.length();
  sFile.write((char*)&len, sizeof(len));
  sFile.write(person.aName.c_str(), len);
  sFile.write((char*)&person.aHp, sizeof(person.aHp));
  sFile.write((char*)&person.aArmor, sizeof(person.aArmor));
  sFile.write((char*)&person.aDamage, sizeof(person.aDamage));
  sFile.write((char*)&person.aPosX, sizeof(person.aPosX));
  sFile.write((char*)&person.aPosY, sizeof (person.aPosY));
}

//Сохраняем игру
void saveGame(std::vector<actor>& actors) {
   std::ofstream saveFile(fName, std::ios::binary);
   if (!saveFile) {
       std::cout << "There are some troubles with saving game!\n";
   } else {
       for (int aCount=0; aCount<actors.size(); aCount++) {
           saveActor(saveFile, actors[aCount]);
       }
   }
   saveFile.close();
}

//Загрузка данных одного персонажа
void loadActor(std::ifstream& sFile, actor& person) {
    sFile.read((char*)&person.type, sizeof(person.type));
    int len;
    sFile.read((char*)&len, sizeof(len));
    person.aName.resize(len);
    sFile.read((char*)person.aName.c_str(), len);
    sFile.read((char*)&person.aHp, sizeof(person.aHp));
    sFile.read((char*)&person.aArmor, sizeof(person.aArmor));
    sFile.read((char*)&person.aDamage, sizeof(person.aDamage));
    sFile.read((char*)&person.aPosX, sizeof(person.aPosX));
    sFile.read((char*)&person.aPosY, sizeof (person.aPosY));
}

bool loadSavedGame(std::vector<actor>& actors) {
  std::ifstream saveFile (fName, std::ios::binary);
  if (!saveFile) {
      saveFile.close();
      return false;
  }
  actors.clear();
  int aCount=0;
  while (aCount<actorCount) {
      actors.resize(actors.size()+1);
      loadActor(saveFile, actors[aCount]);
      aCount++;
  }
  return true;
}

void newGame(std::vector<actor>& actors) {
    actors.clear();
    std::string name;
    bool type;
    int hp, armor, damage, posX, posY;
    for (int aCount=0; aCount<actorCount; aCount++) {
        if (aCount==0) {
            type=false;
            do {
                std::cout << "Enter player name: ";

                std::getline(std::cin, name);
            } while (name.length()==0);
            do {
                std::cout << "Set hitpoints for player (>0): ";
                std::cin >> hp;
            } while (hp<=0);
            do {
                std::cout << "Set armor for player (>=0): ";
                std::cin >> armor;
            } while (armor<0);
            do {
                std::cout << "Enter player damage value (>0): ";
                std::cin >> damage;
            } while (damage<=0);
            do {
                std::cout << "Enter coordinates of spawn (X, Y) (0-" << fieldDim << "): ";
                std::cin >> posX >> posY;
            } while ((posX<0 || posX>fieldDim) || (posY<0 || posY>fieldDim));
        } else {
            type = true;
            name = "Enemy #" + std::to_string(aCount);
            hp = rand()%101+50;
            armor = rand()%51;
            damage = rand()%16+15;
            bool isEmpty;
            do {
                isEmpty = true;
                posX = rand() % fieldDim;
                posY = rand() % fieldDim;
                for (int aCount=0; aCount<actors.size(); aCount++) {
                    if (posX == actors[aCount].aPosX && posY == actors[aCount].aPosY){
                        isEmpty=false;
                        break;
                    }
                }
            } while (!isEmpty);
        }
        actors.push_back(createActor(type, name, hp, armor, damage, posX, posY));
    }
}

void printStat(std::vector<actor>& actors) {
    for (int aCount = 0; aCount<actors.size(); aCount++) {
        std::cout << "Player:    " << actors[aCount].aName << std::endl;
        std::cout << "HP:        " << actors[aCount].aHp << std:: endl;
        std::cout << "Armor:     " << actors[aCount].aArmor << std::endl;
        std::cout << "Damage:    " << actors[aCount].aDamage << std::endl;
        std::cout << "Pos(X, Y): " << actors[aCount].aPosX << " " << actors[aCount].aPosY << std::endl;
    }
}

void takeDamage(actor*& actorCurrent, actor*& actorAttacked) {
    int damage=actorCurrent->aDamage;
    if (actorAttacked->aHp!=0) {
        std::cout << actorCurrent->aName << " took " << damage << " of damage for " << actorAttacked->aName << std::endl;
        actorAttacked->aArmor -= damage;
        if (actorAttacked->aArmor < 0) {
            actorAttacked->aHp += actorAttacked->aArmor;
            actorAttacked->aArmor = 0;
        }
        if (actorAttacked->aHp < 0) actorAttacked->aHp = 0;
    } else {
        std::cout << "Do not touch dead body of " << actorAttacked->aName << std::endl;
    }
}

int main() {
    std::cout << "Field battle!\n";
    //Вектор хранения акторов
    std::vector<actor> actorSet;
    //Проверяем на наличие файла сохранения
    std::ifstream saveFile;
    saveFile.open(fName, std::ios::binary);
    //Проверяем наличие файла сохранения
    if (saveFile) {
        saveFile.close();
        std::cout <<  "Are you want resume saved game? (y-yes, any - n): ";
        std::string answer;
        std::cin >> answer;
        if (answer == "y") {
            loadSavedGame(actorSet);
        } else {
            newGame(actorSet);
        }
    } else {
        saveFile.close();
        newGame(actorSet);
    }
    bool isGameEnd = false;

    do {
        actor *gameField[fieldDim][fieldDim];
        for (int fY=0; fY<fieldDim; fY++) {
            for (int fX=0; fX<fieldDim; fX++) {
                gameField[fX][fY] = nullptr;
            }
        }
        for (int aCount = 0; aCount < actorSet.size(); aCount++) {
            gameField[actorSet[aCount].aPosX][actorSet[aCount].aPosY] = &actorSet[aCount];
        }
        for (int fY = 0; fY < fieldDim; fY++) {
            for (int fX = 0; fX < fieldDim; fX++) {
                if (gameField[fX][fY] == nullptr) {
                    std::cout << ".";
                } else if ((*gameField[fX][fY]).type == true) {
                    if ((*gameField[fX][fY]).aHp <= 0) {
                        std::cout << "X";
                    } else {
                        std::cout << "E";
                    }
                } else if ((*gameField[fX][fY]).type == false) {
                    if ((*gameField[fX][fY]).aHp <= 0) {
                        std::cout << "X";
                    } else {
                        std::cout << "P";
                    }
                }
            }
            std::cout << std::endl;
        }
        std::cout << "For move use: left (l), right (r), up (u), down (d)\n";
        std::cout << "Show players - show, Save game - save, load game - load, exit game - quit\n";
        std::cout << "command> ";
        std::string command;
        std::cin >> command;
        if (command == "quit") {
            std::string ans;
            std::cout << "Are you want to save game? (y-yes, any-no): ";
            std::cin >> ans;
            if (ans=="y") {
                saveGame(actorSet);
            }
            isGameEnd=true;
        } else if (command=="save") {
            saveGame(actorSet);
        } else if (command=="load") {
            loadSavedGame(actorSet);
        } else if (command=="show") {
            printStat(actorSet);
        } else if (command=="left" || command=="l" || command=="right" || command=="r" || command=="up" || command=="u" || command=="down" || command=="d"){
           for (int aCount=0; aCount<actorSet.size(); aCount++) {
               if (aCount==0) {
                   if (command=="left" || command=="l") {
                       int _posX = actorSet[aCount].aPosX-1;
                       if (_posX>0 && gameField[_posX][actorSet[aCount].aPosY]== nullptr) {
                           gameField[_posX][actorSet[aCount].aPosY] = gameField[actorSet[aCount].aPosX][actorSet[aCount].aPosY];
                           gameField[actorSet[aCount].aPosX][actorSet[aCount].aPosY] = nullptr;
                           actorSet[aCount].aPosX=_posX;
                       } else if (_posX>0 && gameField[_posX][actorSet[aCount].aPosY]!= nullptr) {
                           takeDamage(gameField[actorSet[aCount].aPosX][actorSet[aCount].aPosY], gameField[_posX][actorSet[aCount].aPosY]);
                       }
                   } else if (command=="right" || command=="r") {
                       int _posX = actorSet[aCount].aPosX+1;
                       if (_posX<fieldDim-1 && gameField[_posX][actorSet[aCount].aPosY]== nullptr) {
                           gameField[_posX][actorSet[aCount].aPosY] = gameField[actorSet[aCount].aPosX][actorSet[aCount].aPosY];
                           gameField[actorSet[aCount].aPosX][actorSet[aCount].aPosY] = nullptr;
                           actorSet[aCount].aPosX=_posX;
                       } else if (_posX<fieldDim-1 && gameField[_posX][actorSet[aCount].aPosY]!= nullptr) {
                           takeDamage(gameField[actorSet[aCount].aPosX][actorSet[aCount].aPosY], gameField[_posX][actorSet[aCount].aPosY]);
                       }
                   } else if (command=="up" || command=="u") {
                       int _posY = actorSet[aCount].aPosY-1;
                       if (_posY>0 && gameField[actorSet[aCount].aPosY][_posY]== nullptr) {
                           gameField[actorSet[aCount].aPosX][_posY] = gameField[actorSet[aCount].aPosX][actorSet[aCount].aPosY];
                           gameField[actorSet[aCount].aPosX][actorSet[aCount].aPosY] = nullptr;
                           actorSet[aCount].aPosY=_posY;
                       } else if (_posY>0 && gameField[actorSet[aCount].aPosX][_posY]!= nullptr) {
                           takeDamage(gameField[actorSet[aCount].aPosX][actorSet[aCount].aPosY], gameField[actorSet[aCount].aPosX][_posY]);
                       }
                   } else if (command=="down" || command=="d") {
                       int _posY = actorSet[aCount].aPosY+1;
                       if (_posY<fieldDim-1 && gameField[actorSet[aCount].aPosY][_posY]== nullptr) {
                           gameField[actorSet[aCount].aPosX][_posY] = gameField[actorSet[aCount].aPosX][actorSet[aCount].aPosY];
                           gameField[actorSet[aCount].aPosX][actorSet[aCount].aPosY] = nullptr;
                           actorSet[aCount].aPosY=_posY;
                       } else if (_posY<fieldDim-1 && gameField[actorSet[aCount].aPosX][_posY]!= nullptr) {
                           takeDamage(gameField[actorSet[aCount].aPosX][actorSet[aCount].aPosY], gameField[actorSet[aCount].aPosX][_posY]);
                       }
                   }
               } else {
                   int direct = rand()%4;
                   if (actorSet[aCount].aHp!=0) {
                       if (direct == 0) {
                           int _posX = actorSet[aCount].aPosX - 1;
                           if (_posX > 0 && gameField[_posX][actorSet[aCount].aPosY] == nullptr) {
                               gameField[_posX][actorSet[aCount].aPosY] = gameField[actorSet[aCount].aPosX][actorSet[aCount].aPosY];
                               gameField[actorSet[aCount].aPosX][actorSet[aCount].aPosY] = nullptr;
                               actorSet[aCount].aPosX = _posX;
                           } else if (_posX > 0 && gameField[_posX][actorSet[aCount].aPosY] != nullptr) {
                               takeDamage(gameField[actorSet[aCount].aPosX][actorSet[aCount].aPosY],
                                          gameField[_posX][actorSet[aCount].aPosY]);
                           }
                       } else if (direct == 1) {
                           int _posX = actorSet[aCount].aPosX + 1;
                           if (_posX < fieldDim - 1 && gameField[_posX][actorSet[aCount].aPosY] == nullptr) {
                               gameField[_posX][actorSet[aCount].aPosY] = gameField[actorSet[aCount].aPosX][actorSet[aCount].aPosY];
                               gameField[actorSet[aCount].aPosX][actorSet[aCount].aPosY] = nullptr;
                               actorSet[aCount].aPosX = _posX;
                           } else if (_posX < fieldDim - 1 && gameField[_posX][actorSet[aCount].aPosY] != nullptr) {
                               takeDamage(gameField[actorSet[aCount].aPosX][actorSet[aCount].aPosY],
                                          gameField[_posX][actorSet[aCount].aPosY]);
                           }
                       } else if (direct == 2) {
                           int _posY = actorSet[aCount].aPosY - 1;
                           if (_posY > 0 && gameField[actorSet[aCount].aPosY][_posY] == nullptr) {
                               gameField[actorSet[aCount].aPosX][_posY] = gameField[actorSet[aCount].aPosX][actorSet[aCount].aPosY];
                               gameField[actorSet[aCount].aPosX][actorSet[aCount].aPosY] = nullptr;
                               actorSet[aCount].aPosY = _posY;
                           } else if (_posY > 0 && gameField[actorSet[aCount].aPosX][_posY] != nullptr) {
                               takeDamage(gameField[actorSet[aCount].aPosX][actorSet[aCount].aPosY],
                                          gameField[actorSet[aCount].aPosX][_posY]);
                           }
                       } else if (direct == 3) {
                           int _posY = actorSet[aCount].aPosY + 1;
                           if (_posY < fieldDim - 1 && gameField[actorSet[aCount].aPosY][_posY] == nullptr) {
                               gameField[actorSet[aCount].aPosX][_posY] = gameField[actorSet[aCount].aPosX][actorSet[aCount].aPosY];
                               gameField[actorSet[aCount].aPosX][actorSet[aCount].aPosY] = nullptr;
                               actorSet[aCount].aPosY = _posY;
                           } else if (_posY < fieldDim - 1 && gameField[actorSet[aCount].aPosX][_posY] != nullptr) {
                               takeDamage(gameField[actorSet[aCount].aPosX][actorSet[aCount].aPosY],
                                          gameField[actorSet[aCount].aPosX][_posY]);
                           }
                       }
                   }
               }
           }
        } else {
            std::cout << "Unrecognized command\n";
        }
    } while (!isGameEnd);

    return 0;
}