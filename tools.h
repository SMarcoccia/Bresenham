#define FALSE 0
#define TRUE 1

typedef char bool;

extern SDL_Surface *init_sdl(SDL_Surface *display,int W, 
                             int H, int BPP,Uint32 FLAGS);

extern void loop_event(SDL_Surface* display,SDL_Surface* copy);

extern void click(SDL_Surface *display,SDL_Surface *copy, int x, int y, int count,bool button);

extern void put_pixels(SDL_Surface *display,int x1,int y1);

extern SDL_Surface *init_RGB_surface(SDL_Surface *surface,int W, int H, int BPP, Uint32 FLAGS,int a, int r, int g, int b);

extern SDL_Surface *copy_surface(SDL_Surface *surface1,SDL_Surface *surface2);
