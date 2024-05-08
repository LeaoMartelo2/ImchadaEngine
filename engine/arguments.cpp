#include "engine.h"
#include <cstring>

namespace Imchada {

void process_arguments(const Instance &Current, int argc, char *argv[]);

/* add your custom - arguments here */
const int amm_of_args = 4;

const char *argument_comparelist[] = {"-debug", "-verbose", "-log", "-example"};

/*
for (int i = 0; i < argc; i++) {
  for (int j = 0; i < amm_of_args; i++) {
    if (strcmp(argv[i], arguments_comparelist[j]) == 0)
  }
}
*/
} // namespace Imchada
