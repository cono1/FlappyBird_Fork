#include "gameData/GameLoop.h"

using namespace game;

int main()
{
	game::GameLoop();

	return 0;
}

//A corregir:
//Importante:
//- Bastantes numeros magicos en menu.cpp
//- La funci�n Update recibe 13 parametros, podr�an ser menos.
// -Que tome getKeyPressed y no keyDown para el mov del player
//
//	Player :
//	-en player.cpp resetPLayer() sobra initPosX, Y.No hace falta.
//	Lo mismo con obstacles
//
//	GameLoop :
//-en gameLoop.h esta declarada una funcion que no se usa fuera de gameLoop.
//
//Menu :
//	- Hay dos funciones que se llaman similar "DrawReturnButton" y "GameDrawReturnButton" y cumplen la misma funcion, se podria simplificar en una y pasarle los valores por par�metro.
//
//	Game :
//	-En game cpp hay muchas funciones que no tienen declaraci�n.
//	- El orden en el que est�n declaradas en game.h no coincide con el orden en el que est�n definidas en game.cpp.
//	- En la funcion drawParallax hay magic numbers.
//	- La funci�n "DrawObjects" tiene un nombre ambiguo.Podr�a ser "DrawObjectsHitbox" o similar.
//	- Algunas funciones est�n como verbos y otras como sustantivos.Cambiar "PlayerMovement" a "MovePlayer".Lo mismo con las demas funciones en game.cpp
//
//	Credits :
//-Magic numbers
//
//(no se por que se pasa return to menu como parametro en la funcion resetGame en game.cpp)
