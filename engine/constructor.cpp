#include "engine.h"

namespace Imchada {

Instance::Instance(int argc, char *argv[]) {

  m_logging_level = 0;
  m_isVerbose = false;
  m_isDebug = false;

  process_arguments(argc, argv);
}

} // namespace Imchada
