#pragma once
#include "RaquetteGauche.h"

using namespace std;


//Constructeur
RaquetteGauche::RaquetteGauche()
{
	this->RaquetteG = RaquetteG;
	this->posRG = posRG;
	this->RGWidth = 30;
	this->RGHeight = 300;
}


//Constructeur de copie
RaquetteGauche::RaquetteGauche(RaquetteGauche& RG1)
{
	this->RaquetteG = RG1.RaquetteG;
	this->posRG = RG1.posRG;
	this->RGWidth = RG1.RGWidth;
	this->RGHeight = RG1.RGHeight;
}

//Destructeur
RaquetteGauche::~RaquetteGauche() 
{

}

//Accesseurs
rendererObject RaquetteGauche::getRaquetteG()
{
	return RaquetteG;
}


Vect2D RaquetteGauche::getPosRG()
{
	return posRG;
}

int RaquetteGauche::getRGwidth()
{
	return RGWidth;
}

int RaquetteGauche::getRGheight()
{
	return RGHeight;
}


//Mutateurs

void RaquetteGauche::setRaquetteG(rendererObject RaquetteG)
{
	this->RaquetteG = RaquetteG;
}

void RaquetteGauche::setPosRG(Vect2D PosRG)
{
	this->posRG = PosRG;
}

void RaquetteGauche::setRGWidth(int RGWidth)
{
	this->RGWidth = RGWidth;
}

void RaquetteGauche::setRGHeight(int RGHeight)
{
	this->RGHeight = RGHeight;
}



int RaquetteGauche::initRg(renderer* rendu)
{

    
    SDL_Surface* Surf;
    SDL_Texture* texture;

   
    Surf = RaquetteG.getPSureface();

     posRG.setX(50 + RGWidth / 2);
     posRG.setY( rendu->getWinHeight() / 2 - RGHeight / 2);
    
    if (rendu->getPRenderer())
    {
        Surf = IMG_Load("../Asset/RG.png");
        RaquetteG.setPSurface(Surf);
        Surf = RaquetteG.getPSureface();

        if (RaquetteG.getPSureface())
        {
            texture = SDL_CreateTextureFromSurface(rendu->getPRenderer(), RaquetteG.getPSureface());
            RaquetteG.setPTexture(texture);
            

            if (RaquetteG.getPTexture())
            {
                SDL_Rect dest = { posRG.getX(), posRG.getY(), RGWidth, RGHeight };
                SDL_RenderCopy(rendu->getPRenderer(),RaquetteG.getPTexture(), NULL, &dest);
            }
            else
            {
                fprintf(stderr, ":1: Echec de création de la texture : %s ", SDL_GetError());
            }
        }
        else
        {
            fprintf(stderr, ":1: Echec de chargement du sprite : %s ", SDL_GetError());
        }
    }
    else
    {
        fprintf(stderr, " :1: echec de création du renderer : %s", SDL_GetError());
    }

    return 1;
}

int RaquetteGauche::AfficheRG(Vect2D* posRG, renderer* rendu)
{
   
    posRG->setX(20);
    SDL_Rect dest = { posRG->getX(), posRG->getY(), RGWidth, RGHeight };
    SDL_RenderCopy(rendu->getPRenderer(), RaquetteG.getPTexture(), NULL, &dest);

    //fprintf(stderr, "C Copie");

    return 1;
}





