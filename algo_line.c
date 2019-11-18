#include<stdlib.h>
#include<stdio.h>
#include<assert.h>
#include<SDL/SDL.h>

#include"tools.h"

void ellipse_bresenham(SDL_Surface *display, SDL_Surface *copy, int *A, bool button_up)
{
  A++; A = NULL;
  int a=12, b=9, a1=2*a*a, b1=2*b*b; 
  int cx=12,cy=9,x=-a,y=0;
  int dx=cy*cy*(2*x+1), dy=x*x;
  int e2, err=dx+dy; // amorce 
    
  while(x<=0)
  {
    put_pixels(display,cx+x,cy+y);
    put_pixels(display,cx-x,cy+y);
    put_pixels(display,cx-x,cy-y);
    put_pixels(display,cx+x,cy-y);
    printf("err = %d\n",err);
    e2=2*err;
    if(e2>=dx)
    {
      x++;
      err+=dx+=b1;
    }

    if(e2<=dy)
    {
      y++;
      err+=dy+=a1;
    } 
  }

  SDL_Flip(display);

  if(!button_up)
  {
    SDL_Flip(display);
    for(int j=0;j<display->w*display->h;j++)
      *((int*)copy->pixels+j)=*((int*)display->pixels + j);
  }

  if(button_up)
  {
    SDL_Flip(display);
    for(int j=0;j<display->w*display->h;j++)
      *((int*)display->pixels+j)=*((int*)copy->pixels + j);
  }
}

void circle_bresenham(SDL_Surface *display,SDL_Surface* copy, int *A,bool button_up)
{
  int cx=A[0],cy=A[1],x=A[2],y=A[3];
  int ry=cy-y, rx=cx-x;
  int e=0;
  int j=0;

  if(ry<=0)
  {
    e=5-4*-ry;
    y=-ry;
    x=0;
  }

  else if(ry>=0)
  {
    e=5-4*ry;
    y=ry;
    x=0;
  }

  else if(rx<=0)
  {
    e=5-4*-rx;
    x=-rx;
    y=0;
  }

  else if(rx>=0)
  {
    e=5-4*rx;
    x=rx;
    y=0;
  }

  while(x<=y)
  {
    put_pixels(display,x+cx,y+cy);
    put_pixels(display,x+cx,-y+cy);

    put_pixels(display,-x+cx,y+cy);
    put_pixels(display,-x+cx,-y+cy);

    put_pixels(display,y+cx,x+cy);
    put_pixels(display,y+cx,-x+cy);

    put_pixels(display,-y+cx,x+cy);
    put_pixels(display,-y+cx,-x+cy);

    e+=8*x+4;
    x++;

    if(e>0)
    {
      y--;
      e-=8*y;
    }
  }

  if(!button_up)
  {
    SDL_Flip(display);
    for(j=0;j<display->w*display->h;j++)
      *((int*)copy->pixels+j)=*((int*)display->pixels + j);
  }

  if(button_up)
  {
    SDL_Flip(display);
    for(j=0;j<display->w*display->h;j++)
      *((int*)display->pixels+j)=*((int*)copy->pixels + j);
  }
}

void line_bresenham(SDL_Surface *display,SDL_Surface *copy, int *A,bool button_up)
{
  int x1=A[0],y1=A[1],x2=A[2],y2=A[3];
  int ex=abs(x2-x1);
  int ey=abs(y2-y1);
  int dx=2*ex;
  int dy=2*ey;
  int Dx=ex;
  int Dy=ey;
  int i=0,j=0;
  int Xincr=1;
  int Yincr=1;
  
  if(x1>x2)
    Xincr=-1;
  if(y1>y2)
    Yincr=-1;

  if(dy==0)
  {
    while(i<=Dx)
	  {
      i++;
      put_pixels(display,x1,y1);
      x1+=Xincr;
	  }
  }

  if(Dx > Dy)
  {
    while(i<=Dx)
	  {
      put_pixels(display,x1,y1);
      i++;
      x1+=Xincr;
      ex-=dy;

      if(ex<0)
      {
        y1+=Yincr;
        ex+=dx;
      }
	  }  
  }

  if(dx==dy) // Diagonale.
  {
    while(i<=Dx)
	  {
      i++;
      put_pixels(display,x1,y1);
      x1+=Xincr;
      y1+=Yincr;
	  }
  }

  if(Dx<Dy)
  {
    while(i<=Dy)
	  {
      put_pixels(display,x1,y1);
      i++;
      y1+=Yincr;
      ey-=dx;

      if(ey<0)
      {
        x1+=Xincr;
        ey+=dy;
      }
	  }  
  }

  if(dx==0)
  {
    while(i<=Dy)
    {
      i++;
      put_pixels(display,x1,y1);
      y1+=Yincr;
    }
  }

  if(!button_up)
  {
    SDL_Flip(display);
    for(j=0;j<display->w*display->h;j++)
      *((int*)copy->pixels+j)=*((int*)display->pixels + j);
  }

  if(button_up)
  {
    SDL_Flip(display);
    for(j=0;j<display->w*display->h;j++)
      *((int*)display->pixels+j)=*((int*)copy->pixels + j);
  }
}













































