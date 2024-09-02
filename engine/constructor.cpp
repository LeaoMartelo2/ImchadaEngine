#include "engine.hpp"
#include <iostream>

Instance::Instance(int argc, char *argv[]) {

    std::cout << "Constructor Called! \n";

    m_Logging = false;
    m_isVerbose = false;
    m_isDebug = false;

    process_arguments(argc, argv);

    imchada_log("########## Imchada Engine Instance Created ##########", IMCHADA_MESSAGE);

    if (Instance::get_debug_state()) {
        imchada_log("DEBUG MODE ENABLED", IMCHADA_WARN);
        std::cout << "Hello, World from Instance constructor in debug mode\n";
    }
}

Instance::~Instance() {

    imchada_log("########## Imchada Engine Instance Destroyed ##########", IMCHADA_MESSAGE);

    std::cout << "Instance destructor called test\n";
}
