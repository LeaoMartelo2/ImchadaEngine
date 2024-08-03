#ifndef ENGINE_H
#define ENGINE_H

#include "scene.h"
#include <cstring>
#include <fstream>
#include <iostream>
#include <stdio.h>
#include <vector>

#define LOG_ERROR Imchada::Instance::LogLevel::ERROR
#define LOG_WARN Imchada::Instance::LogLevel::WARNING
#define LOG_MESSAGE Imchada::Instance::LogLevel::MESSAGE

namespace Imchada {
class Instance {
private:
  bool m_isDebug;
  bool m_isVerbose;
  bool m_Logging;

  void process_arguments(int argc, char *argv[]);

public:
  Instance(int argc, char *argv[]);

  void set_debug(bool state);
  void set_verbose(bool state);
  void set_logging(bool state);

  bool get_debug_state();
  bool get_verbose_state();
  // int get_logging_level();
  bool get_logging_state();

  // logging stuff

  enum class LogLevel { MESSAGE, ERROR, WARNING };

  void imchada_log(std::string log_message, LogLevel level);

  // scene stuff
  /*  @TODO  */

private:
public:
}; // Instance

} // namespace Imchada

#endif // !ENGINE_H
