#include "Game.h"

#include <iostream>

#include "scenes/EndScreen.h"
#include "objects/Score.h"

using namespace std;

namespace game
{
static Player player1;
static Player player2;
static Obstacle obstacle1;
static Obstacle obstacle2;

void MovePlayer(Player& player, KeyboardKey key);
void CheckPlayerScreenLimits(Player& player);
void MoveObstacles(Player player);
bool CheckPlayerObstacleCollision(Player& player, Obstacle& obstacle);
void ResetGame(Player& player, bool& returnToMenu, Screen& scene);

void InitGameObjects()
{
	Vector2 player1InitPos = { 80, static_cast<float>(GetScreenHeight()) / 2 };
	Vector2 player2InitPos = { player1InitPos.x - 80, player1InitPos.y };

	InitPlayer(player1, player1InitPos);
	InitPlayer(player2, player2InitPos);
	InitObstacle(obstacle1, 0.0f, 300);
	InitObstacle(obstacle2, static_cast<float>(GetScreenHeight() / 2 + player1.height), GetScreenHeight());
}

void DrawObjectsHitboxes()
{
	DrawRectangle(static_cast<int>(player1.posX), static_cast<int>(player1.posY), player1.width, player1.height, player1.color);

	DrawRectangle(static_cast<int>(obstacle1.posX), static_cast<int>(obstacle1.posY), obstacle1.width, obstacle1.height, ORANGE);

	DrawRectangle(static_cast<int>(obstacle2.posX), static_cast<int>(obstacle2.posY), obstacle2.width, obstacle2.height, ORANGE);
}

// dibuja los obstaculos
void DrawObstacles()
{
	DrawTexture(obstacle1.obstacleUpTexture, static_cast<int>(obstacle1.posX), static_cast<int>(obstacle1.posY), WHITE);
	obstacle1.obstacleUpTexture.height = obstacle1.height;

	DrawTexture(obstacle2.obstacleDownTexture, static_cast<int>(obstacle2.posX), static_cast<int>(obstacle2.posY), WHITE);
	obstacle2.obstacleDownTexture.height = obstacle2.height;
}

void DrawPlayer(bool isSinglePlayer)
{
	if (player1.isFlying)
	{
		DrawTexture(player1.playerUpTexture, static_cast<int>(player1.posX), static_cast<int>(player1.posY), WHITE);
	}
	else
	{
		DrawTexture(player1.playerDownTexture, static_cast<int>(player1.posX), static_cast<int>(player1.posY), WHITE);
	}

	if (!isSinglePlayer)
	{
		if (player2.isFlying)
		{
			DrawTexture(player2.playerUpTexture, static_cast<int>(player2.posX), static_cast<int>(player2.posY), WHITE);
		}
		else
		{
			DrawTexture(player2.playerDownTexture, static_cast<int>(player2.posX), static_cast<int>(player2.posY), WHITE);
		}
	}
}


void Update(bool& returnToMenu, Screen& scene, bool isSinglePlayer)
{
	MovePlayer(player1, KEY_SPACE);

	CheckPlayerScreenLimits(player1);

	MoveObstacles(player1);

	ResetGame(player1, returnToMenu, scene);

	if (!isSinglePlayer)
	{
		MovePlayer(player2, KEY_W);

		CheckPlayerScreenLimits(player2);

		MoveObstacles(player2);

		ResetGame(player2, returnToMenu, scene);
	}
}

// mov del jugador
void MovePlayer(Player& player, KeyboardKey key)
{
	if (IsKeyDown(key))
	{
		player.posY -= player.speed * GetFrameTime();

		player.color = RED;

		player.isFlying = true;		
	}
	else
	{
		player.posY += player.speed * GetFrameTime();

		player.color = YELLOW;

		player.isFlying = false;		
	}
}

// el jugador no desaparece por arriba y avisa si se va para abajo
void CheckPlayerScreenLimits(Player& player)
{
	if (player.posY <= 0)
	{
		player.posY = 0;
	}

	if (player.posY >= GetScreenHeight())
	{
		player.fall = true;
	}
}

// mov del obstáculo
void MoveObstacles(Player player)
{
	obstacle1.posX -= obstacle1.speed * GetFrameTime();
	obstacle2.posX -= obstacle2.speed * GetFrameTime();

	if (obstacle1.posX + obstacle1.width <= 0)
	{
		obstacle1.posX = obstacle1.initPosX;
		obstacle1.height = rand() % GetScreenHeight() - (player.height + player.height / 2);

		if (obstacle1.height <= 0)
		{
			obstacle1.height = 10;
		}
	}

	if (obstacle2.posX + obstacle2.width <= 0)
	{
		obstacle2.posX = obstacle2.initPosX;
		obstacle2.posY = static_cast<float>(obstacle1.height + player.height * 2);

		if (obstacle2.posY >= GetScreenHeight())
		{
			obstacle2.posY = static_cast<float>(GetScreenHeight() - 10);
		}

		AddScore();
	}
}

// colision del juagador con el obstáculo
bool CheckPlayerObstacleCollision(Player& player, Obstacle& obstacle)
{
	return ((player.posX + player.width >= obstacle.posX) &&
			(player.posX <= obstacle.posX + obstacle.width) &&
			(player.posY + player.height >= obstacle.posY) &&
			(player.posY <= obstacle.posY + obstacle.height));
}

void ResetGame(Player& player, bool& returnToMenu, Screen& scene)
{
	if (CheckPlayerObstacleCollision(player, obstacle1) || player.fall ||
		CheckPlayerObstacleCollision(player, obstacle2))
	{
		scene = Screen::ENDSCREEN;
		ResetPlayer(player);
		ResetObstacle(obstacle1, 0.0f, 300);
		ResetObstacle(obstacle2, static_cast<float>(GetScreenHeight() / 2 + player.height), GetScreenHeight());

		returnToMenu = false;
	}
}

void DeInitGame()
{
	DeInitObstacle(obstacle1);
	DeInitObstacle(obstacle2);

	DeInitPlayer(player1);
	DeInitPlayer(player2);
}
}