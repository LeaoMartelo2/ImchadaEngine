#include "engine.h"

namespace Imchada {

Instance::Instance(int argc, char *argv[]) {

  m_Logging = false;
  m_isVerbose = false;
  m_isDebug = false;

  process_arguments(argc, argv);

  imchada_log("Engine Start", LOG_MESSAGE);
}

} // namespace Imchada
