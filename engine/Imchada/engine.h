#ifndef ENGINE_H
#define ENGINE_H

namespace Imchada {
class Engine {
private:
  bool m_isDebug;
  bool m_isVerbose;
  bool m_isLogging;

public:
  void set_debug(bool state);
  void set_verbose(bool state);
  void set_logging(bool state);

  bool get_debug_state();
  bool get_verbose_state();
  bool get_logging_state();
};
} // namespace Imchada

#endif // !ENGINE_H
