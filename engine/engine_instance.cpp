#include "engine.h"

namespace Imchada {

inline void Instance::set_debug(bool state) { Instance::m_isDebug = state; }
inline void Instance::set_verbose(bool state) { Instance::m_isVerbose = state; }
inline void Instance::set_logging(bool state) { Instance::m_isLogging = state; }

inline bool Instance::get_debug_state() { return Instance::m_isDebug; }
inline bool Instance::get_verbose_state() { return Instance::m_isVerbose; }
inline bool Instance::get_logging_state() { return Instance::m_isLogging; }

} // namespace Imchada
