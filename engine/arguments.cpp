#include "engine.h"
#include <cstdlib>
#include <cstring>

namespace Imchada {

void Instance::process_arguments(int argc, char *argv[]) {

  /*add your custom arguments here */

  for (int i = 0; i < argc; i++) {
    if (strcmp(argv[i], "-debug") == 0) {
      set_debug(true);
    } else {
      set_debug(false);
    }

    if (strcmp(argv[i], "-verbose") == 0) {
      set_verbose(true);
    } else {
      set_verbose(false);
    }

    if (strcmp(argv[i], "-log") == 0) {
      set_logging_level(atoi(argv[i + 1])); // probably should add some checks
    } else {
      set_logging_level(0);
    }

    if (strcmp(argv[i], "-example") == 0) {
      // example
    } else {
      // !example
    }
  }
}

} // namespace Imchada
