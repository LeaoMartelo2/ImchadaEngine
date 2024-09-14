#ifndef ENGINE_H
#define ENGINE_H

#include "scene.hpp"
#include <fmt/core.h>
#include <memory>
#include <string>
#include <vector>

#define IMCHADA_ERROR Instance::LogType::ERROR
#define IMCHADA_WARN Instance::LogType::WARNING
#define IMCHADA_MESSAGE Instance::LogType::MESSAGE
#define IMCHADA_DEBUG Instance::LogType::DEBUG

class Instance {

    public:
        Instance(int argc, char *argv[]);
        ~Instance();

        // engine states stuff

        void set_debug(bool state);
        void set_logging(bool state);

        bool get_debug_state(void);
        bool get_logging_state(void);

        // logging stuff

        enum class LogType { MESSAGE,
                             ERROR,
                             WARNING,
                             DEBUG };

        // this causes a lot of headache
        template <typename... Args>
        void imchada_log(LogType level, const std::string &format_string, Args &&...args) {

            if (get_logging_state() == false) {
                return;
            }
            if (get_debug_state() == false && level == LogType::DEBUG) {
                return;
            }

            std::string formated_message = get_log_level_string(level);

            formated_message += fmt::format(format_string, std::forward<Args>(args)...);

            log_to_file(formated_message);
        }

        // scene stuff

        /*this creates a Scene object, pushes it in to the Scene(s) buffer, and returns its id */
        int create_scene();

        long unsigned int get_scene_count(void);

        int load_scene(int scene_id);

    private:
        bool m_isDebug;
        bool m_Logging;

        std::vector<std::shared_ptr<Scene>> scene_ptrs;

    private:
        void process_arguments(int argc, char *argv[]);

        std::string get_log_level_string(LogType level);

        void log_to_file(std::string log_line);

        void add_scene(const std::shared_ptr<Scene> &new_scene_ptr);

}; // Instance

#endif //
