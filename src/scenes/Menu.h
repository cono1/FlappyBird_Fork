#pragma once

enum class Screen
{
	MENU,
	GAME,
	CREDITS
};

// dibuja el men�
void DrawMenu(Screen& screen);