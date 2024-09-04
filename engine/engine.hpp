#ifndef ENGINE_H
#define ENGINE_H

#include "scene.hpp"
#include <memory>
#include <string>
#include <vector>

#define IMCHADA_ERROR Instance::LogType::ERROR
#define IMCHADA_WARN Instance::LogType::WARNING
#define IMCHADA_MESSAGE Instance::LogType::MESSAGE

class Instance {
    private:
        bool m_isDebug;
        bool m_Logging;

        const std::string logLevel_header = "[ImchadaEngine][LOG]: ";
        const std::string logLevel_error = "[ImchadaEngine][ERROR]: ";
        const std::string logLevel_warn = "[ImchadaEngine][WARN]: ";

        std::vector<std::shared_ptr<Scene>> scene_ptrs;

    private:
        void process_arguments(int argc, char *argv[]);

        void add_scene(const std::shared_ptr<Scene> &scene_ptr);

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
                             WARNING };

        void imchada_log(std::string log_message, LogType level);

        // scene stuff

        /*this creates a Scene object, pushes it in to the Scene(s) buffer, and returns its id */
        int create_scene();

        long unsigned int get_scene_count(void);

        int load_scene(int scene_id);

}; // Instance

class Asset {
    public:
        void load_asset();
}; // Asset

class GameMap {
    private:
        char map[31][81];

    public:
    private:
        //
    public:
        GameMap(std::string filename);

        char **get_map();

        void visualOverride(char original_value, char replace_with);
};

// classless functions

#endif //
