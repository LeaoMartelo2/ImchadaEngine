#include "engine.hpp"
#include <iostream>

Instance::Instance(int argc, char *argv[]) {

    std::cout << "Instance Constructor Called! \n";

    // just making sure it initializes as 0
    m_Logging = false;
    m_isDebug = false;

    process_arguments(argc, argv);

    imchada_log(IMCHADA_MESSAGE, "########## Imchada Engine Instance Created ##########");

    if (m_isDebug) {
        imchada_log(IMCHADA_WARN, "Instance initialized with debug mode enabled");
        /*std::cout << "Hello, World from Instance constructor in debug mode\n";*/
    }
}

Instance::~Instance() {

    imchada_log(IMCHADA_MESSAGE, "########## Imchada Engine Instance Destroyed ##########");
}
