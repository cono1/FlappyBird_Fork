#include "Parallax.h"

#include "raylib.h"

namespace game
{
static Texture2D foreground;
static Texture2D midForeground;
static Texture2D midBackground;
static Texture2D background;

static float scrollingFore;
static float scrollingMidFore;
static float scrollingMidBack;
static float scrollingBack;

void InitParallax()
{
	//https://opengameart.org/content/background-clouds-and-mountains-parallax
	foreground = LoadTexture("res/assets/background/Background_Clouds_And_Mountains_Parallax_/Layers/BackgroundMuntain02.png");
	midForeground = LoadTexture("res/assets/background/Background_Clouds_And_Mountains_Parallax_/Layers/Cloud03.png");
	midBackground = LoadTexture("res/assets/background/Background_Clouds_And_Mountains_Parallax_/Layers/Cloud02.png");
	background = LoadTexture("res/assets/background/Background_Clouds_And_Mountains_Parallax_/Layers/Background01.png");

	scrollingFore = 0.0f;
	scrollingMidFore = 0.0f;
	scrollingMidBack = 0.0f;
	scrollingBack = 0.0f;
}
	
void UpdateParallax()
{
	float foreSpeed = 60.0f;
	float midForeSpeed = 40.0f;
	float midBackSpeed = 30.0f;
	float backSpeed = 10.0f;

	scrollingFore -= foreSpeed * GetFrameTime();
	scrollingMidFore -= midForeSpeed * GetFrameTime();
	scrollingMidBack -= midBackSpeed * GetFrameTime();
	scrollingBack -= backSpeed * GetFrameTime();

	if (scrollingFore <= -foreground.width) scrollingFore = 0;
	if (scrollingMidFore <= -midForeground.width) scrollingMidFore = 0;
	if (scrollingMidBack <= -midBackground.width ) scrollingMidBack = 0;
	if (scrollingBack <= -background.width ) scrollingBack = 0;
}
	
void DrawParallax()
{
	float scrollindMidForeY = -40.0f;
	float scale = 1.0f;

	DrawTextureEx(background, Vector2{ scrollingBack, 0 }, 0.0f, scale, WHITE);
	DrawTextureEx(background, Vector2{ background.width  + scrollingBack, 0 }, 0.0f, scale, WHITE);

	DrawTextureEx(midBackground, Vector2{ scrollingMidBack, 0}, 0.0f, scale, WHITE);
	DrawTextureEx(midBackground, Vector2{ midBackground.width + scrollingMidBack, 0 }, 0.0f, scale, WHITE);

	DrawTextureEx(midForeground, Vector2{ scrollingMidFore, scrollindMidForeY }, 0.0f, scale, WHITE);
	DrawTextureEx(midForeground, Vector2{ midForeground.width + scrollingMidFore, scrollindMidForeY }, 0.0f, scale, WHITE);

	DrawTextureEx(foreground, Vector2{ scrollingFore, static_cast<float>(GetScreenHeight()) - foreground.height }, 0.0f, scale, WHITE);
	DrawTextureEx(foreground, Vector2{ foreground.width  + scrollingFore, static_cast<float>(GetScreenHeight()) - foreground.height }, 0.0f, scale, WHITE);
}

void DeInitParallax()
{
	UnloadTexture(foreground);
	UnloadTexture(midForeground);
	UnloadTexture(midBackground);
	UnloadTexture(background);
}
}