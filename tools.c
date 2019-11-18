#include<stdio.h>
#include<stdlib.h>
#include<SDL/SDL.h>
#include<assert.h>

#include"tools.h"
#include"algo_line.h"

int nRecupCoord[4] = {0};

SDL_Surface *copy_surface(SDL_Surface *surface1,SDL_Surface *surface2)
{
  return surface2=init_RGB_surface(surface2,
			       surface1->w,
			       surface1->h,
			       surface1->format->BitsPerPixel,
			       surface1->flags,
			       surface1->format->Rmask,
			       surface1->format->Gmask,
			       surface1->format->Bmask,
			       surface1->format->Amask);
}

SDL_Surface *init_RGB_surface(SDL_Surface *surface,int W, int H, int BPP, Uint32 FLAGS,int a, int r, int g, int b)
{
  surface=SDL_CreateRGBSurface(FLAGS,W,H,BPP,a,r,g,b);
  if(surface==NULL)
    {
      fprintf(stderr,"Error create surface : %s \n",SDL_GetError());
      exit(EXIT_FAILURE);
    }
    return surface;
}

SDL_Surface *init_sdl(SDL_Surface *display,int W, int H, int BPP,Uint32 FLAGS)
{

  if(SDL_Init(SDL_INIT_VIDEO)==-1)
    {
      fprintf(stderr,"Error Init : %s\n",SDL_GetError());
      exit(EXIT_FAILURE);
    }
  atexit(SDL_Quit);

  display=SDL_SetVideoMode(W,H,BPP,FLAGS);
  if(display==NULL)
    {
      fprintf(stderr,"Error Display Window : %s\n",SDL_GetError());
      exit(EXIT_FAILURE);
    }

  SDL_WM_SetCaption("Line Bresenham",NULL);
  return display;
}

void loop_event(SDL_Surface* display,SDL_Surface* copy)
{
  SDL_Event event;
  bool stop=TRUE,button_up=TRUE;
  int x,y,count=0;

  do
  {
    while(SDL_PollEvent(&event))
    {	
      if(event.type==SDL_QUIT)
        stop=FALSE;
      if(event.button.button==SDL_BUTTON_RIGHT 
        && event.type==SDL_MOUSEBUTTONDOWN)
        stop=FALSE;

      if(event.button.button==SDL_BUTTON_LEFT &&
        event.type==SDL_MOUSEBUTTONDOWN)
      {
        count=0;
        x=event.button.x;
        y=event.button.y;
        click(display,copy,x,y,count,TRUE);
        count=1;
      }

      if(event.button.button==SDL_BUTTON_LEFT &&
        event.type==SDL_MOUSEBUTTONUP)
      {
        button_up=FALSE;
        x=event.button.x;
        y=event.button.y;
        click(display,copy,x,y,count,button_up);
        button_up=TRUE;
        count=0;
      }

      if(event.type==SDL_MOUSEMOTION)
      {
        x=event.motion.x;
        y=event.motion.y;
        click(display,copy,x,y,count,TRUE);
      }	     
    }
  }while(stop);
}

void click(SDL_Surface *display, SDL_Surface *copy, int x, int y, int count,bool button)
{
  if(count==0)
  {
    nRecupCoord[0]=x;
    nRecupCoord[1]=y;
  }
  if(count==1 || button==FALSE)
  {
    nRecupCoord[2]=x;
    nRecupCoord[3]=y;
    line_bresenham(display,copy, nRecupCoord,button);
    // circle_bresenham(display, copy, nRecupCoord, button);
    // ellipse_bresenham(display, copy, nRecupCoord, button);

  }
}

void put_pixels(SDL_Surface *display,int x1,int y1)
{
  *((int*)display->pixels + x1+display->w*y1)=0x00FF00;
}


