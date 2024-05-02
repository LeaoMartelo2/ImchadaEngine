#include "src/engine.h"
#include <iostream>

int main(int argc, char *argv[]) {
  Imchada::Engine roblox;

  roblox.set_debug(true);

  std::cout << roblox.get_debug_state() << std::endl;

  return 0;
}
