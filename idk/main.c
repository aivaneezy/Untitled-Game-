#include <stdio.h>
#include <SDL.h>
#include <SDL_image.h>
#include <stdbool.h>
#include "main.h"
#include "player1.h"
#include "textureManager.h"
// game running 
bool game_is_running = true;

bool init_sdl()
{
	if (SDL_Init(SDL_INIT_VIDEO != 0))
	{
		printf("Cannot initialize SDl: SDL_Error: %s", SDL_GetError());
		return false;
	}
	return true;
}


void sdl_Window()
{
	window = SDL_CreateWindow("space shooter", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, WIDTH, HEIGHT, SDL_WINDOW_SHOWN);
	if (window == NULL)
	{
		printf("Cannot create a window. SDL_Error: %s \n", SDL_GetError());
		SDL_Quit();
	}
}

void sdl_Render()
{
	renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
	if (renderer == NULL)
	{
		printf("Cannot create a renderer. SDL_Error: %s \n", SDL_GetError());
	}
}


void handle_inputs()
{
	SDL_Event event;
	if (SDL_PollEvent(&event) > 0)
	{
		if (event.type == SDL_QUIT)
		{
			printf("Window is close... \n");
			game_is_running = false;
		}
		else if (event.type == SDL_KEYDOWN)
		{
			// resetting keys value
			key.W = 0;
			key.S = 0;
			switch (event.key.keysym.sym)
			{
			case SDLK_w:
				key.W = 1;
				break;
			case SDLK_s:
				key.S = 1;
				break;
			}
			
		}
		
	}
	

	
}

void update_Sdl()
{

	SDL_RenderClear(renderer);
	SDL_SetRenderDrawColor(renderer, 0, 0, 0, SDL_ALPHA_OPAQUE);
	Draw(); // rendering player1
	SDL_RenderPresent(renderer);

}




int main(int argc, char* argv[])
{
	if (!init_sdl())
	{
		return 1;
	}

	sdl_Window();
	sdl_Render();

	/*Init IMG*/
	Init();
	/*Player1 sprite*/
	LoadImages();
	// FPS for time crapping
	int fps = 60;
	Uint32 desiredTime = 1000 / fps;
	while (game_is_running)
	{
		// Getting sdl ticks.
		Uint32 starTime = SDL_GetTicks();
		Uint32 elapsedTime = SDL_GetTicks() - starTime;

		handle_inputs();	
		Update();
		update_Sdl();

		if (elapsedTime < desiredTime)
		{
			SDL_Delay(desiredTime - elapsedTime);
		}
	}

	return 0;
}
