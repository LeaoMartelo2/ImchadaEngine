#include "engine.hpp"
#include <fstream>

namespace Imchada {
GameMap::GameMap(std::string filename) {
    std::fstream mapfile(filename.c_str());
}
}; // namespace Imchada
