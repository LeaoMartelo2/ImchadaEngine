#include "engine.h"

namespace Imchada {
void Instance::set_debug(bool state) { m_isDebug = state; }
bool Instance::get_debug_state() { return m_isDebug; }

void Instance::set_verbose(bool state) { m_isVerbose = state; }
bool Instance::get_verbose_state() { return m_isVerbose; }

void Instance::set_logging(bool state) { m_Logging = state; }
bool Instance::get_logging_state() { return m_Logging; }

} // namespace Imchada
