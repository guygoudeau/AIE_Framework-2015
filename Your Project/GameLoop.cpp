#include "GameLoop.h" // include game loop header
#include "NewVectorLib.h" // include vector math library
#include <iostream> // include iostream library
#include <ctime> // include time library
using namespace std; // use std namespaces

SDL_Keycode key; // makes key to be pressed for switch statements
System::Point2D<int> rPosition1 = { 0, 200 }; // rectangle 1's position
System::Point2D<int> rPosition2 = { 0, 700 }; // rectangle 2's position
System::Color<int> rColor = { 50, 50, 255, 255 }; // rectangle 1's color
System::Color<int> rColor2 = { 50, 50, 255, 255 }; // rectangle 2's color
System::Point2D<int> cPosition = { 800, 600 }; // circle's position

Vectors <int> TwoD1(6, 9); // define 2D vector
Vectors <int> TwoD2(9, 6); // define 2D vector
Vectors <int> ThreeD1(-6, 50, 6); // define 3D vector
Vectors <int> ThreeD2(4, 2, 14); // define 3D vector
Vectors <int> Vec4(25, 30, 35, 255); // define 4D vector
int degrees = 360;

Vectors <int> twoAdded = TwoD1.twoAdd(TwoD2);
Vectors <int> twoSubbed = TwoD1.threeSub(TwoD2);
Vectors <int> threeAdded = ThreeD1.threeAdd(ThreeD2);
Vectors <int> threeSubbed = ThreeD1.threeSub(ThreeD2);
int twoMag = TwoD1.twoMagnitude();
int threeMag = ThreeD1.threeMagnitude();
Vectors <int> twoNorm = TwoD1.twoNormalize();
Vectors <int> threeNorm = ThreeD1.threeNormalize();
Vectors <int> vec4Norm = Vec4.v4Normalize();
int TwoDot = TwoD1.twoDotProd(TwoD2);
int ThreeDot = ThreeD1.threeDotProd(ThreeD2);
Vectors <int> twoCross = TwoD1.twoCrossProd(TwoD2);
Vectors <int> threeCross = ThreeD1.threeCrossProd(ThreeD2);


float currentTime = 0; // define float currentTime equal to 0
float previousTime = 0; // define float previousTime equal to 0
float deltaTime = 0; // define float deltaTime equal to 0

void GameLoop::Loop() // start the game
{
	while (m_bRunning) // While the game is running, do the following
	{
		SDL_Event sdlEvent; // Will hold the next event to be parsed

		while (m_bRunning) // While the game is running, do the following
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

			float div = 1000; // define float div equal to 1000
			float ct = clock(); //define float ct equal to system clock time
			currentTime = (float)ct / div; // currentTime equals ct * div
			deltaTime = currentTime - previousTime; // deltaTime equals currentTime - previousTime

			Update(); // run update function

			LateUpdate(); // run lateupdate function

			Draw(); // run draw function

			DrawGraph(); // run drawgraph function

			previousTime = currentTime; // set previousTime equal to currentTime

			Graphics::Flip(); // Required to update the window with all the newly drawn content
		}
	}
}

void GameLoop::DrawGraph() // draws graph function
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


	System::Point2D<int> cPosition2 = { 400, 600 }; // define circle 2's position
	for (int i = 0; i < 11; i++) // run loop 11 times, and for each loop
	{
		Graphics::DrawCircle(cPosition2, 5, 50, { 0, 255, 0, 255 }); // draw a small circle
		cPosition2.X += 50; // then add 50 to x
		cPosition2.Y -= 50; // then subtract 50 from y
	}


}

