#include "../engine/engine.h"
#include "include/example.h"
#include <iostream>

int main(int argc, char **argv) {

  Imchada::Instance example(argc, argv);

  std::cout << example.get_debug_state() << std::endl;

  example.set_debug(true);

  std::cout << example.get_debug_state() << std::endl;

  std::cout << "Hello World from main file\n";
  hello_world();

  std::cout << example.get_logging_level() << std::endl;

  return 0;
}
