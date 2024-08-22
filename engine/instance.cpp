#include "engine.hpp"
#include <chrono>
#include <cstring>
#include <ctime>
#include <fstream>
#include <iostream>
#include <memory>

namespace Imchada {

// engine state
void Instance::set_debug(bool state) { m_isDebug = state; }
bool Instance::get_debug_state() { return m_isDebug; }

void Instance::set_verbose(bool state) { m_isVerbose = state; }
bool Instance::get_verbose_state() { return m_isVerbose; }

void Instance::set_logging(bool state) { m_Logging = state; }
bool Instance::get_logging_state() { return m_Logging; }

// arguments

void Instance::process_arguments(int argc, char *argv[]) {

    for (int i = 0; i < argc; i++) {
        if (strcmp(argv[i], "-debug") == 0) {
            set_debug(true);
        }

        if (strcmp(argv[i], "-verbose") == 0) {
            set_verbose(true);
        }

        if (strcmp(argv[i], "-log") == 0) {
            set_logging(true);
        }

        if (strcmp(argv[i], "-example") == 0) {
            // example
        }
    }
}

// logging
const char *logLevel_header = "[ImchadaEngine][LOG]: ";
const char *logLevel_error = "[ImchadaEngine][ERROR]: ";
const char *logLevel_warn = "[ImchadaEngine][WARN]: ";
const char *log_debug = "[ImchadaEngine][DEBUG] ";

void Instance::imchada_log(std::string log_message, LogLevel level) {

    if (!get_logging_state()) {
        return;
    }

    /* get system time chrono magic */

    // get sys time
    auto now = std::chrono::system_clock::now();

    // convert it to time_point UTC standart
    std::time_t now_c = std::chrono::system_clock::to_time_t(now);

    std::tm *local_time = std::localtime(&now_c);

    int hour = local_time->tm_hour;  // Hour of the day (24-hour format)
    int minute = local_time->tm_min; // Minute of the hour
    int second = local_time->tm_sec; // Second of the minute

    std::fstream file("latest.log", std::ios::app); // open file in append mode

    if (!file.is_open()) {

        file.open("latest.log",
                  std::ios::out); // creates the file in output mode if it does
                                  // not exist / failed to open in append mode
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

// classless functions

void setupImchadaEngine(int argc, char **argv) {

    std::shared_ptr<Instance> ImchadaInstance =
        std::make_shared<Instance>(argc, **argv);
}

}; // namespace Imchada
