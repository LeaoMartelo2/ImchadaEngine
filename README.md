# WARNING:
this readme is VERY VERY outdated, the project has been since re-written

# ImchadaEngine

A C++ Linux terminal game engine, based of a old [project of mine](https://github.com/LeaoMartelo2/makefile_git), inspired by ural89's [ConsoleCraftEngine](https://github.com/ural89/ConsoleCraftEngine)



## Compiling projects with the engine.

	soon™

## Rundown on how to use the Engine


This is a simple guide on how to use the engine in your project.

- Clone the repository in your working directory.

- Your game specific code goes in the `game_src` directory, keep in mind that you'll need to update the `Makefile` accordingly to your project.

	 - You need to include the engine headers in to your files, usually done by `#include "../engine/engine.h"`, `engine.h` being the main header of the engine itself.
	 - If you only need a specific part of the engine, make sure to only include the needed parts of it, to make your project more organized, and have faster build times as a result, make sure to update the relevant `Makefile`(s) accordingly.
	 
- **IF** you need to modify the engine itself to make it modular to your project, you can run `make update` to update the library. Keep in mind you'll need to update the relevant `Makefile`(s) to your changes.

