#include <iostream>
#include <vector>
using namespace std;

//Стурктура "комната"
struct Room {
  public:
    Room(int rType, int spaceValue) {
      typeId = rType;
      switch (rType) {
        case 0: {
          roomType = "Bedroom";
          break;
          }
        case 1: {
          roomType = "Kitchen";
          break;
        }
        case 2: {
          roomType = "Bathroom";
          break;
        }
        case 3: {
          roomType = "Playroom";
          break;
        }
        case 4: {
          roomType = "Living room";
          break;
        }
      };
      space = spaceValue;
    }
    string getRType() {
      return roomType;
    }
    int getSpace() {
      return space;
    }
  private:
    int typeId;
    string roomType;
    int space;  
};
//Структура "Этаж"
struct Stage {
  public:
    Stage(int ceilingH, int nRooms) {
      ceilingHeight = ceilingH;
      numberOfRooms = nRooms;
      int count = 0;
      while (count<nRooms) {
        int square;
        int tRoom;
        do {
          cout << "Enter square of room: ";
          cin >> square;
        } while(square<=0);
        do {
          cout << "Enter room type (0-Bedroom, 1-Kitchen, 2-Bathroom, 3-Playroom, 4-Living room): ";
          cin >> tRoom;
        } while(tRoom<0 || tRoom>4);
        Room newRoom = Room(tRoom, square);
        Rooms.push_back(newRoom);
        count++;
      }
    }
    int getCeilingH() {
      return ceilingHeight;
    }
    int getNOfRooms() {
      return numberOfRooms;
    }
    void getRoomInfo(int RoomNumber) {
      if (RoomNumber >= Rooms.size() || RoomNumber < 0) {
        cout << "Room is out of range!\n";
      } else {
        cout << "Room #" << RoomNumber << " Room Type - " << Rooms[RoomNumber].getRType() << " square - " << Rooms[RoomNumber].getSpace() << endl;
      }
    }
  private: 
    int ceilingHeight;
    int numberOfRooms;
    vector<Room> Rooms;
};

//Структура "Здание"
struct Building {
  public:
    Building(int buildingType, int buildingSpace) {
      bSpace = buildingSpace;
      bType = buildingType;
      switch (bType) {
        case 0: {
          bTypeStr = "Living house";
          do {
            cout << "Enter number of Stages (1-3):";
            cin >> nStages;
          } while (nStages < 0 && nStages>3);
          for (int stageCount=0; stageCount<nStages; stageCount++) {
            int rooms;
            do {
              cout << "How many rooms in the stage? (2-4):";
              cin >> rooms;
            } while (rooms < 2 || rooms>4);
            int ceilingH;
            do {
              cout << "What height of ceiling in the stage? (>=2m):";
              cin  >>ceilingH;
            } while (ceilingH<2);
            Stage newStage = Stage(ceilingH, rooms);
            stages.push_back(newStage);
          }
          break;
        }
        case 1: {
          bTypeStr = "Garage";
          break;
        }
        case 2: {
          bTypeStr = "Barn";
          break;
        }
        case 3: {
          bTypeStr = "Bathhouse";
          break;
        }
      }
      if (bType == 0 || bType == 4) {
        int present;
        do {
        cout << "Is furnace present? (1 - yes, 0 - no)";
        cin >> present;
        } while (present<0 && present > 1);
        isFurnacePresent = !present?false:true;
      }
    }
    int getSquare() {
      return bSpace;
    }
  private:
    int bType;
    string bTypeStr;
    bool isFurnacePresent;
    int bSpace;
    int nStages;
    vector<Stage> stages;
};

struct Homestead {
public:
 Homestead(int Space, int numberOfBuildings=1) {
   hsSpace = Space;
   nOfBuildings = numberOfBuildings;
   for (int bCount=0; bCount<nOfBuildings; bCount++){
     int bType;
     int square;
     if (bCount == 0) {
        bType=0;
        cout << "Describe living house\n";
        cout << "Enter square of living house:";
        cin >> square;
      } else {
        cout << "What type of additional building are yo want to describe?\n";
        cout << "(0 - living house, 1 - Garage, 2 - Barn, 3 - Bathhouse):";
        cin >> bType;
        cout << "Enter square of building:";
        cin >> square;
      }
      Building newBuilding = Building(bType, square);
      Buildings.push_back(newBuilding);
    }
  }
  int getSquare() {
       return hsSpace;
  }
  int getBuildingCount() {
    return nOfBuildings;
  }
private:
  int hsSpace;
  int nOfBuildings;
  vector<Building> Buildings;
};

int main() {
  cout << "Hello World!\n";
  vector<Homestead> Homesteads;

  cout << "How many homestaeds in this area? ";
  int homeStaeadsCount;
  cin >> homeStaeadsCount;
  for (int hsCount=0; hsCount<homeStaeadsCount; hsCount++) {
    int  bCount, hsSquare;
    cout << "what square of this homestaed? ";
    cin >> hsSquare;
    cout << "How many building in this homestaed? ";
    cin >> bCount;
    
    Homestead newHomestead = Homestead(hsSquare, bCount);
    Homesteads.push_back(newHomestead);
  }

  cout << "\n\n++++++++++++++++++++++++++++++++++++++++\n";
  cout << "Info about area\n";
  cout << "\++++++++++++++++++++++++++++++++++++++++\n";
  cout << "Number of Homesteads - " << Homesteads.size() << endl;
  cout << "Space of area - ";
  int total=0;
  for (int hsCount=0; hsCount<Homesteads.size(); hsCount++) {
    total += Homesteads[hsCount].getSquare();
  }
  cout << total << endl;
  cout << "Number of buildings - ";
  total = 0;
  for (int hsCount=0; hsCount<Homesteads.size(); hsCount++) {
    total += Homesteads[hsCount].getBuildingCount();
  }
  cout << total << endl;
}