#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <SDL2/SDL.h>
/* Sets constants */
 #define levity 50
#define jump -1200
 #define width 900
 #define height 500



int main(int argc, char **argv)
{

  if (SDL_Init(SDL_INIT_EVERYTHING) != 0)
  {
    printf("error initializing SDL: %s\n", SDL_GetError());
    return 1;
  }

  /* Creates a window */
  SDL_Window *window = SDL_CreateWindow("The Ghost", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, width, height, 0);

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
  bool running = true, jump = false, jump_again = true; 

  // create the ghost

  SDL_Surface *image_ghost = SDL_LoadBMP("./ghost_pix.bmp");
  SDL_Texture *texture_ghost = SDL_CreateTextureFromSurface(rend, image_ghost);

  float x = 0, y = 350, yVelocity = 0;
  SDL_Rect ghost = {x, y, 90, 90};

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
          jump == true;
          break;

        default:
          break;
        }
        break;
      case SDL_KEYUP:
        switch (event.key.keysym.scancode)
        {
        case SDL_SCANCODE_SPACE:
          jump == false;
          break;

        default:
          break;
        }
        break;

      default:
        break;
      }
    }

    
    yVelocity += levity;
    
    if (jump  && jump_again )
    {
      jump_again = false;
      yVelocity = jump;
    }

    y += yVelocity / 60;

    if (y >= height - ghost.h)
    {
      yVelocity = 0;
      y = height - ghost.h;
      if (jump == false)
        jump_again = true;
    }

    ghost.y = y;
 


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