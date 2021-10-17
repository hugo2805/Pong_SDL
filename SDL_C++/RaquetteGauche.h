#pragma once
#include <iostream>
#include <SDL.h>
#include <SDL_image.h>
#include <stdio.h>
#include "Window.h"
#include "Struct.h"

using namespace std;

rendererObject RaquetteG;
vect2D posRG;
int RGWidth = 30;
int RGHeight = 300;
int initRg()
{
    posRG.n_x = 50 + RGWidth / 2;
    posRG.n_y = WIN_HEIGHT / 2 - RGHeight / 2;
    if (rendu.pRenderer)
    {
        RaquetteG.pSurface = IMG_Load("../Asset/RG.png");
        if (RaquetteG.pSurface)
        {
            RaquetteG.pTexture = SDL_CreateTextureFromSurface(rendu.pRenderer, RaquetteG.pSurface);
            if (RaquetteG.pTexture)
            {
                SDL_Rect dest = { posRG.n_x, posRG.n_y, RGWidth, RGHeight };
                SDL_RenderCopy(rendu.pRenderer, RaquetteG.pTexture, NULL, &dest);
            }
            else
            {
                fprintf(stderr, ":3: Echec de création de la texture : %s ", SDL_GetError());
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

int AfficheRG(vect2D posRG)
{
    posRG.n_x = 20;
    SDL_Rect dest = { posRG.n_x, posRG.n_y, RGWidth, RGHeight };
    SDL_RenderCopy(rendu.pRenderer, RaquetteG.pTexture, NULL, &dest);

    return 1;
}