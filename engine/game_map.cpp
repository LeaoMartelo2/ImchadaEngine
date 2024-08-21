#include "engine.hpp"
#include <fstream>
#include <iostream>

namespace Imchada {
GameMap::GameMap(std::string filename) {
  std::fstream mapfile(filename.c_str());
}
}; // namespace Imchada
