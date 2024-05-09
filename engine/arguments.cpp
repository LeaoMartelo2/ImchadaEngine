#include "engine.h"
#include <cstring>

namespace Imchada {

void Instance::process_arguments(int argc, char *argv[]) {

  /* add your custom - arguments here */
  const char *argument_comparelist[] = {"-debug", "-verbose", "-log",
                                        "-example"};

  /* check for your custom arguments here */
  for (int i = 0; i < argc; i++) {
    if (strcmp(argv[i], argument_comparelist[0]) == 0) { //-debug
      Instance::set_debug(true);
    }
    if (strcmp(argv[i], argument_comparelist[1]) == 0) { //-verbose
      Instance::set_verbose(true);
    }
    if (strcmp(argv[i], argument_comparelist[2]) == 0) { //-log
      Instance::set_logging(true);
    }
    if (strcmp(argv[i], argument_comparelist[3]) == 0) { //-example
      /*example argument*/
    }
  }
}
} // namespace Imchada
