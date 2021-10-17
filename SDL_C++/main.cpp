#include <iostream>
#include <SDL.h>
#include <SDL_image.h>
#include <stdio.h>
#include "Window.h"
#include "Struct.h"
#include "Ball.h"
#include "RaquetteGauche.h"
#include "RaquetteD.h"

#define WIN_WIDTH 1200
#define WIN_HEIGHT 700
using namespace std;
controller controlJ1 =  none;
controller controlJ2 = none;
int close = 0;

void handleEvents(controller* controlJ1, controller* controlJ2, int close);

int main(int argc, char** argv)
{
    initWindow();
    
        if (rendu.pWindow)
        {
            
           initBall();
           initRg();
           initRd();
            
           
            

            while (!close) {

               handleEvents(&controlJ1, &controlJ2, close);
               
                //Update transform
               switch (controlJ1)
               {
               case up:
                   posRD.n_y -= 5;
                   fprintf(stderr, "up");
                   break;
               case down:
                   posRD.n_y += 5;
                   fprintf(stderr, "down");
                   break;

               }

               switch (controlJ2)
               {
                case up:
                     posRG.n_y -= 5;
                     fprintf(stderr, "z");
                     break;
                 case down:
                     posRG.n_y += 5;
                     fprintf(stderr, "s");
                     break;
               }

                SDL_RenderClear(rendu.pRenderer);
                AfficheBall();
                AfficheRD(posRD);
                AfficheRG(posRG);
                SDL_RenderPresent(rendu.pRenderer);

                SDL_Delay(1000 / 60);
            }
            

        }
        else
        {
            fprintf(stderr, "Erreur de création de la fenêtre: %s\n", SDL_GetError());
        }
    
        SDL_DestroyTexture(RaquetteG.pTexture);
        SDL_FreeSurface(Ball.pSurface);
        SDL_DestroyRenderer(rendu.pRenderer);
    SDL_Quit();

    return 0;
}

//Set controller event
void handleEvents(controller* controlJ1, controller* controlJ2, int close)
{

    SDL_Event event;

    while(SDL_PollEvent(&event)) {

        switch (event.type) {
        case SDL_QUIT:
            close = 1;
            break;
        case SDL_KEYDOWN:
            switch (event.key.keysym.sym)
            {
            case SDLK_z:
                *controlJ2 = up;
                break;
            case SDLK_s:
                *controlJ2 = down;
                break;
            }break;

        default:
            *controlJ2 = none;
            break;
        }


        switch (event.type) {
        case SDL_KEYDOWN:
            switch (event.key.keysym.sym) 
            {
            case SDLK_UP:
                *controlJ1 = up; 
                break;
            case SDLK_DOWN:
                *controlJ1 = down; 
                break;
            }break;

        default:
            *controlJ1 = none; 
            break;
        }


    }
}
