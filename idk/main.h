
#pragma once
#include <stdio.h>
#include <SDL.h>
#include <SDL_image.h>
#include "main.h"
#include <stdbool.h>

#define WIDTH 720
#define HEIGHT 720

SDL_Window* window;
SDL_Renderer* renderer;
SDL_Surface* surface;


// function declaration
bool init_sdl();
void sdl_Window();
void sdl_Render();
void handle_inputs();
void update_Sdl();
