#ifndef ENGINE_H
#define ENGINE_H

// ENGINE_INSTANCE

namespace Imchada {
class Instance {
private:
  bool m_isDebug = false;
  bool m_isVerbose = false;
  bool m_isLogging = false;

public:
  void set_debug(bool state);
  void set_verbose(bool state);
  void set_logging(bool state);

  bool get_debug_state();
  bool get_verbose_state();
  bool get_logging_state();

  void process_arguments(int argc, char *argv[]);
};
} // namespace Imchada

#endif // !ENGINE_H
