#include "scene.hpp"
#include <iostream>

Scene::Scene() {
    std::cout << "Scene created \n";
}

Scene::~Scene() {
    std::cout << "scene destructor called \n";
}

void Scene::load() {

    std::cout << "Pretend this loaded a scene\n";
}
