#include "engine.h"
#include <fstream>
#include <iostream>

namespace Imchada {

const char *logLevel_header = "[ImchadaEngine]: ";
const char *logLevel_error = "[ImchadaEngine] [ERROR]: ";
const char *logLevel_warn = "[ImchadaEngine] [WARN]: ";

void imchada_log(std::string log_message, int log_level) {

  std::fstream file("latest.log", std::ios::app);

  if (!file.is_open()) {

    std::cerr << "could not open latest.log\n no logs avaliable\n";
  }

  std::string temp_log_header;

  switch (log_level) {

  case LOG_WARN:
    temp_log_header = logLevel_warn;
    break;

  case LOG_ERROR:
    temp_log_header = logLevel_error;
    break;

  default:
    temp_log_header = logLevel_header;
    break;
  }

  file << temp_log_header << log_message << std::endl;

  file.close();
}

} // namespace Imchada
