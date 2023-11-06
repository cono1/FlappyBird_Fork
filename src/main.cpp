#include "objects/Player.h"

#include "raylib.h"

int main()
{
	const int screenWidth = 1080;
	const int screenHeight = 720;

	Player player;

	InitWindow(screenWidth, screenHeight, "Flappy Bird");

	InitPlayer(player);

	while(!WindowShouldClose())
	{
		SetExitKey(NULL);

		BeginDrawing();

		DrawRectangle(player.posX, player.posY, player.width, player.height, RED);

		ClearBackground(DARKGREEN);
		
		EndDrawing();
	}

	CloseWindow();

	return 0;
}