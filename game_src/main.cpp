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

  example.imchada_log("message log", LOG_MESSAGE);
  example.imchada_log("warn log", LOG_WARN);
  example.imchada_log("error log", LOG_ERROR);

  std::cout << example.get_debug_state() << std::endl;

  return 0;
}
