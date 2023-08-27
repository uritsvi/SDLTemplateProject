#pragma once

#include <SDL.h>

struct Vec2{
	float x;
	float y;

	Vec2 operator +(Vec2& a) {
		return Vec2{ x + a.x, y + a.y };
	}
};

struct RenderInfo {
	int Width;
	int Height;
};

class Render
{
public:
	Render(
		_In_ const RenderInfo& Info);
	~Render();


	bool Load(_In_ const char* Path);

	/*
	* The Position arg is a vec2 in the rage of 
	* -1.0f to 1.0f in x and y
	*/
	bool Draw(
		_In_ SDL_Renderer* Target, 
		_In_ const Vec2& Position,
		_In_ const Vec2& Scale,
		_In_ float Angle);


	void MakeRenderRect(
		_In_ const Vec2& Position,
		_In_ const Vec2& Scale, 
		_Out_ SDL_Rect& Rect);

	void Project(
		_Inout_ Vec2& P, 
		_In_ float Left, 
		_In_ float Right, 
		_In_ float Top, 
		_In_ float Bottom);

private:
	SDL_Surface* m_Surface;

	int m_TargerWidth;
	int m_TargerHeight;
};

