#include "../engine/engine.hpp"
#include <iostream>
#include <memory>

int main(int argc, char **argv) {

    /*attempt #1 of trying the schizo api method, where you hallucinate how you wanna use the API/lib first
     * and then you figure out implement it (its gonna suck bad) */
    {
        auto ImchadaInstance = std::make_shared<Instance>(argc, argv);

        /*test if logging system works correctly */
        ImchadaInstance->imchada_log(IMCHADA_MESSAGE, "This is a Message log");
        ImchadaInstance->imchada_log(IMCHADA_WARN, "This is a Warn log");
        ImchadaInstance->imchada_log(IMCHADA_ERROR, "This is a Error log");
        ImchadaInstance->imchada_log(IMCHADA_DEBUG,
                                     "This is a Debug log, you shoud only be seeing this if you used -debug");

        int scene_id = ImchadaInstance->create_scene("assets/maps/testmap");

        ImchadaInstance->load_scene(scene_id);
    }

    std::cout << "Press enter to exit\n";
    std::cin.get();

    return 0;
}
