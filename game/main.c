#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <SDL2/SDL.h>
/* Sets constants */
#define JUMP -1200

int main(int argc, char **argv)
{

  if (SDL_Init(SDL_INIT_EVERYTHING) != 0)
  {
    printf("error initializing SDL: %s\n", SDL_GetError());
    return 1;
  }

  /* Creates a window */
  SDL_Window *window = SDL_CreateWindow("The Ghost", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 900, 500, 0);

  if (!window)
  {
    printf("Error creating window: %s\n", SDL_GetError());
    SDL_Quit();
    return 0;
  }

  /* Create a renderer  */
  SDL_Renderer *rend = SDL_CreateRenderer(window, -1, 0);
  if (!rend)
  {
    printf("Error creating renderer: %s\n", SDL_GetError());
    SDL_DestroyWindow(window);
    SDL_Quit();
    return 0;
  }

  // load the background
  SDL_Surface *image = SDL_LoadBMP("./background.bmp");
  if (!image)
  {
    printf("Unable to load image %s! SDL Error: %s\n", "background.bmp", SDL_GetError());
    return 0;
  }
  SDL_Texture *texture = SDL_CreateTextureFromSurface(rend, image);

 // boolean 
  bool running = true, jump = false, can_jump = true;

  // create the ghost

  SDL_Surface *image_ghost = SDL_LoadBMP("./ghost_pix.bmp");
  SDL_Texture *texture_ghost = SDL_CreateTextureFromSurface(rend, image_ghost);

  float x_pos = 0, y_pos = 350, yVel = 0, xVel = 0;
  SDL_Rect ghost = {x_pos, y_pos, 90, 90};

  SDL_QueryTexture(texture_ghost, NULL, NULL, &ghost.w, &ghost.h);

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

      case SDL_KEYDOWN:
        switch (event.key.keysym.scancode)
        {
        case SDL_SCANCODE_SPACE:
          jump = true;
          break;

        default:
          break;
        }
        break;
      case SDL_KEYUP:
        switch (event.key.keysym.scancode)
        {
        case SDL_SCANCODE_SPACE:
          jump = false;
          break;

        default:
          break;
        }
        break;

      default:
        break;
      }
    }
    yVel += 50;
    
    if (jump && can_jump)
    {
      can_jump = false;
      yVel = -1200;
      xVel += 50;
      //  xVel = 100;
    }

    y_pos += yVel / 50;
    x_pos += xVel/50;

    if (y_pos >= 500 - ghost.h)
    {
      yVel = 0;
      y_pos = 500 - ghost.h;
      if (!jump)
        can_jump = true;
    }

    ghost.y = y_pos;
    ghost.x = x_pos;


    SDL_RenderCopy(rend, texture, NULL, NULL);
   SDL_RenderCopy(rend, texture_ghost, NULL, &ghost);
    // SDL_SetRenderDrawColor(rend, 255, 0, 0, 255);
    // SDL_RenderFillRect(rend, &ghost);
    // show what was draw
    SDL_RenderPresent(rend);

    // clear screen
    SDL_RenderClear(rend);
    SDL_Delay(16);
  }

  /* Frees memory */
  SDL_DestroyTexture(texture);
  SDL_FreeSurface(image);
  SDL_DestroyRenderer(rend);
  SDL_DestroyWindow(window);
  SDL_Quit();

  return 0;
}