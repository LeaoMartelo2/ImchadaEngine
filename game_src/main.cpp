#include "../engine/engine.h"
#include "include/example.h"
#include <iostream>

int main(int argc, char **argv) {

  Imchada::Instance example;

  std::cout << example.get_debug_state() << std::endl;

  example.set_debug(true);

  std::cout << example.get_debug_state() << std::endl;

  std::cout << "Hello World from main file\n";
  hello_world();
  return 0;
}
