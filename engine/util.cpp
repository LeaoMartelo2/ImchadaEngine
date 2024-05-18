#include "engine.h"

namespace Imchada {

int ascii_to_int(char ascii_int) {

  if (ascii_int >= '0' && ascii_int <= '9') { // check if is a valid digit
    return ascii_int - '0';
  } else {
    std::cerr << "[ImchadaEngine] [ERROR]: Error: Input char was not a valid "
                 "digit"
              << std::endl;
    return -1;
  }
}

} // namespace Imchada
