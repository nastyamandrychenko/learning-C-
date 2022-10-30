#include <stdio.h>
#include <stdbool.h>
#include <SDL2/SDL.h>
/* Sets constants */
#define WIDTH 800
#define HEIGHT 600


int main (int argc, char **argv)
{
  
  
  if (SDL_Init(SDL_INIT_EVERYTHING) != 0) {
    printf("error initializing SDL: %s\n", SDL_GetError());
    return 1;
  }

  /* Creates a window */
   SDL_Window *window = SDL_CreateWindow("The Witcher",
			    SDL_WINDOWPOS_CENTERED, 
			    SDL_WINDOWPOS_CENTERED, 
			    WIDTH, HEIGHT, 0); 


  if (!window) {
    printf("Error creating window: %s\n", SDL_GetError());
    SDL_Quit();
    return 0;
  }

 /* Create a renderer */
  SDL_Renderer* rend = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
  if (!rend)
  {
    printf("Error creating renderer: %s\n", SDL_GetError());
    SDL_DestroyWindow(window);
    SDL_Quit();
    return 0;
  }ь 

  /* Frees memory */
  SDL_DestroyWindow(window);
  SDL_Quit(); 
  
  return 0;
}