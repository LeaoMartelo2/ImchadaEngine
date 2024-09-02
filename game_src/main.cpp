#include "../engine/engine.hpp"
#include "include/example.hpp"
#include <iostream>
#include <memory>

int main(int argc, char **argv) {

    /*std::cout << "Before the scope\n";*/
    // std::unique_ptr<Imchada::Instance> ImchadaInstance = setupImchadaEngine(argc, argv);
    /*{
        std::unique_ptr<Imchada::Instance> ImchadaInstance = std::make_unique<Imchada::Instance>(argc, argv);

        hello_world();
        std::cout << "hello world from main\n";

        std::cout << "Debug state: " << ImchadaInstance->get_debug_state() << std::endl;

        std::cout << "Swapping debug state\n";

        ImchadaInstance->set_debug(!ImchadaInstance->get_debug_state());

        std::cout << "Debug state: " << ImchadaInstance->get_debug_state() << std::endl;

        ImchadaInstance->imchada_log("message log", LOG_MESSAGE);
        ImchadaInstance->imchada_log("warn log", LOG_WARN);
        ImchadaInstance->imchada_log("error log", LOG_ERROR);
    }*/

    /*std::cout << "Outside the scope\n";*/

    /*std::cin.get();*/

    /*attempt #1 of trying the schizo api method, where you hallucinate how you wanna use the API/lib first
     * and then you figure out implement it (its gonna suck bad) */

    return 0;
}
