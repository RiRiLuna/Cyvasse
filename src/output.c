#include "output.h"

void render_surface(SDL_Renderer *renderer, char *filename, int x, int y, int w, int h)
{ 
    SDL_Surface *sprite = IMG_Load(filename);
    
    if(sprite)
    {
    	SDL_Texture *texture = SDL_CreateTextureFromSurface(renderer, sprite);
		if(texture)
		{
			SDL_Rect dst;
			dst.x = x;
			dst.y = y;
			if(w == 0)
				dst.w = sprite->w;
			else
				dst.w = w;
			if(h == 0)
				dst.h = sprite->h;
			else
				dst.h = h;
			
			SDL_RenderCopy(renderer, texture, NULL, &dst);
			SDL_RenderPresent(renderer);
			
			SDL_DestroyTexture(texture);
		}
		else
			fprintf(stderr, "Probleme lors la creation de la texture : %s\n", SDL_GetError());
    	
    	SDL_FreeSurface(sprite);
    }  
	else
		fprintf(stderr, "Probleme lors la creation du sprite : %s\n", SDL_GetError());
}
