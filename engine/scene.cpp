#include "scene.hpp"
#include <iostream>

Scene::Scene() {
    std::cout << "Scene created \n";
}

Scene::~Scene() {
    std::cout << "scene destructor called \n";
}
