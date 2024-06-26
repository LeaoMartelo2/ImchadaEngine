#ifndef ENGINE_H
#define ENGINE_H

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
  //  int m_logging_level;
  bool m_Logging;

  void process_arguments(int argc, char *argv[]);

public:
  Instance(int argc, char *argv[]);

  void set_debug(bool state);
  void set_verbose(bool state);
  // void set_logging_level(int level);
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
  char m_scene_buffer[30][80];

  std::vector<char[30][80]> scenes;

public:
  char current_scene[30][80];

  int add_scene(char new_scene[][80]); // you add a screne and it returns you
                                       // with the scene id

  int load_scene(int scene_id); // loads the scene for the given scene id

  void setup_scenes(); // map display, hud, debug info, logs and etc

  void reload_current(); // reloads the current scene

}; // Instance

} // namespace Imchada

#endif // !ENGINE_H
