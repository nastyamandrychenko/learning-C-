#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <SDL2/SDL.h>
/* Sets constants */
#define WIDTH 900
#define HEIGHT 500

int main(int argc, char **argv)
{

  if (SDL_Init(SDL_INIT_EVERYTHING) != 0)
  {
    printf("error initializing SDL: %s\n", SDL_GetError());
    return 1;
  }

  /* Creates a window */
  SDL_Window *window = SDL_CreateWindow("The Witcher",
                                        SDL_WINDOWPOS_CENTERED,
                                        SDL_WINDOWPOS_CENTERED,
                                        WIDTH, HEIGHT, 0);

  if (!window)
  {
    printf("Error creating window: %s\n", SDL_GetError());
    SDL_Quit();
    return 0;
  }

  /* Create a renderer  */
  SDL_Renderer *rend = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
  if (!rend)
  {
    printf("Error creating renderer: %s\n", SDL_GetError());
    SDL_DestroyWindow(window);
    SDL_Quit();
    return 0;
  }
  bool running = true;
  SDL_Event event;
  while (running)
  {
    /* Process events */
    while (SDL_PollEvent(&event))
    {
      switch (event.type)
      {
      case SDL_QUIT:
        running = false;
        break;
      }
    }
    // clear screen
    SDL_RenderClear(rend);

    // show what was draw
    SDL_RenderPresent(rend);
  }

  /* Frees memory */
  SDL_DestroyRenderer(rend);
  SDL_DestroyWindow(window);
  SDL_Quit();

  return 0;
}