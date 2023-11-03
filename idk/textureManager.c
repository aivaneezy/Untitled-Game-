#include "textureManager.h"


void Init()
{
	int flags = IMG_INIT_PNG;
	if (IMG_Init(flags) != flags)
	{
		printf("Error in init of image: %s", SDL_GetError());
	}
}

SDL_Texture* LoadTexture(const char* filepath, SDL_Texture* tex)
{
	
	surface = IMG_Load(filepath);
	if (surface == NULL)
	{
		printf("Cannot create a surface : %s ", SDL_GetError());
	}

	tex = SDL_CreateTextureFromSurface(renderer, surface);
	if (tex == NULL)
	{
		printf("Cannot create a texture: %s", SDL_GetError());
	}

	return tex;
}