#include "engine.hpp"
#include "scene.hpp"
#include <chrono>
#include <cstdarg>
#include <cstring>
#include <ctime>
#include <fmt/core.h>
#include <fstream>
#include <memory>
#include <string>
#include <utility>

// engine state
void Instance::set_debug(bool state) {

    imchada_log(IMCHADA_WARN, "DEBUG MODE: {}", state);

    m_isDebug = state;
}

bool Instance::get_debug_state(void) { return m_isDebug; }

void Instance::set_logging(bool state) { m_Logging = state; }
bool Instance::get_logging_state(void) { return m_Logging; }

// arguments

void Instance::process_arguments(int argc, char *argv[]) {

    std::string current_check = {};

    int i = 0;
    for (i = 0; i < argc; i++) {
        current_check = argv[i];

        if (current_check == "-debug") {
            m_isDebug = true;
        }

        if (current_check == "-log") {
            m_Logging = true;
        }
    }
}

// logging

void Instance::log_to_file(std::string log_line) {

    // get sys time
    auto now = std::chrono::system_clock::now();
    // convert time_point to time_t
    std::time_t now_c = std::chrono::system_clock::to_time_t(now);
    //    timezone stuff
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

    file << "[" << year << "/" << month << "/" << day << "]"
         << "[" << hour << ":" << minute << ":" << second << "]"
         << log_line << '\n';

    // this should end up printing like this
    //[year/month/day] [hour:minute:second] <LogType> <message>

    file.close();
}

std::string Instance::get_log_level_string(LogType level) {
    switch (level) {

    case LogType::MESSAGE:
        return "[ImchadaEngine][LOG]: ";
        break;

    case LogType::ERROR:
        return "[ImchadaEngine][ERROR]: ";
        break;

    case LogType::WARNING:
        return "[ImchadaEngine][WARN]: ";
        break;

    case LogType::DEBUG:
        if (m_isDebug == true) {
            return "[ImchadaEngine][DEBUG]: ";
        } else {
            return "";
        }
        break;

    default:
        return "UNKNOWN";
    }
}

void Instance::add_scene(const std::shared_ptr<Scene> &new_scene_ptr) {

    scene_ptrs.push_back(new_scene_ptr);

    imchada_log(IMCHADA_MESSAGE, "Pushed Scene to Instance, Scene ID: {}",
                scene_ptrs.size() - 1);
}

long unsigned int Instance::get_scene_count() {
    /*a std::vector's size is a long unsigned int apparently  */
    return scene_ptrs.size();
}

int Instance::load_scene(int scene_id) {
    /*logic to load scene by its std::vector position  */

    if (static_cast<long unsigned int>(scene_id) < scene_ptrs.size()) {
        scene_ptrs[scene_id]->load();

        imchada_log(IMCHADA_MESSAGE, "Loaded Scene with ID: {}", scene_id);
        return 0;

    } else {
        imchada_log(IMCHADA_ERROR, "Instance Failed to Load Scene, No Scene with ID {} found.", scene_id);
        return 1;
        // oh well ¯\_(ツ)_/¯
    }
}

int Instance::create_scene() {

    // this creates all the Scene objects with the same name, surprised it didnt blow up yet
    std::shared_ptr<Scene> scene_obj = std::make_shared<Scene>();

    add_scene(scene_obj);

    return static_cast<int>(scene_ptrs.size()) - 1;
}
// classless functions
