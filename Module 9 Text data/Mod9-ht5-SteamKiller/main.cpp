#include <iostream>
#include <cmath>

int main() {
  std::cout << "Убийца Steam!\n";

  float fileSize, downloadSpeed, remainingSize;

  std::cout << "Введите размер файла для скачивания (МБ): ";
  std::cin >> fileSize;
  if (fileSize <= 0.f) {
    std::cout << "Неправильный размер файла.\n";
  } else {
    std::cout << "Введите скорость скачивания (МБ): ";
    std::cin >> downloadSpeed;
    if (downloadSpeed <=0.f) {
      std::cout << "Проверьте соединенние с Интернетом!\n";
    } else {
      remainingSize = fileSize;
      
      for (int count = 1; remainingSize > 0.f; ++count) {
         remainingSize -= downloadSpeed;
         if (remainingSize > 0.f) {
          std::cout << "Прошло " << count << " сек. Скачано " << count * downloadSpeed << " из " << fileSize << " МБ (" << std::floor((count*downloadSpeed)/fileSize*100) << "%).\n";
         } else {
           std::cout << "Прошло " << count << " сек. Скачано " << count * downloadSpeed + remainingSize << " из " << fileSize << " МБ (" << ( count * downloadSpeed + remainingSize)/fileSize*100 << "%).\n";
         }
      }
      
    }
  }
}