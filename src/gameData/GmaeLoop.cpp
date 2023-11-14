#include "GmaeLoop.h"

#include "scenes/Menu.h"
#include "scenes/Game.h"
#include "scenes/Credits.h"

#include "raylib.h"
#include <iostream>

using namespace std;

void InitAll(Player& player, Obstacle& obstacle1, Obstacle& obstacle2)
{
	srand(static_cast<unsigned int>(time(NULL)));

	const int screenWidth = 1080;
	const int screenHeight = 720;

	InitWindow(screenWidth, screenHeight, "Flappy Bird 0.1");

	InitPlayer(player);
	InitObstacle(obstacle1, 0.0f, 300);
	InitObstacle(obstacle2, static_cast<float>(GetScreenHeight() / 2 + player.height), GetScreenHeight());
}

// carga las texturas
void InitTextures(Texture2D& foreground, Texture2D& midground)
{
	foreground = LoadTexture("res/assets/background/cyberpunk_street_foreground.png");
	midground = LoadTexture("res/assets/background/cyberpunk_street_midground.png");
}

void GameLoop()
{
	Screen screen = Screen::MENU;

	Player player;

	Obstacle obstacle1;
	Obstacle obstacle2;

	Texture2D foreground;
	Texture2D midground;

	float scrollingFore = 0.0f;
	float scrollingMid = 0.0f;

	bool returnToMenu = false;

	InitAll(player, obstacle1, obstacle2);
	InitTextures(foreground, midground);	

	while (!WindowShouldClose())
	{
		SetExitKey(NULL);

		switch (screen)
		{
		case Screen::MENU:
			DrawMenu(screen);
			break;
		case Screen::GAME:
			Update(player,obstacle1,obstacle2,foreground,midground,scrollingFore,scrollingMid);
			break;
		case Screen::CREDITS:
			break;
		}

		BeginDrawing();

		switch (screen)
		{
		case Screen::MENU:
			break;
		case Screen::GAME:
			DrawObjects(player, obstacle1, obstacle2);
			DrawReturnButton(screen, returnToMenu);
			break;
		case Screen::CREDITS:
			DrawCredits();
			DrawReturnButton(screen, returnToMenu);
			break;
		}

		ClearBackground(DARKGREEN);

		EndDrawing();
	}

	UnloadTexture(foreground);

	CloseWindow();


}