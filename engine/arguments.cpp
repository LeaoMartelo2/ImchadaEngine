#include "engine.h"
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
      set_logging(true);
    }

    /*   if (strcmp(argv[i], "-log") == 0) {
         int log_value = std::stoi(argv[i + 1]);
         if (log_value >= 0 && log_value <= 9) { // is a number
           if (log_value < MAX_LOGGING_LEVEL + 1) {
             set_logging_level(log_value);
           }
           if (log_value > MAX_LOGGING_LEVEL) {
             printf("[ImchadaEngine] [ERROR]: Invalid logging state value
       parsed, " "found %d \n, Expected \'1\' through \'%d\' " "Defaulting to "
                    "\'0\' \n",
                    log_value, MAX_LOGGING_LEVEL);
             return;
           }
         }
       }

       */

    if (strcmp(argv[i], "-example") == 0) {
      // example
    }
  }
}

} // namespace Imchada
