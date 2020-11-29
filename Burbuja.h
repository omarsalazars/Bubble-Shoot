#ifndef BURBUJA_H
#define BURBUJA_H
#include "allegro5/allegro.h"
#include "Imagen.h"

class Burbuja:public Imagen
{
    private:
        int color,dx,dy;
        bool moviendo;
    public:
        Burbuja();
        Burbuja(int,int,int);
        virtual ~Burbuja();
        void setColor(int color){this->color=color;};
        void setDx(int dx){this->dx=dx;}
        void setDy(int dy){this->dy=dy;}
        void setMoviendo(bool moviendo){this->moviendo=moviendo;}
        int getDx(){return this->dx;}
        int getDy(){return this->dy;}
        int getLogicX();
        int getLogicY();
        int getColor(){return this->color;}
        bool getMoviendo(){return this->moviendo;}
        void burbujaRandom();
        void mover();
        bool choque(int**);
};

#endif // BURBUJA_H
