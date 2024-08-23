#ifndef ENGINE_H
#define ENGINE_H

#include <memory>
#include <string>

#define LOG_ERROR Imchada::Instance::LogLevel::ERROR
#define LOG_WARN Imchada::Instance::LogLevel::WARNING
#define LOG_MESSAGE Imchada::Instance::LogLevel::MESSAGE

namespace Imchada {

class Instance {
    private:
        bool m_isDebug;
        bool m_isVerbose;
        bool m_Logging;

        void process_arguments(int argc, char *argv[]);

    public:
        Instance(int argc, char *argv[]);

        void set_debug(bool state);
        void set_verbose(bool state);
        void set_logging(bool state);

        bool get_debug_state();
        bool get_verbose_state();
        bool get_logging_state();

        // logging stuff

        enum class LogLevel { MESSAGE,
                              ERROR,
                              WARNING };

        void imchada_log(std::string log_message, LogLevel level);

}; // Instance

class Scene {
    private:
    public:
        void add_map();
}; // Scene

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

} // namespace Imchada

std::unique_ptr<Imchada::Instance> setupImchadaEngine(int argc, char *argv[]);

#endif // !ENGINE_H
