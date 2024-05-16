#ifndef ENGINE_H
#define ENGINE_H

namespace Imchada {
class Instance {
private:
  bool m_isDebug;
  bool m_isVerbose;
  int m_logging_level;

  void process_arguments(int argc, char *argv[]);

public:
  Instance(int argc, char *argv[]);

  void set_debug(bool state);
  void set_verbose(bool state);
  void set_logging_level(int level);

  bool get_debug_state();
  bool get_verbose_state();
  int get_logging_level();
};

} // namespace Imchada

#endif // !ENGINE_H
