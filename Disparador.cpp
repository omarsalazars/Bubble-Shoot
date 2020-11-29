#include "Disparador.h"
#include <cstdio>
#include <cstdlib>
#include <cmath>

Disparador::Disparador()
{
    this->setImagen(al_load_bitmap("holis/flecha.png"));
    if(!this->getImagen())
        printf("No existe flecha.png\n");
    this->grado=0;
    this->setW(40);
    this->setH(80);
    this->setX(380);
    this->setY(560);
    this->dy=5;
    this->dx=0;
    this->siguiente=new Burbuja(1,360,450);
    this->sigX=80*cos(this->getAnguloReal());
    this->sigY=80*sin(this->getAnguloReal());
}

Disparador::~Disparador()
{
    if(this->siguiente!=NULL)
    delete this->siguiente;
}

void Disparador::cambiarCoordenadas(char lado)
{
    if(lado=='l')
    {
        this->grado-=5;
        this->dx-=1;
    }
    if(lado=='r')
    {
        this->grado+=5;
        this->dx+=1;
    }
    this->sigX=80*cos(this->getAnguloReal());
    this->sigY=80*sin(this->getAnguloReal());

    this->siguiente->setX(this->sigX+340+20);
    this->siguiente->setY(560-this->sigY-20);
    //printf("%d %d\n",sigX,sigY);
}

void Disparador::disparar(){
    if(this->siguiente->getMoviendo())
        return;
    //this->siguiente=new Burbuja(1+rand()%5,360,450);
    //this->siguiente=new Burbuja(1,360,450);
    this->siguiente->setDy(this->dy);
    this->siguiente->setDx(this->dx);
    this->siguiente->setX(this->sigX+340+20);
    this->siguiente->setY(560-this->sigY-20);
    //printf("COORDENADA: %d %d\n",this->siguiente->getX(),this->siguiente->getY());
    this->siguiente->setMoviendo(true);
}

void Disparador::DibujarRotado()
{
    al_draw_rotated_bitmap(
        this->getImagen(),
        this->getW()/2,
        this->getH(),
        this->getX(),
        this->getY(),
        this->getGrado()*3.14159/180,0);
}

void Disparador::cambiarBurbuja(){
    if(this->siguiente!=NULL)
        delete this->siguiente;
    this->siguiente=new Burbuja(1+rand()%5,360,450);
    this->siguiente->setX(this->sigX+340+20);
    this->siguiente->setY(560-this->sigY-20);
}
