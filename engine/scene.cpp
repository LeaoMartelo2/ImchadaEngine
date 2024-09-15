#include "scene.hpp"
#include <algorithm>
#include <cstring>
#include <fstream>
#include <iostream>
#include <string>
#include <vector>

Scene::Scene(std::string filename) {

    fail_state = false;
    get_map_from_file(filename);
    if (get_map_from_file(filename) == false) {
        return;
    }
}

Scene::~Scene() {
    std::cout << "scene destructor called \n";
}

bool Scene::failed_to_load() {
    if (fail_state) {
        return true;
    } else {
        return false;
    }
}

bool Scene::get_map_from_file(std::string &filename) {

    std::ifstream file(filename);
    if (!file.is_open()) {
        // could not open the file
        fail_state = true;
        return false;
    }
    fail_state = true;

    std::string line;

    for (int i = 0; i < 31 && std::getline(file, line); ++i) {
        std::copy_n(line.begin(), std::min(line.size(), size_t(80)), scene_map[i].begin());
    }

    file.close();

    return true;
}

void Scene::load() {

    /*temp debug until i start ncurses implementation*/
    for (const auto &row : scene_map) {
        for (const char c : row) {
            if (c != '\0') {
                std::cout << c;
            }
        }
        std::cout << std::endl;
    }
}
