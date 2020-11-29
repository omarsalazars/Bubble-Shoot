#ifndef IMAGEN_H
#define IMAGEN_H
#include "allegro5/allegro.h"

class Imagen
{
    private:
        ALLEGRO_BITMAP *imagen;
        int x,y,w,h;
    public:
        Imagen();
        virtual ~Imagen();
        ALLEGRO_BITMAP* getImagen(){return this->imagen;}
        void setImagen(ALLEGRO_BITMAP* imagen){this->imagen=imagen;}
        int getX(){return this->x;}
        int getY(){return this->y;}
        int getW(){return this->w;}
        int getH(){return this->h;}
        void setX(int x){this->x=x;}
        void setY(int y){this->y=y;}
        void setW(int w){this->w=w;}
        void setH(int h){this->h=h;}
        void Dibujar();
};

#endif // IMAGEN_H
