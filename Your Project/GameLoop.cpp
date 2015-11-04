#include "GameLoop.h"
#include "VectorLib.h"
#include <iostream>

SDL_Keycode key;
System::Point2D<int> Position = { 800, 450 };

Vectors<int> ThreeD1(2, 3, 4);
Vectors<int> ThreeD2(5, 6, 7);
Vectors<int> ThreeDAdd = ThreeD1 + ThreeD2;

void GameLoop::Loop()
{
	while (m_bRunning)
	{
		SDL_Event sdlEvent; // Will hold the next event to be parsed

		while (m_bRunning)
		{
			// Events get called one at a time, so if multiple things happen in one frame, they get parsed individually through 'SDL_PollEvent'
			// The next event to parse gets stored into 'sdlEvent', and then passed to the 'EventHandler' class which will call it's appropriate function here
			// 'SDL_PollEvent' returns 0 when there are no more events to parse
			while (SDL_PollEvent(&sdlEvent))
			{
				// Calls the redefined event function for the EventHandler class
				// Refer to its header file and cpp for more information on what each inherited function is capable of
				// and its syntax
				OnEvent(sdlEvent);
			}
			Update();

			LateUpdate();

			Draw();

			Graphics::Flip(); // Required to update the window with all the newly drawn content
		}
	}
}

void GameLoop::Update()
{
	switch (key)
	{
	case SDLK_UP:
		Position.Y -= 7;
		break;
	
	case SDLK_DOWN:
		Position.Y += 7;
		break;

	case SDLK_LEFT:
		Position.X -= 7;
		break;
	
	case SDLK_RIGHT:
		Position.X += 7;
		break;
	case SDLK_p:
		std::cout << "(" << ThreeDAdd.x << "," << ThreeDAdd.y << "," << ThreeDAdd.z << ")";
		break;
	}
}
void GameLoop::LateUpdate()
{
	key = KMOD_NONE;
}

void GameLoop::Draw()
{
	// Objects are drawn in a painter's layer fashion meaning the first object drawn is on the bottom, and the last one drawn is on the top
	// just like a painter would paint onto a canvas

	Graphics::DrawRect({ 200, 200 }, {50, 50}, {250, 250, 250, 255});
	Graphics::DrawCircle(Position, 200, 50, { 50, 250, 50, 255 });
}

void GameLoop::OnKeyDown(const SDL_Keycode ac_sdlSym, const Uint16 ac_uiMod, const SDL_Scancode ac_sdlScancode)
{
	
	switch (ac_sdlSym)
	{
	case SDLK_ESCAPE: m_bRunning = false; break; // End the loop

	default: printf("%s\n",SDL_GetKeyName(ac_sdlSym));
		key = ac_sdlSym;
		break;
	}
}
void GameLoop::OnKeyUp(const SDL_Keycode ac_sdlSym, const Uint16 ac_uiMod, const SDL_Scancode ac_sdlScancode)
{
	switch (ac_sdlSym)
	{
	default: break;
	}
}
void GameLoop::OnExit()
{
	m_bRunning = false; // End the loop
}

GameLoop::GameLoop()
{
	m_bRunning = true;
}
GameLoop::~GameLoop()
{

}
