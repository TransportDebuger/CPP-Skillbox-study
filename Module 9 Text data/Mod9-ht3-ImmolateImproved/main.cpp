#include <iostream>

int main() {
  std::cout << "Immolate Improved!\n";

  float healthPoints, magicResistance, fireballPower;

  std::cout << "Сколько HP у Орка? ";
  std::cin >> healthPoints;
  if (healthPoints <= 0.f) {
    std::cout << "Запускать огненый шар в мертвого орка глупо. Лучше потратить силы на живого врага!\n";
  } else {
    do {
      std::cout << "Вы заметили легкое свечение ауры сопротивляемости. Как сильно она светиться? (0-1): ";
      std::cin >> magicResistance;
      if (magicResistance < 0.f || magicResistance > 1.f) {
        std::cout << "Так не бывает. Подумайте еще раз.\n";
      }
    } while (magicResistance < 0.f || magicResistance > 1.f);
    if (magicResistance == 1.f) { 
      std::cout << "Огненный шар бесполезен. Придется в бить Орка старым добрым клинком!\n";
    } else {
      for (float reducingHP = 0.f; healthPoints > 0.f; ) {
        do {
          std::cout << "Какой мощности огненный шар запустим? ";
          std::cin >> fireballPower;
          if (fireballPower < 0.f) {
            std::cout << "Вернуть здоровье Орку вряд ли получиться? Попробуйте подумать еще раз.\n";
          }
        } while (fireballPower <= 0.f);
        reducingHP = fireballPower - fireballPower * magicResistance;
        healthPoints -= reducingHP;
        std::cout << "Вы нанесли " << reducingHP << " урона.\n";
        if (healthPoints > 0.f) {
          std::cout << "У Орка осталось " << healthPoints << " HP.\n";
        } else {
          std::cout << "Хорошо прожаренный Орк. Что может быть лучше!\n";
        }
      }
    }
  }
}