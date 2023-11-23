#pragma once

namespace game
{
enum class Screen
{
	MENU,
	SINGLEPLAYER,
	MULTIPLAYER,
	CREDITS
};

// dibuja el menú
void DrawMenu(Screen& screen);

// botón que vuelve al menú
void DrawReturnButton(Screen& screen, bool& returnToMenu);

void GameDrawReturnButton(Screen& screen, bool& returnToMenu);
}