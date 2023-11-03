#include "player1.h"
#include <stdio.h>
#include <math.h>
#define PADDLE_WIDTH 100
#define PADDLE_HEIGHT 100


void LoadImages()
{
	int Xindex = 0; // x axes
	int Yindex = 0; // y axes

	player1Tex = LoadTexture("C:\\Users\\Golden\\Desktop\\Assets\\paddle1.png", player1Tex);
	if (player1Tex == NULL)
	{
		printf("Failed to load image: %s", SDL_GetError());
	}
	


	playerDst.x = Xindex;
	playerDst.y = Yindex;
	playerDst.w = PADDLE_WIDTH;
	playerDst.h = PADDLE_HEIGHT;
	
}

void Update()
{
	int PLAYER_MOVEMENT = 10;
	if (key.W)
	{
		playerDst.y -= PLAYER_MOVEMENT;
		if (playerDst.y < 0)
		{
			
			printf("playerdst is reverse\n");
		}
		printf("%d\n", playerDst.y);
	}
	if (key.S)
	{	
		playerDst.y += PLAYER_MOVEMENT;
		if (playerDst.y + PADDLE_HEIGHT > HEIGHT)
		{
			playerDst.y = HEIGHT - PADDLE_HEIGHT;
			PLAYER_MOVEMENT = -PLAYER_MOVEMENT;
		}
	}
}

void Draw()
{
	SDL_RenderCopy(renderer, player1Tex, NULL, &playerDst);
}