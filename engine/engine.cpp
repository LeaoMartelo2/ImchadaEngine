#include "engine.h"
#include <ncurses.h>

void Imchada::Engine::set_debug(bool state) {
  Imchada::Engine::m_isDebug = state;
}

void Imchada::Engine::set_verbose(bool state) {
  Imchada::Engine::m_isVerbose = state;
}

void Imchada::Engine::set_logging(bool state) {
  Imchada::Engine::m_isLogging = state;
}

bool Imchada::Engine::get_debug_state() {
  // probabbly need to find a better way to do this
  return Imchada::Engine::m_isDebug;
}

bool Imchada::Engine::get_verbose_state() {
  // probabbly need to find a better way to do this
  return Imchada::Engine::m_isVerbose;
}

bool Imchada::Engine::get_logging_state() {
  // probabbly need to find a better way to do this
  return Imchada::Engine::m_isLogging;
}

void Imchada::Engine::setup_engine() {}
