#include "Rules.h"

#include <iostream>
#include <string>

#include "raylib.h"

namespace game
{
static int fontSize;
static float offset;
static Color fontColor;
static Color secondFontColor;

static std::string singlePlayerText;
static std::string multiPlayerText;
static std::string playerText;
static std::string leftPlayerText;
static std::string rightPlayerText;

static Vector2 singlePlayerTextPos;
static Vector2 playerMoveTextPos;
static Vector2 multiPlayerTextPos;
static Vector2 leftPlayerTextPos;
static Vector2 rightPlayerTextPos;

void InitRules();
void AssignPos(Vector2& textPos, std::string text, std::string previousText, int order);
void DrawRulesText(std::string text, Vector2 pos, Color color);

void DrawRules()
{
	InitRules();

	DrawRulesText(singlePlayerText, singlePlayerTextPos, fontColor);
	DrawRulesText(playerText, playerMoveTextPos, secondFontColor);

	DrawRulesText(multiPlayerText, multiPlayerTextPos, fontColor);
	DrawRulesText(leftPlayerText, leftPlayerTextPos, secondFontColor);
	DrawRulesText(rightPlayerText, rightPlayerTextPos, secondFontColor);

}

void InitRules()
{
	fontSize = 30;
	offset = 80;
	fontColor = WHITE;
	secondFontColor = LIGHTGRAY;

	singlePlayerText = "SINGLEPLAYER";
	playerText = "Press SPACE to jump";
	multiPlayerText = "MULTIPLAYER";
	leftPlayerText = "Left player: Press W to fly";
	rightPlayerText = "Right player: Press SPACE to fly";

	singlePlayerTextPos = { GetScreenWidth() / 2 - static_cast<float>(MeasureText(singlePlayerText.c_str(), fontSize)) / 2, 40 };

	AssignPos(playerMoveTextPos, playerText, singlePlayerText, 1);
	AssignPos(multiPlayerTextPos, multiPlayerText, playerText, 2);
	AssignPos(leftPlayerTextPos, leftPlayerText, multiPlayerText, 3);
	AssignPos(rightPlayerTextPos, rightPlayerText, leftPlayerText, 4);
}

void AssignPos(Vector2& textPos, std::string text, std::string previousText, int order)
{
	textPos = { GetScreenWidth() / 2 - static_cast<float>(MeasureText(text.c_str(), fontSize)) / 2,
				MeasureTextEx(GetFontDefault(), previousText.c_str(), static_cast<float>(fontSize), 0).y + offset * order};
}


void DrawRulesText(std::string text, Vector2 pos, Color color)
{
	DrawText(text.c_str(), static_cast<int>(pos.x), static_cast<int>(pos.y), fontSize, color);
}
}