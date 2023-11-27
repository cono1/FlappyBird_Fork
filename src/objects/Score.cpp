#include "Score.h"

#include <string>

#include "raylib.h"

namespace game
{
static int score = 0;
static int maxScore = 50;
static int hiScore = score;

void DrawScore()
{
	int scoreSize = 35;
	int offset = 40;
	std::string scoreText = "Score: " + std::to_string(score);

	DrawText(scoreText.c_str(), GetScreenWidth() - MeasureText(scoreText.c_str(), scoreSize) - offset, 10, scoreSize, WHITE);
}

void AddScore()
{
	int scoreAdd = 10;

	if (score + scoreAdd <= maxScore)score += scoreAdd;


	if (hiScore < score) hiScore = score;
}

int GetScore()
{
	return score;
}

int GetHiScore()
{
	return hiScore;
}

int GetMaxScore()
{
	return maxScore;
}

void ResetScore()
{
	score = 0;
}
}