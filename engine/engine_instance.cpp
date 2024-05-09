#include "engine.h"

namespace Imchada {

void Instance::set_debug(bool state) { Instance::m_isDebug = state; }
void Instance::set_verbose(bool state) { Instance::m_isVerbose = state; }
void Instance::set_logging(bool state) { Instance::m_isLogging = state; }

bool Instance::get_debug_state() { return Instance::m_isDebug; }
bool Instance::get_verbose_state() { return Instance::m_isVerbose; }
bool Instance::get_logging_state() { return Instance::m_isLogging; }

} // namespace Imchada
