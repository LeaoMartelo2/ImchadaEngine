#include "engine.h"

namespace Imchada {

Instance::Instance(int argc, char *argv[]) {

  // you can set those here manually to force a state regardless of aguments
  m_Logging = false;
  m_isVerbose = false;
  m_isDebug = false;

  process_arguments(argc, argv);

  imchada_log("########## Imchada Engine Instance Created ##########",
              LOG_MESSAGE);

  if (m_isDebug) {
    imchada_log("DEBUG MODE ENABLED", LOG_MESSAGE);
  }
}
} // namespace Imchada
