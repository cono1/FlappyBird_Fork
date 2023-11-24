#include "EndScreen.h"

#include <string>

#include "raylib.h"

#include "Game.h"
#include "objects/Score.h"

namespace game
{
void DrawEndScreen(Screen& screen, Screen previousScreen)
{
	int scoreSize = 40;
	int playAgainSize = 65;

	std::string scoreText = "SCORE: " + std::to_string(GetScore());
	std::string hiScoreText = "HIGH SCORE: " + std::to_string(GetHiScore());
	std::string playAgainText = "PLAY AGAIN";
	std::string menuText= "Menu";

	Vector2 scoreTextPos = { GetScreenWidth() / 2 - static_cast<float>(MeasureText(scoreText.c_str(), scoreSize)) / 2, static_cast<float>(GetScreenHeight()) / 3 };
	Vector2 hiScoreTextPos = { GetScreenWidth() / 2 - static_cast<float>(MeasureText(hiScoreText.c_str(), scoreSize)) / 2, scoreTextPos.y + 50 };
	Vector2 playAgainTextPos = { GetScreenWidth() / 2 - static_cast<float>(MeasureText(playAgainText.c_str(), playAgainSize)) / 2, hiScoreTextPos.y + 80 };
	Vector2 menuTextPos = { GetScreenWidth() / 2 - static_cast<float>(MeasureText(menuText.c_str(), scoreSize)) / 2, playAgainTextPos.y + 80 };

	DrawText(scoreText.c_str(), static_cast<int>(scoreTextPos.x), static_cast<int>(scoreTextPos.y), scoreSize, WHITE);
	DrawText(hiScoreText.c_str(), static_cast<int>(hiScoreTextPos.x), static_cast<int>(hiScoreTextPos.y), scoreSize, WHITE);
	DrawText(playAgainText.c_str(), static_cast<int>(playAgainTextPos.x), static_cast<int>(playAgainTextPos.y), playAgainSize, WHITE);
	DrawText(menuText.c_str(), static_cast<int>(menuTextPos.x), static_cast<int>(menuTextPos.y), scoreSize, WHITE);


	if (GetMousePosition().x >= playAgainTextPos.x &&
		GetMousePosition().x <= playAgainTextPos.x + MeasureText(playAgainText.c_str(), playAgainSize) &&
		GetMousePosition().y >= playAgainTextPos.y &&
		GetMousePosition().y <= playAgainTextPos.y + MeasureTextEx(GetFontDefault(), playAgainText.c_str(), static_cast<float>(playAgainSize), 0).y)
	{
		DrawText(playAgainText.c_str(), static_cast<int>(playAgainTextPos.x), static_cast<int>(playAgainTextPos.y), playAgainSize, DARKBROWN);

		if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
		{
			if(previousScreen == Screen::SINGLEPLAYER) screen = Screen::SINGLEPLAYER;
			
			if(previousScreen == Screen::MULTIPLAYER) screen = Screen::MULTIPLAYER;

			ResetScore();
		}
	}

	//if (IsKeyDown(KEY_SPACE))
	//{
	//	screen = Screen::SINGLEPLAYER;
	//	ResetScore();
	//}

	if (GetMousePosition().x >= menuTextPos.x &&
		GetMousePosition().x <= menuTextPos.x + MeasureText(menuText.c_str(), scoreSize) &&
		GetMousePosition().y >= menuTextPos.y &&
		GetMousePosition().y <= menuTextPos.y + MeasureTextEx(GetFontDefault(), menuText.c_str(), static_cast<float>(scoreSize), 0).y)
	{
		DrawText(menuText.c_str(), static_cast<int>(menuTextPos.x), static_cast<int>(menuTextPos.y), scoreSize, DARKBROWN);

		if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
		{
			screen = Screen::MENU;
			ResetScore();
		}
	}
}
}