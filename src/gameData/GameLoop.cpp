#include "GameLoop.h"

#include <iostream>

#include "raylib.h"

#include "scenes/Menu.h"
#include "scenes/Game.h"
#include "scenes/Credits.h"
#include "scenes/Rules.h"
#include "objects/Parallax.h"

using namespace std;

namespace game
{
void InitAll(Player& player1, Player& player2, Obstacle& obstacle1, Obstacle& obstacle2)
{
	srand(static_cast<unsigned int>(time(NULL)));

	const int screenWidth = 1024;
	const int screenHeight = 768;
	Vector2 player1InitPos = { 50, screenHeight / 2 };
	Vector2 player2InitPos = { player1InitPos.x + 80, player1InitPos.y };

	InitWindow(screenWidth, screenHeight, "Flappy Bird 0.3");

	InitPlayer(player1, player1InitPos);
	InitPlayer(player2, player2InitPos);
	InitObstacle(obstacle1, 0.0f, 300);
	InitObstacle(obstacle2, static_cast<float>(GetScreenHeight() / 2 + player1.height), GetScreenHeight());
	InitParallax();
}

void GameLoop()
{
	Screen screen = Screen::MENU;

	Player player1;
	Player player2;

	Obstacle obstacle1;
	Obstacle obstacle2;

	bool returnToMenu = false;

	InitAll(player1, player2, obstacle1, obstacle2);

	while (!WindowShouldClose())
	{
		SetExitKey(NULL);

		switch (screen)
		{
		case Screen::MENU:
			break;
		case Screen::SINGLEPLAYER:
			UpdateParallax();
			Update(player1, obstacle1, obstacle2, returnToMenu);
			break;
		case Screen::MULTIPLAYER:
			UpdateParallax();
			Update(player1, player2, obstacle1, obstacle2, returnToMenu);
			break;
		case Screen::RULES:
			break;
		case Screen::CREDITS:
			break;
		}

		BeginDrawing();
		ClearBackground(DARKGREEN);

		switch (screen)
		{
		case Screen::MENU:
			DrawMenu(screen);
			break;
		case Screen::SINGLEPLAYER:
			DrawParallax();
#ifdef _DEBUG
			DrawObjectsHitboxes(player1, obstacle1, obstacle2);
#endif
			DrawObstacles(obstacle1, obstacle2);
			GameDrawReturnButton(screen, returnToMenu);
			DrawPlayer(player1);
			DrawScore();
			break;
		case Screen::MULTIPLAYER:
			DrawParallax();
			DrawObstacles(obstacle1, obstacle2);
			GameDrawReturnButton(screen, returnToMenu);
			DrawPlayer(player1);
			DrawPlayer(player2);
			DrawScore();
			break;
		case Screen::RULES:
			GameDrawReturnButton(screen, returnToMenu);
			DrawRules();
			break;
		case Screen::CREDITS:
			DrawCredits();
			GameDrawReturnButton(screen, returnToMenu);
			break;
		}

		EndDrawing();
	}

	DeInitParallax();

	DeInitObstacle(obstacle1);
	DeInitObstacle(obstacle2);

	DeInitPlayer(player1);
	DeInitPlayer(player2);

	CloseWindow();
}
}