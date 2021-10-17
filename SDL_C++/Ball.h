#pragma once
#include <iostream>
#include <SDL.h>
#include <SDL_image.h>
#include <stdio.h>
#include "Window.h"
#include "Struct.h"
#include <stdlib.h>
#include <time.h>




using namespace std;


rendererObject Ball;
vect2D posBall;
int BallWidth = 50;
int BallHeight = 50;

int initBall() 
{
    posBall.n_x = WIN_WIDTH/2 - BallWidth/2;
    posBall.n_y = WIN_HEIGHT / 2 - BallHeight/2;

    if (rendu.pRenderer)
    {
        Ball.pSurface = IMG_Load("../Asset/ball.png");
        if (Ball.pSurface)
        {
            Ball.pTexture = SDL_CreateTextureFromSurface(rendu.pRenderer, Ball.pSurface);
            if (Ball.pTexture)
            {
                SDL_Rect dest = { posBall.n_x ,posBall.n_y , BallWidth, BallHeight };
                SDL_RenderCopy(rendu.pRenderer, Ball.pTexture, NULL, &dest);
            }
            else
            {
                fprintf(stderr, " :1: Echec de création de la texture : %s ", SDL_GetError());
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

int AfficheBall()
{
    posBall.n_x -= 5;
    posBall.n_y -= 5;
    SDL_Rect dest = { posBall.n_x ,posBall.n_y , BallWidth, BallHeight };
    SDL_RenderCopy(rendu.pRenderer, Ball.pTexture, NULL, &dest);

    return 1;
}

int collisionHaut(vect2D posBall)
{
    if (posBall.n_y >= 1200) {

    }
    return 1;
}

int DeplacementDiag1()
{
    srand(time(NULL));
    int n = rand() % 6;
    posBall.n_x -= 5;
    posBall.n_y -= n;
    return 1;
}

int DeplacementDiag2()
{
    srand(time(NULL));
    int n = rand() % 6;
    posBall.n_x += 5;
    posBall.n_y -= n;
    return 1;
}

int DeplacementDiag3()
{
    srand(time(NULL));
    int n = rand() % 6;
    posBall.n_x -= 5;
    posBall.n_y += n;
    return 1;
}

int DeplacementDiag4()
{
    srand(time(NULL));
    int n = rand() % 6;
    posBall.n_x += 5;
    posBall.n_y += n;
    return 1;
}