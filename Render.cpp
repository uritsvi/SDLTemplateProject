#include <SDL_image.h>

#include "Utils.h"
#include "Render.h"

#pragma comment(lib, "SDL2_Image.lib")

Render::Render(_In_ const RenderInfo& Info) {
	m_Surface = nullptr;

	m_TargerWidth = Info.Width;
	m_TargerHeight = Info.Height;
}
Render::~Render() {
	if (m_Surface) {
		//SDL_FreeSurface(m_Surface);
	}
}

bool Render::Load(_In_ const char* Path) {
	
	m_Surface = IMG_Load(Path);
	if (m_Surface == nullptr) {
		return false;
	}

	return true;
}

bool Render::Draw(
	_In_ SDL_Renderer* Target,
	_In_ const Vec2& Position,
	_In_ const Vec2& Scale,
	_In_ float Angle) {

	auto texture = SDL_CreateTextureFromSurface(
		Target, 
		m_Surface);
	if (texture == nullptr) {
		Utils::Error("Failed to create a texture");
		return false;
	}

	SDL_Rect dest;
	MakeRenderRect(
		Position, 
		Scale, 
		dest);

	auto res = SDL_RenderCopyEx(Target,
		texture,
		nullptr,
		&dest,
		Angle, 
		nullptr, 
		SDL_FLIP_NONE);
	
	SDL_DestroyTexture(texture);
	
	if (res != 0) {
		Utils::Error("Failed to render to a surface");
		return false;
	}

	return true;
}

void Render::MakeRenderRect(
	_In_ const Vec2& Position,
	_In_ const Vec2& Scale,
	_Out_ SDL_Rect& Rect) {

	Vec2 position = Position;
	Vec2 scale = Scale;
	Vec2 scaledPosition = position + scale;
	

	float wDevToh = (float)m_TargerWidth / m_TargerHeight;
	float hDevTow = 1;

	Project(
		position, 
		-2.0f, 
		2.0f, 
		1.5f, 
		-1.5f);
	Project(
		scaledPosition,
		-wDevToh,
		wDevToh,
		hDevTow,
		-hDevTow);
	
	float x = (position.x - scaledPosition.x + 1) / 2.0f;
	float y = (-position.y - scaledPosition.y + 1) / 2.0f;

	Rect.x = (int)(x * m_TargerWidth);
	Rect.y = (int)(y* m_TargerHeight);
	Rect.w = (int)((scaledPosition.x - position.x) * m_TargerWidth);
	Rect.h = (int)((scaledPosition.y - position.y) * m_TargerHeight);


	return;
}

void Render::Project(
	_Inout_ Vec2& inputVector, 
	_In_ float Left,
	_In_ float Right,
	_In_ float Top,
	_In_ float Bottom) {
	
	inputVector.x = (2.0f * inputVector.x) / (Right - Left) - (Right + Left) / (Right - Left);
	inputVector.y = (2.0f * inputVector.y) / (Top- Bottom) - (Top + Bottom) / (Top - Bottom);
}