#ifndef ENGINE_H
#define ENGINE_H

#include <string>

#define IMCHADA_ERROR Instance::LogType::ERROR
#define IMCHADA_WARN Instance::LogType::WARNING
#define IMCHADA_MESSAGE Instance::LogType::MESSAGE

class Instance {
    private:
        bool m_isDebug;
        bool m_isVerbose;
        bool m_Logging;

        void process_arguments(int argc, char *argv[]);

    public:
        Instance(int argc, char *argv[]);
        ~Instance();

        void set_debug(bool state);
        void set_verbose(bool state);
        void set_logging(bool state);

        bool get_debug_state();
        bool get_verbose_state();
        bool get_logging_state();

        // logging stuff

        enum class LogType { MESSAGE,
                             ERROR,
                             WARNING };

        void imchada_log(std::string log_message, LogType level);

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

#endif // !ENGINE_H
