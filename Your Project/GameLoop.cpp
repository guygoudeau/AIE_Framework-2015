#include "GameLoop.h"
#include "VectorLib.h"
#include <iostream>
#include <ctime>

SDL_Keycode key;
System::Point2D<int> rPosition1 = { 0, 200 };
System::Point2D<int> rPosition2 = { 0, 700 };
System::Color<int> rColor = { 50, 50, 255, 255 };
System::Color<int> rColor2 = { 50, 50, 255, 255 };
System::Point2D<int> cPosition = { 800, 600 };

Vectors<int> ThreeD1(2, 3, 4);
Vectors<int> ThreeD2(5, 6, 7);
Vectors<int> ThreeDAdd = ThreeD1 + ThreeD2;
float currentTime = 0;
float previousTime = 0;
float deltaTime = 0;

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

			float div = 1000;
			float ct = clock();
			currentTime = (float)ct / div;
			deltaTime = currentTime - previousTime;

			///Update();
			///LateUpdate();
			///Draw();
			///Graphics::Draw();*

			DrawGraph();

			previousTime = currentTime;

			Graphics::Flip(); // Required to update the window with all the newly drawn content
		}
	}
}

void GameLoop::DrawGraph() // draws graph
{
	Graphics::DrawLine({ 400, 600 }, { 900, 600 }, { 0, 0, 255, 255 }); // x line
	Graphics::DrawLine({ 400, 600 }, { 400, 100 }, { 0, 0, 255, 255 }); // y line

	float x = 400; // beginning x position of intervals
	for (int i = 0; i < 10; i++) // i = number of intervals
	{
		x += 50; // space between each interval, plus means going right
		Graphics::DrawLine({ x, 590 }, { x, 610 }, { 255, 0, 0, 255 }); // x intervals
	}

	float y = 600; // beginning y position of intervals
	for (int i = 0; i < 10; i++) // i = number of intervals
	{
		y -= 50; // space between each interval, minus means going up
		Graphics::DrawLine({ 390, y }, { 410, y }, { 255, 0, 0, 255 }); // y intervals
	}
}

void GameLoop::Update()
{

	rPosition1.X++*deltaTime == currentTime;
	rPosition1.X++*deltaTime == currentTime;
	rColor.Blue = rPosition1.X;
	if (rPosition1.X == 400)
	{
		rColor = { 255, 50, 50, 255 };
	}
	if (rPosition1.X == 800)
	{
		rColor = { 50, 255, 50, 255 };
	}
	if (rPosition1.X == 1200)
	{
		rColor = { 50, 50, 255, 255 };
	}
	if (rPosition1.X == 1600)
	{
		rPosition1.X = 0;
	}

	rPosition2.X++*deltaTime == currentTime;
	rColor2.Blue = rPosition2.X;
	if (rPosition2.X == 400)
	{
		rColor2 = { 255, 50, 50, 255 };
	}
	if (rPosition2.X == 800)
	{
		rColor2 = { 50, 255, 50, 255 };
	}
	if (rPosition2.X == 1200)
	{
		rColor2 = { 50, 50, 255, 255 };
	}
	if (rPosition2.X == 1600)
	{
		rPosition2.X = 0;
	}

	switch (key)
	{
	case SDLK_UP:
		cPosition.Y -= 10;
		Crunch->Pos.Y -= 10;
		break;
	
	case SDLK_DOWN:
		cPosition.Y += 10;
		Crunch->Pos.Y += 10;
		break;

	case SDLK_LEFT:
		cPosition.X -= 10;
		Crunch->Pos.X -= 10;
		break;
	
	case SDLK_RIGHT:
		cPosition.X += 10;
		Crunch->Pos.X += 10;
		break;
	case SDLK_p:
		std::cout << "(" << ThreeDAdd.x << "," << ThreeDAdd.y << "," << ThreeDAdd.z << ")";
		break;
	case SDLK_m:
		std::cout << "Previous time: " << previousTime << std::endl;
		std::cout << "Current time: " << currentTime << std::endl;
		std::cout << "Delta time: " << deltaTime << std::endl;
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

	Graphics::DrawRect({ 0, 0 }, {1600, 1600}, { 50, 50, 250, 255 });
	Graphics::DrawLine(rPosition1, { rPosition1.X, rPosition1.Y - 50 }, { 250, 250, 250, 255 });
	Graphics::DrawCircle({rPosition1.X+14, rPosition1.Y-75}, 30, 3, { 255, 0, 0, 255 });
	Graphics::DrawRect(rPosition1, {50, 50}, rColor);

	Graphics::DrawLine(rPosition2, { rPosition2.X, rPosition2.Y - 50 }, { 250, 250, 250, 255 });
	Graphics::DrawCircle({ rPosition2.X + 14, rPosition2.Y - 75 }, 30, 3, { 255, 0, 0, 255 });
	Graphics::DrawRect(rPosition2, { 50, 50 }, rColor2);

	Graphics::DrawCircle(cPosition, 200, 50, { 255, 255, 0, 255 });
	Graphics::DrawCircle(cPosition, 180, 50, { 225, 165, 0, 255 });

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
	Crunch = Graphics::LoadSurface<int>("Images/CapnC.png");
}
GameLoop::~GameLoop()
{

}
