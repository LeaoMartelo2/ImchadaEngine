#include "engine.h"
#include <chrono>
#include <cstdlib>
#include <ctime>
#include <fstream>
#include <iostream>

namespace Imchada {

const char *logLevel_header = "[ImchadaEngine]: ";
const char *logLevel_error = "[ImchadaEngine][ERROR]: ";
const char *logLevel_warn = "[ImchadaEngine][WARN]: ";

void Instance::imchada_log(std::string log_message, LogLevel level) {

  if (!get_logging_state()) {
    return;
  }

  /* get system time chrono magic */

  // get sys time
  auto now = std::chrono::system_clock::now();

  // convert it to time_point UTC standart
  std::time_t now_c = std::chrono::system_clock::to_time_t(now);

  // convert utc to local time struct, or whatever that means didnt understarnd
  // it yet
  std::tm *local_time = std::localtime(&now_c);

  int hour = local_time->tm_hour;  // Hour of the day (24-hour format)
  int minute = local_time->tm_min; // Minute of the hour
  int second = local_time->tm_sec; // Second of the minute

  std::fstream file("latest.log", std::ios::app); // open file in append mode

  if (!file.is_open()) {

    file.open("latest.log",
              std::ios::out); // creates the file in output mode if it does not
                              // exist / failed to open in append mode
  }

  std::string temp_log_header;

  switch (level) {

  case LogLevel::WARNING:
    temp_log_header = logLevel_warn;
    break;

  case LogLevel::ERROR:
    temp_log_header = logLevel_error;
    break;

  default:
    temp_log_header = logLevel_header;
    break;
  }

  /* this step builds the message to be printed in the log file */

  file << "[" << hour << ":" << minute << ":" << second << "]"
       << temp_log_header << log_message << std::endl;

  file.close();
}

} // namespace Imchada
