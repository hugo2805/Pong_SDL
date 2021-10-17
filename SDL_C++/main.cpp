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
controller control = controller :: none;

void handleEvents(controller* control);

int main(int argc, char** argv)
{
    initWindow();
    
        if (rendu.pWindow)
        {
            
           initBall();
           initRg();
           initRd();
            
           
            int close = 0;

            while (!close) {

               handleEvents(&control);

                //Update transform
               switch (control)
               {
               case up:
                   posRD.n_y -= 5;
                   fprintf(stderr, "up");
                   break;
               case down:
                   posRD.n_y += 5;
                   fprintf(stderr, "down");
                   break;
               case Z:
                   posRG.n_y -= 5;
                   fprintf(stderr, "z");
                   break;
               case S:
                   posRG.n_y += 5;
                   fprintf(stderr, "s");
                   break;
               }

                SDL_RenderClear(rendu.pRenderer);
                AfficheBall();
                AfficheRD(posRD);
                AfficheRG(posRG);
                SDL_RenderPresent(rendu.pRenderer);


                SDL_Event event;

                while (SDL_PollEvent(&event)) {
                    switch (event.type) {
                    case SDL_QUIT:
                        close = 1;
                        break;
                    /*case SDL_KEYDOWN:
                        switch (event.key.keysym.scancode) {
                        case SDL_SCANCODE_W:
                            break;
                        default:
                            break;
                        }*/
                    }
                }
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
void handleEvents(controller* control) {

    SDL_Event event;

    while(SDL_PollEvent(&event)) {

        switch (event.type) {
        case SDL_KEYDOWN:
            switch (event.key.keysym.sym) 
            {
            case SDLK_UP:
                *control = up; 
                break;
            case SDLK_DOWN:
                *control = down; 
                break;
            case SDLK_z:
                *control = Z; 
                break;
            case SDLK_s:
                *control = S;
                break;

            }break;



        default:*control = none; break;
        }
    }
}
