#ifndef ENGINE_H
#define ENGINE_H

#include "cstring"
#include <iostream>
#include <stdio.h>

#define MAX_LOGGING_LEVEL 2
#define LOG_ERROR 1
#define LOG_WARN 2

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

// logging

void imchada_log(std::string log_message, unsigned short log_level);

void imchada_log(char *message, unsigned short log_level);

// utils

int ascii_to_int(char ascii_int);

} // namespace Imchada

#endif // !ENGINE_H
