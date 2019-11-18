#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include<SDL/SDL.h>

#include"tools.h"
#include"algo_line.h"

#define W 600
#define H 400
#define BPP 32
#define FLAGS SDL_HWSURFACE

int main(int argc, char *argv[])
{
  freopen("CON", "w", stdout);
  SDL_Surface *display=NULL;
  SDL_Surface *copy_display=NULL;

  display=init_sdl(display, W, H, BPP, FLAGS);

  copy_display=copy_surface(display, copy_display);

  loop_event(display, copy_display); 

  SDL_FreeSurface(display);
  SDL_FreeSurface(copy_display);

  if(argc <- 1) printf(argv[0]);
  return EXIT_SUCCESS;
}

