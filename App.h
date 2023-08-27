#pragma once

#include <memory>

#include "Graphics.h"

class App
{
public:
	App();
	~App();

	void Run();

private:
	void PollEvents();

private:
	std::shared_ptr<Graphics> m_Graphics;
	bool m_Running;
};

