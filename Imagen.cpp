#include "Imagen.h"

Imagen::Imagen()
{
    //ctor
}

Imagen::~Imagen()
{
    al_destroy_bitmap(this->imagen);
}

void Imagen::Dibujar(){
    al_draw_bitmap(this->imagen,this->getX(),this->getY(),0);
}
