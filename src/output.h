#ifndef OUTPUT_H
#define OUTPUT_H

#include "defines.h"
#include "SDL2/SDL.h"
#include <SDL2/SDL_image.h>

/* Fonctions de base pour l'affichage */
void render_surface(SDL_Renderer *renderer, char *filename, int x, int y, int w, int h);

/* Fonctions gestion affichage jeu */
void render_board(SDL_Renderer *renderer);

#endif // OUTPUT_H
