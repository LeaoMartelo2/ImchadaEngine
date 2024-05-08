#include "engine.h"
#include <cstring>

namespace Imchada {

void process_arguments(Instance &current, int argc, char *argv[]) {

  /* add your custom - arguments here */
  const char *argument_comparelist[] = {"-debug", "-verbose", "-log",
                                        "-example"};

  for (int i = 0; i < argc; i++) {
    if (strcmp(argv[i], argument_comparelist[0]) == 0) {
      current.set_debug(true);
    }
    if (strcmp(argv[i], argument_comparelist[1]) == 0) {
      current.set_verbose(true);
    }
    if (strcmp(argv[i], argument_comparelist[2]) == 0) {
      current.set_logging(true);
    }
    if (strcmp(argv[i], argument_comparelist[3]) == 0) {
      /*example argument*/
    }
  }
}
} // namespace Imchada
