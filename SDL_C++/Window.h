#pragma once
#include <iostream>
#include <SDL.h>
#include <SDL_image.h>
#include <stdio.h>
#include "Struct.h"

#define WIN_WIDTH 1200
#define WIN_HEIGHT 700
using namespace std;

renderer rendu;

int initWindow()
{
    rendu.pWindow = NULL;
    rendu.pRenderer = NULL;

    /* Initialisation simple */
    if (SDL_Init(SDL_INIT_VIDEO) != 0)
    {
        fprintf(stdout, "Échec de l'initialisation de la SDL (%s)\n", SDL_GetError());
        return 0;
    }
    else
    {
        /* Création de la fenêtre */
        rendu.pWindow = SDL_CreateWindow("PONG HUGO EITEL", SDL_WINDOWPOS_UNDEFINED,
            SDL_WINDOWPOS_UNDEFINED,
            WIN_WIDTH,
            WIN_HEIGHT,
            SDL_WINDOW_SHOWN);

        rendu.pRenderer = SDL_CreateRenderer(rendu.pWindow, -1, 0);
    }
    return 1;
}