void GameLoop::Update() // Update function definition
{

	rPosition1.X++*deltaTime == currentTime; // change rectangle 1's position using deltatime
	rPosition1.X++*deltaTime == currentTime; // do the same thing to make it faster
	rColor.Blue = rPosition1.X; // set rectangle 1's blue value to be equal to it's x value
	if (rPosition1.X == 400) // if rectangle 1's x is a certain value
	{
		rColor = { 255, 50, 50, 255 }; // change the color values
	}
	if (rPosition1.X == 800) // if rectangle 1's x is a certain value
	{
		rColor = { 50, 255, 50, 255 }; // change the color values
	}
	if (rPosition1.X == 1200) // if rectangle 1's x is a certain value
	{
		rColor = { 50, 50, 255, 255 }; // change the color values
	}
	if (rPosition1.X == 1600) // if rectangle 1's x reaches the right edge of the screen
	{
		rPosition1.X = 0; // send it back to the left
	}

	rPosition2.X++*deltaTime == currentTime; // change rectangle 2's position using deltatime
	rColor2.Blue = rPosition2.X; // set rectangle 2's blue value to be equal to it's x value
	if (rPosition2.X == 400) // if rectangle 2's x is a certain value
	{
		rColor2 = { 255, 50, 50, 255 }; // change the color values
	}
	if (rPosition2.X == 800) // if rectangle 2's x is a certain value
	{
		rColor2 = { 50, 255, 50, 255 }; // change the color values
	}
	if (rPosition2.X == 1200) // if rectangle 2's x is a certain value
	{
		rColor2 = { 50, 50, 255, 255 }; // change the color values
	}
	if (rPosition2.X == 1600) // if rectangle 1's x reaches the right edge of the screen
	{
		rPosition2.X = 0; // send it back to the left
	}

	switch (key) // depending on the key pressed, change the case
	{
	case SDLK_p: // if p is pressed, display vector math from VectorMath.lib
		
		cout << "Add 2D vectors: ";
		twoAdded.twoPrint();
		cout << "Subtract 2D vectors: ";
		twoSubbed.twoPrint();
		cout << "Add 3D vectors: ";
		threeAdded.threePrint();
		cout << "Subtract 3D vectors: ";
		threeSubbed.threePrint();
		cout << "Magnitude of 2D vector: " << twoMag << endl;
		cout << "Magnitude of 3D vector: " << threeMag << endl;
		cout << "Normalized 2D vector: ";
		twoNorm.twoPrint();
		cout << "Normalized 3D vector: ";
		threeNorm.threePrint();
		cout << "Normalized 4D vector: ";
		vec4Norm.fourPrint();
		cout << "Dot product of 2D vectors: " << TwoDot << endl;
		cout << "Dot product of 3D vectors: " << ThreeDot << endl;
		cout << "Cross product of 2D vectors: ";
		twoCross.twoPrint();
		cout << "Cross product of 3D vectors: ";
		threeCross.threePrint();
		cout << "Degrees to radians: " << degToRad(degrees) << endl;
		
		break; // break case
	case SDLK_m: // if m is pressed
		std::cout << "Previous time: " << previousTime << std::endl; // output previous time and end line
		std::cout << "Current time: " << currentTime << std::endl; // output current time and end line
		std::cout << "Delta time: " << deltaTime << std::endl; // output delta time and end line
		break; // break case
	}
}
void GameLoop::LateUpdate() // run LateUpdate function
{
	key = KMOD_NONE; // no key is being pressed
}

void GameLoop::Draw() // run Draw function
{
	// Objects are drawn in a painter's layer fashion meaning the first object drawn is on the bottom, and the last one drawn is on the top
	// just like a painter would paint onto a canvas

	Graphics::DrawLine(rPosition1, { rPosition1.X, rPosition1.Y - 50 }, { 250, 250, 250, 255 }); //draw flagpole for rect1
	Graphics::DrawCircle({rPosition1.X+14, rPosition1.Y-75}, 30, 3, { 255, 0, 0, 255 }); // draw flag for rect1
	Graphics::DrawRect(rPosition1, {50, 50}, rColor); // draw rect1

	Graphics::DrawLine(rPosition2, { rPosition2.X, rPosition2.Y - 50 }, { 250, 250, 250, 255 }); //draw flagpole for rect2
	Graphics::DrawCircle({ rPosition2.X + 14, rPosition2.Y - 75 }, 30, 3, { 255, 0, 0, 255 }); // draw flag for rect2
	Graphics::DrawRect(rPosition2, { 50, 50 }, rColor2); // draw rect2

}

void GameLoop::OnKeyDown(const SDL_Keycode ac_sdlSym, const Uint16 ac_uiMod, const SDL_Scancode ac_sdlScancode) // function that happens when a key is pressed down
{
	
	switch (ac_sdlSym)
	{
	case SDLK_ESCAPE: m_bRunning = false; break; // End the loop
	default: printf("%s\n",SDL_GetKeyName(ac_sdlSym)); // print they key that's pressed
		key = ac_sdlSym;
		break; // break case
	}
}
void GameLoop::OnKeyUp(const SDL_Keycode ac_sdlSym, const Uint16 ac_uiMod, const SDL_Scancode ac_sdlScancode) // function that happens when a key is released
{
	switch (ac_sdlSym)
	{
	default: break; // break case
	}
}
void GameLoop::OnExit() // on exit of the loop
{
	m_bRunning = false; // End loop
}

GameLoop::GameLoop() // actual loop
{
	m_bRunning = true; // game running bool is true
}
GameLoop::~GameLoop() // idk blame ben
{

}
