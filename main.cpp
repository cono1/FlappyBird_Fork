#include "raylib.h"

int main()
{
	const int screenWidth = 1080;
	const int screenHeight = 720;

	InitWindow(screenWidth, screenHeight, "Flappy Bird");

	while(!WindowShouldClose())
	{
		SetExitKey(NULL);
	}

	return 0;
}