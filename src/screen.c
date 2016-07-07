#include "../include/screen.h"

void initScreen(Screen* screen) {
   if (SDL_Init(SDL_INIT_VIDEO) != 0) {
      fprintf(stderr, "Failed to init: %s\n", SDL_GetError());
      return;
   }

   screen->window = NULL;
   screen->window = SDL_CreateWindow("Test",
         SDL_WINDOWPOS_UNDEFINED,
         SDL_WINDOWPOS_UNDEFINED,
         W,
         H,
         SDL_WINDOW_SHOWN);
   screen->renderer = NULL;
   screen->renderer = SDL_CreateRenderer(screen->window, -1, SDL_RENDERER_ACCELERATED);

   if (!screen->renderer) {
      fprintf(stderr, "Failed to create renderer: %s\n", SDL_GetError());
      return;
   }

   if (screen->window) {
      SDL_RenderClear(screen->renderer);
      for (int i = 0; i < 3; i++) { 
         SDL_Rect dest = {i*200 + i*10,0,200,200};
         SDL_RenderFillRect(screen->renderer, &dest);
      }
      SDL_RenderPresent(screen->renderer);
      SDL_Delay(3000);
      destroyScreen(screen);
      SDL_Quit();
   }
   else {
      fprintf(stderr, "Failed create window: %s\n", SDL_GetError());
      return;
   }
}

void destroyScreen(Screen* screen) {
   SDL_DestroyRenderer(screen->renderer);
   SDL_DestroyWindow(screen->window);
}
