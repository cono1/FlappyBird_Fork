#include "Credits.h"

#include "raylib.h"

namespace game
{
void DrawCredits()
{
	DrawText("Game made by", GetScreenWidth() / 2 - 150, 250, 40, WHITE);
	DrawText("Dev: Joaquin Herrero Lendner", GetScreenWidth() / 2 - 230, 350, 30, WHITE);
}
}