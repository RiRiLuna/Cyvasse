#include <stdio.h>
#include <stdlib.h>

#include "defines.h"
#include "game.h"
#include "output.h"

/* main permettait de tester le jeu */

int main(int argc, char *argv)
{
    if(SDL_Init(SDL_INIT_EVERYTHING) != 0)
    {
    	fprintf(stderr, "Probleme lors de l'initialisation de la SDL : %s\n", SDL_GetError());
    	return 1;
    }
    
    SDL_Window *window = SDL_CreateWindow("Cyvasse test window", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, WINDOW_WIDTH, WINDOW_HEIGHT, SDL_WINDOW_FULLSCREEN_DESKTOP);
    
    if(window == NULL)
    {
    	fprintf(stderr, "Probleme lors de la creation de la fenetre : %s\n", SDL_GetError());
    	SDL_Quit();
    	return 1;
    }
    
    SDL_Renderer *renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    
    if(renderer == NULL)
    {
    	fprintf(stderr, "Probleme lors de la creation du renderer : %s\n", SDL_GetError());
           
    	SDL_Quit();
    	return 1;
    }
    
    SDL_RenderClear(renderer);
    
    int nb_mode = SDL_GetNumDisplayModes(0);
    if(nb_mode < 0)
    {
        fprintf(stdout,"Échec lors de la récupération du nombre de modes (%s)\n",SDL_GetError());
        return -2;
    }
    fprintf(stdout, "Vous avez %d mode(s) d'affichage\n", nb_mode);

    // Affichage des différents modes
    int i, error;
    SDL_DisplayMode display_mode, fullscreen;
    for(i = 0; i < nb_mode; i++)
    {
        if(i == 0)
            SDL_GetDisplayMode(0, i, &fullscreen);
        error = SDL_GetDisplayMode(0, i, &display_mode);
        if(error < 0)
        {
            fprintf(stdout, "Échec lors de la récupération du mode d'affichage (%s)\n", SDL_GetError());
            return -3;
        }
            
        fprintf(stdout, "Mode %d : %dx%dx%d\n", i, display_mode.w, display_mode.h, display_mode.refresh_rate);
    }
    
    render_surface(renderer, "../data/img/grassv2.png", (fullscreen.h - BOARD_SIZE) / 2, (fullscreen.h - BOARD_SIZE) / 2, 0,0);
    
    SDL_Delay(5000);
    
    SDL_DestroyWindow(window);
    
    SDL_Quit();
    
    return EXIT_SUCCESS;
}
