#ifndef ENGINE_H
#define ENGINE_H

#include <cstring>
#include <iostream>
#include <stdio.h>
#include <vector>

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

  // scene stuff
  /*  @TODO  */

private:
  char m_scene_buffer[30][80];

  std::vector<char[30][80]> scenes;

public:
  char curret_scene[30][80];

  int add_scene(char new_scene[][80]); // you add a screne and it returns you
                                       // with the scene id

  int load_scene(int scene_id); // loads the scene for the given scene id

  void reload_current(); // reloads the current scene

}; // Instance

void imchada_log(std::string log_message, int log_level);

void imchada_log(char *message, int log_level);

} // namespace Imchada

#endif // !ENGINE_H
