#include "engine.h"

namespace Imchada {
void Instance::set_debug(bool state) { m_isDebug = state; }
bool Instance::get_debug_state() { return m_isDebug; }

void Instance::set_verbose(bool state) { m_isVerbose = state; }
bool Instance::get_verbose_state() { return m_isVerbose; }

void Instance::set_logging(bool state) { m_Logging = state; }
bool Instance::get_logging_state() { return m_Logging; }

/*
void Imchada::Instance::set_logging_level(int level) {
  m_logging_level = level;
}
int Imchada::Instance::get_logging_level() { return m_logging_level; }

*/
} // namespace Imchada
