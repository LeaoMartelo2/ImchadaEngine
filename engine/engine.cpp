#include "engine.h"

void Imchada::Instance::set_debug(bool state) {
  Imchada::Instance::m_isDebug = state;
}

void Imchada::Instance::set_verbose(bool state) {
  Imchada::Instance::m_isVerbose = state;
}

void Imchada::Instance::set_logging(bool state) {
  Imchada::Instance::m_isLogging = state;
}

bool Imchada::Instance::get_debug_state() {
  // probabbly need to find a better way to do this
  return Imchada::Instance::m_isDebug;
}

bool Imchada::Instance::get_verbose_state() {
  // probabbly need to find a better way to do this
  return Imchada::Instance::m_isVerbose;
}

bool Imchada::Instance::get_logging_state() {
  // probabbly need to find a better way to do this
  return Imchada::Instance::m_isLogging;
}
