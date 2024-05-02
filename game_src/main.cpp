#include "../engine/engine.h"
#include "include/example.h"
#include <iostream>

int main(int argc, char *argv[]) {
  Imchada::Instance example;
  example.get_logging_state();
  std::cout << "Hello World from main file\n";
  hello_world();
  return 0;
}
