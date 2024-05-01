# ImchadaEngine

A C++ Linux terminal game engine, based of a old [project of mine](https://github.com/LeaoMartelo2/makefile_git), inspired by ural89's [ConsoleCraftEngine](https://github.com/ural89/ConsoleCraftEngine)



## Compiling projects with the engine.

	soon™

## Rundown on how to use the Engine


This is a simple guide on how to use the engine in your project.

- Clone the engine repository in the directory you want to work with your project in, as this is also a workspace for the engine.
- In the `"game"` directory, you will add your own code, sprites, scripts for the game using the engine.

- Games using the Engine must include the "master" engine header (`#include "../engine/ImchadaEngine.h"`).

- If you do not wish to  include the whole engine on your project, you can do so following the example bellow. Keep in mind that you will need to update the `Makefile` accordingly after doing so.

	 `#include "../engine/example.h"` 
	 ##### ( game/src/main.cpp used as example file)


- Adjust the Makefile to your project.


- Modify/Delete/Add engine files as you please/require for your project, don't be afraid to re-make it entirely if needed.


- Clean up the Makefile for faster compile times **(important)**.
