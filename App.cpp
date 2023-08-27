#include <string>

#include "App.h"
#include "Render.h"

const std::string AppName = "Animation";


App::App() {
	m_Graphics =
		std::make_shared<Graphics>();

}

App::~App() {

}

void App::PollEvents() {
	SDL_Event event;
	while (SDL_PollEvent(&event)) {

		switch (event.type) {
		case SDL_QUIT: m_Running = false; break;
		}
	}
}

void App::Run() {	

	SDL_Rect display;
	SDL_GetDisplayBounds(
		0,
		&display);

	
	int w = (display.w / 2);
	int h = (display.h / 2);
	
	m_Graphics->Show(
		AppName,
		w,
		h);

	auto info = RenderInfo{w, h};
	auto render = Render(info);

	auto res = render.Load("b.png");
	if (!res) {
		int a = 0;
	}




	m_Running = true;
	while (m_Running) {
		PollEvents();

		SDL_RenderClear(m_Graphics->m_Renderer);

		SDL_SetRenderDrawColor(m_Graphics->m_Renderer, 255, 255, 255, 255);

		render.Draw(m_Graphics->m_Renderer, {0.0f, 0.0f}, {0.5f, 0.5f}, 0);


		SDL_RenderPresent(m_Graphics->m_Renderer);

	}

}