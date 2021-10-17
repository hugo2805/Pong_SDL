#pragma once
#include <iostream>
#include <SDL.h>
#include <SDL_image.h>
#include <stdio.h>
#include "Window.h"
#include "Struct.h"

using namespace std;

rendererObject RaquetteD;
vect2D posRD;
int RDWidth = 30;
int RDHeight = 300;

int initRd()
{
    posRD.n_x = 1150 - RDWidth/2;
    posRD.n_y = WIN_HEIGHT / 2 - RDHeight / 2;
    if (rendu.pRenderer)
    {
        RaquetteD.pSurface = IMG_Load("../Asset/RD.png");
        if (RaquetteD.pSurface)
        {
            RaquetteD.pTexture = SDL_CreateTextureFromSurface(rendu.pRenderer, RaquetteD.pSurface);
            if (RaquetteD.pTexture)
            {
                SDL_Rect dest = { posRD.n_x , posRD.n_y, RDWidth, RDHeight };
                SDL_RenderCopy(rendu.pRenderer, RaquetteD.pTexture, NULL, &dest);
            }
            else
            {
                fprintf(stderr, ":2: Echec de création de la texture : %s ", SDL_GetError());
            }
        }
        else
        {
            fprintf(stderr, "Echec de chargement du sprite : %s ", SDL_GetError());
        }
    }
    else
    {
        fprintf(stderr, "echec de création du renderer : %s", SDL_GetError());
    }

    return 1;
}
int AfficheRD(vect2D posRD)
{
    posRD.n_x = 1150;
    //posRD.n_y = WIN_HEIGHT / 2 - RDHeight / 2;
    SDL_Rect dest = { posRD.n_x , posRD.n_y, RDWidth, RDHeight };
    SDL_RenderCopy(rendu.pRenderer, RaquetteD.pTexture, NULL, &dest);

    return 1;
}