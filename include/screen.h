#ifndef SCREEN_H
#define SCREEN_H

#include "constants.h"

#include <SDL2/SDL.h>
#include <stdio.h>

typedef struct Pixel {
   SDL_Rect pos;
   int color;
} Pixel;

typedef struct Screen {
   SDL_Window* window;
   SDL_Renderer* renderer;
} Screen;

void initScreen(Screen* screen);
void destroyScreen(Screen* screen);

#endif
