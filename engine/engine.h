#ifndef ENGINE_H
#define ENGINE_H

// ENGINE_INSTANCE

namespace Imchada {
class Instance {
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

  void setup_engine();
};
} // namespace Imchada

// ARGUMENTS

namespace Imchada {

void process_arguments(const Instance &Current, int argc, char *argv[]);

}

#endif // !ENGINE_H
