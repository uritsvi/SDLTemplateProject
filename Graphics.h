#pragma once

#include <SDL.h>

#include <string>

class Graphics
{
public:
	Graphics();
	~Graphics();

	bool Show(
		_In_ const std::string& AppName,
		_In_ int W, 
		_In_ int H);

	SDL_Renderer* m_Renderer;


private:
	SDL_Window* m_Window;
};

