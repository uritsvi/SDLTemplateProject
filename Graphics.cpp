#include "Graphics.h"
#include "Utils.h"

Graphics::Graphics() {
	SDL_Init(SDL_INIT_VIDEO);

	m_Window = nullptr;
	m_Renderer = nullptr;
}

Graphics::~Graphics() {

}

bool Graphics::Show(
	_In_ const std::string& AppName,
	_In_ int W, 
	_In_ int H) {
	
	m_Window = SDL_CreateWindow(
		AppName.c_str(), 
		SDL_WINDOWPOS_CENTERED,
		SDL_WINDOWPOS_CENTERED,
		W, 
		H, 
		0);

	if (m_Window == nullptr) {
		Utils::Error("Failed to create a window");
		return false;
	}

	m_Renderer = SDL_CreateRenderer(
		m_Window, 
		-1, 
		0);

	if (m_Renderer == nullptr) {
		Utils::Error("Failed to create renderer");
		return false;
	}

	return true;
}