#include "GameLoop.h"

#include <iostream>

#include "raylib.h"

#include "scenes/Menu.h"
#include "scenes/Game.h"
#include "scenes/Credits.h"
#include "scenes/Rules.h"
#include "scenes/EndScreen.h"
#include "scenes/Pause.h"
#include "objects/Parallax.h"
#include "objects/Score.h"

using namespace std;

namespace game
{
static Screen previousScreen;


void InitGame()
{
	srand(static_cast<unsigned int>(time(NULL)));

	const int screenWidth = 1024;
	const int screenHeight = 768;
	//Vector2 player1InitPos = { 50, screenHeight / 2 };
	//Vector2 player2InitPos = { player1InitPos.x + 80, player1InitPos.y };

	InitWindow(screenWidth, screenHeight, "Flappy Bird 0.3");

	//InitPlayer(player1, player1InitPos);
	//InitPlayer(player2, player2InitPos);
	//InitObstacle(obstacle1, 0.0f, 300);
	//InitObstacle(obstacle2, static_cast<float>(GetScreenHeight() / 2 + player1.height), GetScreenHeight());
	InitParallax();
}

void GameLoop()
{
	Screen screen = Screen::MENU;

	bool returnToMenu = false;

	InitGame();
	InitGameObjects();

	while (!WindowShouldClose())
	{
		SetExitKey(NULL);

		switch (screen)
		{
		case Screen::MENU:
			break;
		case Screen::SINGLEPLAYER:
			UpdateParallax();
			Update(returnToMenu, screen, true);
			previousScreen = Screen::SINGLEPLAYER;
			break;
		case Screen::MULTIPLAYER:
			UpdateParallax();
			Update(returnToMenu, screen, false);
			previousScreen = Screen::MULTIPLAYER;
			break;
		case Screen::RULES:
			break;
		case Screen::CREDITS:
			break;
		case Screen::PAUSE:
			break;
		case Screen::ENDSCREEN:
			break;
		}

		BeginDrawing();
		ClearBackground(DARKGREEN);

		bool singlePlayer = true;

		switch (screen)
		{
		case Screen::MENU:
			DrawMenu(screen);
			break;
		case Screen::SINGLEPLAYER:
			DrawParallax();
#ifdef _DEBUG
			DrawObjectsHitboxes();
#endif
			DrawObstacles();
			DrawPauseButton(screen);
			DrawPlayer(singlePlayer);
			DrawScore();
			break;
		case Screen::MULTIPLAYER:
			DrawParallax();
			DrawObstacles();
			DrawPauseButton(screen);
			DrawPlayer(!singlePlayer);
			DrawScore();
			break;
		case Screen::RULES:
			DrawReturnButton(screen, returnToMenu);
			DrawRules();
			break;
		case Screen::CREDITS:
			DrawCredits();
			DrawReturnButton(screen, returnToMenu);
			break;
		case Screen::PAUSE:
			DrawPauseScreen(screen, previousScreen, returnToMenu);
			break;
		case Screen::ENDSCREEN:
			DrawEndScreen(screen, previousScreen);
			break;
		}

		EndDrawing();
	}

	DeInitParallax();

	DeInitGame();

	CloseWindow();
}
}