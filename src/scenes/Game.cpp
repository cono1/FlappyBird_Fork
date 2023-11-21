#include "Game.h"

#include <iostream>

using namespace std;

namespace game
{
void DrawObjects(Player player, Obstacle obstacle1, Obstacle obstacle2)
{
	DrawRectangle(static_cast<int>(player.posX), static_cast<int>(player.posY), player.width, player.height, player.color);

	DrawRectangle(static_cast<int>(obstacle1.posX), static_cast<int>(obstacle1.posY), obstacle1.width, obstacle1.height, ORANGE);

	DrawRectangle(static_cast<int>(obstacle2.posX), static_cast<int>(obstacle2.posY), obstacle2.width, obstacle2.height, ORANGE);
}

// dibuja el parallax
void DrawParallax(Texture2D& foreground, Texture2D& midground, float& scrollingFore, float& scrollingBack)
{
	DrawTextureEx(midground, Vector2{ scrollingBack, 20 }, 0.0f, 2.0f, WHITE);
	DrawTextureEx(midground, Vector2{ midground.width * 2 + scrollingBack, 20 }, 0.0f, 2.0f, WHITE);

	DrawTextureEx(foreground, Vector2{ scrollingFore, 0 }, 0.0f, 2.0f, WHITE);
	DrawTextureEx(foreground, Vector2{ foreground.width * 2 + scrollingFore, 0 }, 0.0f, 2.0f, WHITE);
}

// dibuja los obstaculos
void DrawObstacles(Obstacle& obstacle1, Obstacle& obstacle2)
{
	DrawTexture(obstacle1.obstacleUpTexture, static_cast<int>(obstacle1.posX), static_cast<int>(obstacle1.posY), WHITE);
	obstacle1.obstacleUpTexture.height = obstacle1.height;

	DrawTexture(obstacle2.obstacleDownTexture, static_cast<int>(obstacle2.posX), static_cast<int>(obstacle2.posY), WHITE);
	obstacle2.obstacleDownTexture.height = obstacle2.height;
}

// mov del jugador
void PlayerMovement(Player& player)
{
	if (IsKeyDown(KEY_W))
	{
		player.posY -= player.speed * GetFrameTime();

		player.color  = RED;

		DrawTexture(player.playerUp, static_cast<int>(player.posX), static_cast<int>(player.posY), WHITE);
	}

	else
	{
		player.posY += player.speed * GetFrameTime();

		player.color = YELLOW;

		DrawTexture(player.playerDown, static_cast<int>(player.posX), static_cast<int>(player.posY), WHITE);
	}
}

// el jugador no desaparece por arriba y avisa si se va para abajo
void PlayerScreenLimits(Player& player)
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

// mov del obst�culo
void ObstacleMovement(Obstacle& obstacle1, Obstacle& obstacle2, Player player)
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
	}
}

// colision del juagador con el obst�culo
bool PlayerObstacleCollision(Player& player, Obstacle& obstacle)
{
	if ((player.posX + player.width >= obstacle.posX) &&
		(player.posX <= obstacle.posX + obstacle.width) &&
		(player.posY + player.height >= obstacle.posY) &&
		(player.posY <= obstacle.posY + obstacle.height))
	{
		return true;
	}

	return false;
}

void ResetGame(Player& player, Obstacle& obstacle1, Obstacle& obstacle2, bool& returnToMenu)
{
	if (PlayerObstacleCollision(player, obstacle1) || player.fall ||
		PlayerObstacleCollision(player, obstacle2) || returnToMenu)
	{
		ResetPlayer(player);
		ResetObstacle(obstacle1, 0.0f, 300);
		ResetObstacle(obstacle2, static_cast<float>(GetScreenHeight() / 2 + player.height), GetScreenHeight());

		returnToMenu = false;
	}
}

void Update(Player& player, Obstacle& obstacle1, Obstacle& obstacle2,
	Texture2D& foreground, Texture2D& midground,
	float& scrollingFore, float& scrollingBack, bool returnToMenu)
{
	scrollingFore -= 100.0f * GetFrameTime();
	scrollingBack -= 50.0f * GetFrameTime();

	if (scrollingFore <= -foreground.width * 2) scrollingFore = 0;
	if (scrollingBack <= -midground.width * 2) scrollingBack = 0;

	DrawParallax(foreground, midground, scrollingFore, scrollingBack);

	DrawObjects(player, obstacle1, obstacle2);

	DrawObstacles(obstacle1, obstacle2);

	PlayerMovement(player);

	PlayerScreenLimits(player);

	ObstacleMovement(obstacle1, obstacle2, player);

	ResetGame(player, obstacle1, obstacle2, returnToMenu);
}
}