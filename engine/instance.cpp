#include "engine.h"
#include <cstring>

namespace Imchada {

// engine state
void Instance::set_debug(bool state) { m_isDebug = state; }
bool Instance::get_debug_state() { return m_isDebug; }

void Instance::set_verbose(bool state) { m_isVerbose = state; }
bool Instance::get_verbose_state() { return m_isVerbose; }

void Instance::set_logging(bool state) { m_Logging = state; }
bool Instance::get_logging_state() { return m_Logging; }

// arguments

void Instance::process_arguments(int argc, char *argv[]) {

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

}; // namespace Imchada
