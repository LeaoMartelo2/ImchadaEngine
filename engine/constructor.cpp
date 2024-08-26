#include "engine.hpp"
#include <iostream>

namespace Imchada {

Instance::Instance(int argc, char *argv[]) {

    std::cout << "Constructor Called! \n";

    m_Logging = false;
    m_isVerbose = false;
    m_isDebug = false;

    process_arguments(argc, argv);

    imchada_log("########## Imchada Engine Instance Created ##########", LOG_MESSAGE);

    if (Instance::get_debug_state()) {
        imchada_log("DEBUG MODE ENABLED", LOG_MESSAGE);
    }
}

} // namespace Imchada
