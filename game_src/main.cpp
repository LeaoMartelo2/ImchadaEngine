#include "../engine/engine.hpp"
#include "include/example.hpp"
#include <iostream>
#include <memory>

int main(int argc, char **argv) {

    /*attempt #1 of trying the schizo api method, where you hallucinate how you wanna use the API/lib first
     * and then you figure out implement it (its gonna suck bad) */
    {
        std::shared_ptr<Instance> ImchadaInstance = std::make_shared<Instance>(argc, argv);

        /* test if the game include headers are ok*/
        std::cout << "Hello world from Main game file\n";
        hello_world();

        /* test if checking/setting a Instance variable works correctly */
        std::cout << "Initialized debug state: " << ImchadaInstance->get_debug_state() << std::endl;
        std::cout << "Flipping debug state\n";
        ImchadaInstance->set_debug(!ImchadaInstance->get_debug_state());
        std::cout << "Current debug state: " << ImchadaInstance->get_debug_state() << std::endl;

        /* test if logging system works correctly */
        ImchadaInstance->imchada_log("MESSAGE LOG", IMCHADA_MESSAGE);
        ImchadaInstance->imchada_log("WARN LOG", IMCHADA_WARN);
        ImchadaInstance->imchada_log("ERROR LOG", IMCHADA_ERROR);

        /* temp hack to check for Scene impelementation */
        auto scenePtr1 = std::make_shared<Scene>();
        auto scenePtr2 = std::make_shared<Scene>();

        ImchadaInstance->add_scene(scenePtr1);
        ImchadaInstance->add_scene(scenePtr2);

        std::cout << "Ammound of scenes added to current instance: "
                  << ImchadaInstance->get_scene_count() << std::endl;

        ImchadaInstance->load_scene(1);

        /*lets hope all scenes get their destructors called*/
    }

    return 0;
}
