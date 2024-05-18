#include "engine.h"
#include <cstdlib>
#include <cstring>

namespace Imchada {

void Instance::process_arguments(int argc, char *argv[]) {

  /*add your custom arguments here */

  for (int i = 0; i < argc; i++) {
    if (strcmp(argv[i], "-debug") == 0) {
      set_debug(true);
    }

    if (strcmp(argv[i], "-verbose") == 0) {
      set_verbose(true);
    }

    if (strcmp(argv[i], "-log") == 0) {
      if (atoi(argv[i + 1]) > MAX_LOGGING_LEVEL && atoi(argv[i + 1]) > -1) {
        set_logging_level(
            atoi(argv[i + 1])); // probably should add some more checks
      }
    }

    if (strcmp(argv[i], "-example") == 0) {
      // example
    }
  }
}

} // namespace Imchada
