#include "../engine/engine.hpp"
#include <iostream>
#include <memory>

int main(int argc, char **argv) {

    {
        auto ImchadaInstance = std::make_shared<Instance>(argc, argv);

        /*Scene first_scene = load_map("assets/maps/testmap");*/

        /*test if logging system works correctly */
        ImchadaInstance->imchada_log(IMCHADA_MESSAGE, "This is a Message log");
        ImchadaInstance->imchada_log(IMCHADA_WARN, "This is a Warn log");
        ImchadaInstance->imchada_log(IMCHADA_ERROR, "This is a Error log");
        ImchadaInstance->imchada_log(IMCHADA_DEBUG,
                                     "This is a Debug log, you shoud only be seeing this if you used -debug");

        std::cout << "before create\n";

        int scene_id = ImchadaInstance->create_scene("assets/maps/testmap");

        std::cout << "after create\n";

        ImchadaInstance->load_scene(scene_id);

        std::cout << "after load\n";
    }

    std::cout << "Press enter to exit\n";
    std::cin.get();

    return 0;
}
