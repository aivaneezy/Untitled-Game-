#include "player1.h"
#include <stdio.h>




void LoadImages()
{
	int Xindex = 0; // x axes
	int Yindex = 0; // y axes

	player1Tex = LoadTexture("C:\\Users\\Golden\\Desktop\\Assets\\sprites.png", player1Tex);
	if (player1Tex == NULL)
	{
		printf("Failed to load image: %s", SDL_GetError());
	}
	
	player.x = Xindex * 64;
	player.y = Yindex * 64;
	player.w = 150;
	player.h = 150;
	
}

void Update()
{

}

void Draw()
{
	SDL_RenderCopy(renderer, player1Tex, NULL, &player);
}