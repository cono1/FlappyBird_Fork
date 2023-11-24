#pragma once

namespace game
{
enum class Screen
{
	MENU,
	SINGLEPLAYER,
	MULTIPLAYER,
	RULES,
	CREDITS,
	ENDSCREEN
};

// dibuja el menú
void DrawMenu(Screen& screen);

// botón que vuelve al menú
void GameDrawReturnButton(Screen& screen, bool& returnToMenu);
}