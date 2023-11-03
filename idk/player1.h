#include <SDL.h>
#include "main.h"
#include "textureManager.h"

// variables
SDL_Rect playerDst;
SDL_Texture* player1Tex;



typedef struct
{
	int W;
	int S;
	int D;
	int A;
}Key;
Key key;

// functions
void LoadImages();
void Update();
void Draw();