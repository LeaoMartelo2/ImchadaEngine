#include "../engine/engine.hpp"
#include "include/example.hpp"
#include <iostream>

int main(int argc, char **argv) {

    /*attempt #1 of trying the schizo api method, where you hallucinate how you wanna use the API/lib first
     * and then you figure out implement it (its gonna suck bad) */

    Instance ImchadaInstance(argc, argv);

    std::cout << "Hello world from Main game file\n";
    hello_world();

    std::cout << "Initialized debug state: " << ImchadaInstance.get_debug_state() << std::endl;
    std::cout << "Flipping debug state\n";
    ImchadaInstance.set_debug(!ImchadaInstance.get_debug_state());
    std::cout << "Current debug state: " << ImchadaInstance.get_debug_state() << std::endl;

    ImchadaInstance.imchada_log("MESSAGE LOG", IMCHADA_MESSAGE);
    ImchadaInstance.imchada_log("WARN LOG", IMCHADA_WARN);
    ImchadaInstance.imchada_log("ERROR LOG", IMCHADA_ERROR);

    return 0;
}
