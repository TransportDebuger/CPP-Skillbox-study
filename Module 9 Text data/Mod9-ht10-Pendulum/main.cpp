#include <iostream>

int main() {
  std::cout << "Маятник!\n";

  float startAmp, stopAmp;
  int counter=0;

  std::cout << "Начальная амплитуда маятника (см): ";
  std::cin >> startAmp;
  if (startAmp > 0.f) {
    std::cout << "Конечная амплитуда маятника (см): ";
    std::cin >> stopAmp;
    if (stopAmp < startAmp && stopAmp > 0.f) {
      do {
        startAmp *= 0.916f;
        counter++;
      } while (startAmp > stopAmp);
      std::cout << "Количество колебаний маятника " << counter << "\n";
    }
  }
}