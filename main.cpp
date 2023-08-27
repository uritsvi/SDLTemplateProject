#include <SDL.h>

#include "App.h"

#pragma comment(lib, "SDL2.lib")
#pragma comment(lib, "SDL2main.lib")


int main(int argc, char* argv[]) {
	
	App app;
	app.Run();

	return 0;
}