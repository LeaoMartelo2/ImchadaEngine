#ifndef SCENE_HPP
#define SCENE_HPP

#include <string>
#include <vector>

class Instance;

class Scene {
    private:
        std::vector<std::vector<char>> scene_map;

        bool get_map_from_file(std::string &filename);
        bool fail_state = false;

    public:
        Scene(std::string filename);
        ~Scene();

        void load();

        bool failed_to_load();

}; // Scene

#endif
