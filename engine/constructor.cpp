#include "engine.hpp"
#include <iostream>

Instance::Instance(int argc, char *argv[]) {

    std::cout << "Instance Constructor Called! \n";

    // just making sure it initializes as 0
    m_Logging = false;
    m_isDebug = false;

    process_arguments(argc, argv);

    imchada_log("########## Imchada Engine Instance Created ##########", IMCHADA_MESSAGE);

    if (m_isDebug) {
        imchada_log("Instance initialized with debug mode enabled", IMCHADA_WARN);
        /*std::cout << "Hello, World from Instance constructor in debug mode\n";*/
    }
}

Instance::~Instance() {

    imchada_log("########## Imchada Engine Instance Destroyed ##########", IMCHADA_MESSAGE);
}
