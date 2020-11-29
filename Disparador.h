#ifndef DISPARADOR_H
#define DISPARADOR_H
#include "allegro5/allegro.h"
#include <cstdio>
#include "Burbuja.h"

class Disparador:public Imagen
{
    private:
        float grado;
        Burbuja *siguiente;
        int dx,dy,sigX,sigY;
    public:
        Disparador();
        virtual ~Disparador();
        float getGrado(){return this->grado;}
        void setGrado(float grado){this->grado=grado;printf("%f\n",grado);}
        int getDx(){return this->dx;}
        int getDy(){return this->dy;}
        Burbuja* getSiguiente(){return this->siguiente;}
        void setDx(int dx){this->dx=dx;}
        void setDy(int dy){this->dy=dy;}
        void setSiguiente(Burbuja* siguiente){this->siguiente=siguiente;}
        float getAnguloReal(){return (float)((this->grado-90)*-1)*3.14159/180;}///en radianes
        void cambiarCoordenadas(char);
        void disparar();
        void DibujarRotado();
        void cambiarBurbuja();
};

#endif // DISPARADOR_H
