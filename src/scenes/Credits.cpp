#include "Credits.h"

#include "raylib.h"

namespace game
{
void DrawCredits()
{
	DrawText("Game made by", GetScreenWidth() / 2 - 150, 250, 40, WHITE);
	DrawText("Dev: Joaquin Herrero Lendner", GetScreenWidth() / 2 - 230, 350, 30, WHITE);
	DrawText("Dev: Daniela Gonzalez", GetScreenWidth() / 2 - 230, 450, 30, WHITE);
}
}