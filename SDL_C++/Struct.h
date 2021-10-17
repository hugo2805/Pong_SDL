#pragma once
#include <iostream>
#include <SDL.h>
#include <SDL_image.h>
#include <stdio.h>

using namespace std;

//Ressources pour rendu
typedef struct renderer {

    SDL_Window* pWindow;
    SDL_Renderer* pRenderer;

}renderer;


//Ressources pour les objets (assets) a afficher dans le rendu
typedef struct rendererObject {

    SDL_Surface* pSurface;
    SDL_Texture* pTexture;

}rendererObject;


//Vecteur pour set la position des objets
typedef struct vect2D {

    float n_x;
    float n_y;

}vect2D;

//Tranform objet a manipuler pour modifier la position
typedef struct transform {

    vect2D tpos;


}transform;


//Etats controller
typedef enum controller {

    up=1,
    down,
    Z,
    S,
    none = 0

}controller;


