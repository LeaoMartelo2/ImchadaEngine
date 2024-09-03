#include "engine.hpp"
#include <chrono>
#include <cstring>
#include <ctime>
#include <fstream>
#include <iostream>
#include <memory>
#include <string>

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
    }
}

// logging

void Instance::imchada_log(std::string log_message, LogType level) {

    if (get_logging_state() == false) {
        return;
    }

    std::string temp_log_header = "SOMETHING WENT WRONG\n";

    switch (level) {

    case LogType::WARNING:
        temp_log_header = logLevel_warn;
        break;

    case LogType::ERROR:
        temp_log_header = logLevel_error;
        break;

    default:
        temp_log_header = logLevel_header;
        break;
    }

    // get sys time
    auto now = std::chrono::system_clock::now();

    // convert time_point to time_t
    std::time_t now_c = std::chrono::system_clock::to_time_t(now);

    /*timezone stuff*/
    std::tm *local_time = std::localtime(&now_c);

    int day = local_time->tm_mday;
    int month = local_time->tm_mon + 1;    // 0 indexed
    int year = local_time->tm_year + 1900; // timestamped since 1900 so add 1900 to get current year
    int hour = local_time->tm_hour;        // 24-hour format
    int minute = local_time->tm_min;
    int second = local_time->tm_sec;

    std::fstream file("latest.log", std::ios::app); // open file in append mode

    if (!file.is_open()) {

        file.open("latest.log", std::ios::out); // creates the file in output mode if it does
                                                // not exist / failed to open in append mode
    }

    /* this step builds the message to be printed in the log file */

    file << "[" << year << "/" << month << "/" << day << "]"
         << "[" << hour << ":" << minute << ":" << second << "]"
         << temp_log_header << log_message << std::endl;

    /*this should end up printing like this*/
    /*[year/month/day] [hour:minute:second] <LogType> <message>*/

    file.close();
}

void Instance::add_scene(const std::shared_ptr<Scene> &scene_ptr) {

    scene_ptrs.push_back(scene_ptr);

    if (m_Logging) {
        imchada_log("Pushed Scene to Instance, Scene ID: " +
                        std::to_string(scene_ptrs.size() - 1),
                    IMCHADA_MESSAGE);
    }
}

int Instance::get_scene_count() {
    return scene_ptrs.size();
}

void Instance::load_scene(long unsigned int scene_id) {
    /*logic to load scene by its std::vector position  */

    if (scene_id < scene_ptrs.size()) {
        scene_ptrs[scene_id]->load();

        if (m_Logging) {
            imchada_log("Loaded Scene with ID: " + std::to_string(scene_id), IMCHADA_MESSAGE);
        }

    } else {
        if (m_Logging) {
            imchada_log("Instance failed to load Scene; Tried to load scene with ID: " +
                            std::to_string(scene_id),
                        IMCHADA_ERROR);
        }
        return;
        // oh well ¯\_(ツ)_/¯
    }
}
// classless functions
