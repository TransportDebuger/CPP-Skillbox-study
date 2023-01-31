//
// Created by Artem on 28.01.2023.
//
#include <iostream>
#include "mod-cli.h"
#include "mod-cmp.h"

commands cmdconvert(const std::string &cmd) {
    if (cmd == "exit") return commands::EXIT;
    if (cmd == "input") return commands::INPUT;
    if (cmd == "read") return commands::READ;
    if (cmd == "write") return commands::WRITE;
    if (cmd == "save")  return commands::SAVE;
    if (cmd == "load") return commands::LOAD;
    if (cmd == "display") return commands::DISPLAY;
    if (cmd == "sum") return commands::SUM;
    return commands::UNKNOWN;
}

void Execute(commands cmd, Computer *cmp) {
  if (cmd == commands::EXIT) return;
  if (cmd == commands::UNKNOWN) {
      std::cout << "Command is not recognised\n";
  }
  else if (cmd == commands::DISPLAY) {
      cmp->gpuDisplay();
  } else if (cmd == commands::WRITE) {
      cmp->write();
  } else if (cmd == commands::SUM) {
      cmp->sum();
  } else if (cmd == commands::SAVE) {
      cmp->save();
  } else if (cmd == commands::LOAD) {
      cmp->load();
  }
}