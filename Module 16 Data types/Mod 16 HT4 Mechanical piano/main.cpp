#include <iostream>
#include <string>

enum notes {
  UNKNOWN = 0,
  NOTE_C = 1,
  NOTE_D = 2,
  NOTE_E = 4,
  NOTE_F = 8,
  NOTE_G = 16,
  NOTE_A = 32,
  NOTE_B = 64
};

void printNote(notes NFlag){
  switch (NFlag) {
    case NOTE_C:
      std::cout << "C ";
      break;
    case NOTE_D:
      std::cout << "D ";
      break;
    case NOTE_E:
      std::cout << "E ";
      break;
    case NOTE_F:
      std::cout << "F ";
      break;
    case NOTE_G:
      std::cout << "G ";
      break;
    case NOTE_A:
      std::cout << "A ";
      break;
    case NOTE_B:
      std::cout << "B ";
      break;
    default:
      break;
  }
}

notes getNote(char nnote){
  int offset = nnote-49;
  switch (1 << offset) {
    case 1: return NOTE_C;
    case 2: return NOTE_D;
    case 4: return NOTE_E;
    case 8: return NOTE_F;
    case 16: return NOTE_G;
    case 32: return NOTE_A;
    case 64: return NOTE_B;
    default: return UNKNOWN;
  }
}

int main() {
  //число для аккорда.
  int chords[12];
  std::cout << "Tip: For chord construction use numbers from 1 (note C) to 7 (note B)." << std::endl;
  std::cout << "For example: 134 ecual the chord C E F." << std::endl;
  for (int count=0; count<sizeof(chords)/sizeof(chords[0]); count++) {
    std::cout << "Enter the chord[" << count << "]: ";
    std::cin >> chords[count];
  }

  std::cout << "OK. Let's play the melody." << std::endl;
  for (int count=0; count<sizeof(chords)/sizeof(chords[0]); count++) {
    std::string chordBuffer = std::to_string(chords[count]);
    for (int i=0; i<chordBuffer.length(); i++) {
      printNote(getNote(chordBuffer[i]));
    }
    std::cout << std::endl;
  }
} 