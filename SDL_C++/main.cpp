#include <iostream>
#include <SDL.h>
#include <SDL_image.h>
#include <stdio.h>
#include "Window.h"
#include "Struct.h"
#include "Ball.h"
#include "RaquetteGauche.h"
#include "RaquetteDroite.h"

using namespace std;




void handleEvents(controller* controlJ1, controller* controlJ2, int close);

int main(int argc, char** argv)
{
    controller controlJ1;
    controller controlJ2;
    renderer rendu;
    int close = 0;
    C_Ball Obj_Ball;
    RaquetteGauche Obj_RG;
    RaquetteDroite Obj_RD;
    Vect2D posBall;
    Vect2D MovBall(1, 1);
    int speedBall = 4;
    Vect2D posRD;
    Vect2D posRG;
    int i = 0;
    


    initWindow(&rendu);

        if (rendu.getPWindow())
        {
            
           Obj_Ball.initBall(&rendu);
           Obj_RG.initRg(&rendu);
           Obj_RD.initRd(&rendu);
            
            while (!close) {

                posBall = Obj_Ball.getPosBall();
                posRD = Obj_RD.getPosRD();
                posRG = Obj_RG.getPosRG();
               
               

                handleEvents(&controlJ1, &controlJ2, close);

               
                //Update transform
               switch (controlJ1)
               {
               case up:
                   if(posRD.getY()>0) 
                   posRD.setY(posRD -= 5);
                   //fprintf(stderr, "up");
                   break;
               case down:
                   if(posRD.getY() < 700 - Obj_RD.getRDheight())
                   posRD.setY(posRD += 5);
                   //fprintf(stderr, "down");
                   break;

               }

               switch (controlJ2)
               {
               case up:
                   if (posRG.getY() > 0)
                     posRG.setY(posRG -= 5);
                     //fprintf(stderr, "z");
                     break;
               case down:
                   if (posRG.getY() < 700 - Obj_RG.getRGheight())
                     posRG.setY(posRG += 5);
                     //fprintf(stderr, "s");
                     break;
               }

                
                Obj_RD.setPosRD(posRD);
                Obj_RG.setPosRG(posRG);
                // update ball pos
                speedBall = Obj_Ball.CollisionBall(&posBall, speedBall, &MovBall);
                speedBall = Obj_Ball.VerifRG(&posBall, speedBall, &MovBall, &posRG);
                speedBall = Obj_Ball.VerifRD(&posBall, speedBall, &MovBall, &posRD);

                Vect2D newPos(posBall.getX() + MovBall.getX() * speedBall, posBall.getY() + MovBall.getY() * speedBall);
                Obj_Ball.setPosBall(newPos);
                SDL_RenderClear(rendu.getPRenderer());
                Obj_Ball.AfficheBall(newPos, &rendu);
                Obj_RD.AfficheRD(&posRD, &rendu);
                Obj_RG.AfficheRG(&posRG, &rendu);
                SDL_RenderPresent(rendu.getPRenderer());
                i++;
                SDL_Delay(1000 / 60);
                
            }
            
        }
        else
        {
            fprintf(stderr, "Erreur de création de la fenêtre: %s\n", SDL_GetError());
        }
        SDL_DestroyRenderer(rendu.getPRenderer());
    
    SDL_Quit();

    return 0;
}

//Set controller event
void handleEvents(controller* controlJ1, controller* controlJ2, int close)
{

    SDL_Event events;

    while(SDL_PollEvent(&events)) {

        switch (events.type) {
        case SDL_QUIT:
            close = 1;
            break;
        case SDL_KEYDOWN:
            switch (events.key.keysym.sym)
            {
            case SDLK_LEFT:
                *controlJ2 = up;
                break;
            case SDLK_RIGHT:                                                        
                *controlJ2 = down;
                break;
            }break;

        default:
            *controlJ2 = idle;
            break;
        }
    

        switch (events.type) {
        case SDL_KEYDOWN:
            switch (events.key.keysym.sym) 
            {
            case SDLK_UP:
                *controlJ1 = up; 
                break;
            case SDLK_DOWN:
                *controlJ1 = down; 
                break;
            }break;

        default:
            *controlJ1 = idle; 
            break;
        }
        
    }
}
