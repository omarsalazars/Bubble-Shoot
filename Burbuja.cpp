#include "Burbuja.h"
#include <cstdlib>
#include <ctime>
#include <string>
#include <cstdio>

Burbuja::Burbuja()
{
}

Burbuja::Burbuja(int color,int x,int y)
{
    this->color=color;
    char archivo[15]="holis/ball";
    archivo[10]=color+'0';
    archivo[11]='.';
    archivo[12]='p';
    archivo[13]='n';
    archivo[14]='g';
    this->setImagen(al_load_bitmap(archivo));
    if(!this->getImagen())
        printf("NO EXISTE\n");
    this->setX(x);
    this->setY(y);
    this->setW(40);
    this->setH(40);
    this->dx=0;
    this->dy=0;
    this->moviendo=false;
}

Burbuja::~Burbuja()
{
    //dtor
}

int Burbuja::getLogicY()
{
    return this->getY()/40;
}

int Burbuja::getLogicX(){
    if(getLogicY()%2==0)
        return (this->getX()-220)/40;
    else
        return this->getX()>=240? ((this->getX()-220-20)/40) : 0;
}

void Burbuja::burbujaRandom(){
    for(int i=0;i<10;i++)
    {

    }
}

void Burbuja::mover()
{
    if(!this->moviendo)
        return;
    if(this->getY()<=0)
    {
        this->moviendo=false;
        return;
    }
    if(this->getX()<=220 || this->getX()>=500)
    {
        this->dx*=-1;
    }
    this->setY(this->getY()-this->dy);
    this->setX(this->getX()+this->dx);
    this->Dibujar();
}

bool Burbuja::choque(int** Matriz)
{
    if(!(this->getY()%40>=0 && this->getY()%40<=10))
    {
        if(getLogicY()%2==0)
        {
            if(!(this->getX()%40>=0 && this->getX()%40<10))
                return false;
        }
        else
        {
            if(!((20+this->getX())%40>=0 && (20+this->getX())%40<10))
            {
                return false;
            }
        }
    }
    if(this->getLogicY()==0 && Matriz[getLogicY()][getLogicX()]==0)
    {
        Matriz[getLogicY()][getLogicX()]=this->color;
        this->setMoviendo(false);
        return true;
    }

    //printf("LOGICOS: %d %d  MAT:%d\n",logicaX,logicaY,Matriz[logicaY][logicaX]);

    //Lista de vecinos
    int dis[6][2]={{-1,-1},{-1,0},{0,1},{1,0},{1,-1},{0,-1}};//fila par
    int dis2[6][2]={{-1,0},{-1,1},{0,1},{1,1},{1,0},{0,-1}};//fila impar
    //Lista de vecinos
    bool seConecta=false;
    if(Matriz[getLogicY()][getLogicX()]==0)
    {
        if(getLogicY()%2==0)
        {
            for(int i=0;i<6;i++)
            {
                if(getLogicY()+dis[i][0]>=0 && getLogicX()+dis[i][1]>=0 && getLogicX()+dis[i][1]<8)
                {
                    if(Matriz[getLogicY()+dis[i][0]][getLogicX()+dis[i][1]]!=0)
                    {
                        seConecta=true;
                        //printf("ESTO ESTA EN LA MATRIZ: %d COORDENADAS %d %d\n",Matriz[logicaY+dis[i][0]][logicaX+dis[i][1]],logicaX+dis[i][1],logicaY+dis[i][0]);
                    }
                }
            }
        }
        if(getLogicY()%2==1)
        {
            for(int i=0;i<6;i++)
            {
                if(getLogicY()+dis2[i][0]>=0 && getLogicX()+dis2[i][1]>=0 && getLogicX()+dis2[i][1]<8)
                {
                    if(Matriz[getLogicY()+dis2[i][0]][getLogicX()+dis2[i][1]]!=0)
                    {
                        seConecta=true;
                        //printf("ESTO ESTA EN LA MATRIZ: %d COORDENADAS %d %d\n",Matriz[logicaY+dis2[i][0]][logicaX+dis2[i][1]],logicaX+dis2[i][1],logicaY+dis2[i][0]);
                    }
                }
            }
        }
    }
    if(seConecta)
    {
        Matriz[getLogicY()][getLogicX()]=this->color;
        printf("%d %d\n",this->getX(),this->getY());
        this->moviendo=false;
    }
    return seConecta;
}
