#include "Matriz.h"
#include <allegro5/allegro.h>
#include <cstdio>
#include <iostream>

using namespace std;

Matriz::Matriz(){
    filas= 10;
    columnas=7;
    j=i=0;
    puntos=0;
    apu=new int*[filas];
    for(int j=0;j<filas;j++)
        apu[j]=new int [columnas];
}

Matriz::~Matriz(){
 	for(j=0;j<filas;j++)
  		delete apu[j];
  	delete apu;
}

void  Matriz::llenar(){
    for(i=0;i<filas;i++){
        for(int j=0;j<columnas;j++)
            apu[i][j]=0;
    }
}

void Matriz::mostrar(int fondo){
	ALLEGRO_BITMAP *buffer = al_create_bitmap(1601, 895);
	ALLEGRO_BITMAP *NIVEL1=al_load_bitmap("fondo1.bmp");
	ALLEGRO_BITMAP *NIVEL2=al_load_bitmap("fondo2.bmp");
	ALLEGRO_BITMAP *NIVEL3=al_load_bitmap("fondo3.bmp");
	ALLEGRO_BITMAP *BALL1=al_load_bitmap("ball1.bmp");
	ALLEGRO_BITMAP *BALL2=al_load_bitmap("ball2.bmp");
	ALLEGRO_BITMAP *BALL3=al_load_bitmap("ball3.bmp");
	ALLEGRO_BITMAP *BALL4=al_load_bitmap("ball4.bmp");
	ALLEGRO_BITMAP *BALL5=al_load_bitmap("ball5.bmp");
    al_set_target_bitmap(buffer);
 while(1){
 	if(fondo==1)
        al_draw_bitmap_region(NIVEL1, 0, 0, 0, 0, 1601, 895,0);
    else if(fondo==2)
        al_draw_bitmap_region(NIVEL2, 0, 0, 0, 0, 1601, 895,0);
    else if(fondo==3)
        al_draw_bitmap_region(NIVEL3, 0, 0, 0, 0, 1601, 895,0);
    for(int i=0;i<filas;i++){
        for(int j=0;j<columnas;j++){
	        if(apu[i][j]==1)
                al_draw_bitmap_region(BALL1,533,8,j*76,i*69,76,69,0);
	        else if(apu[i][j]==2)
                al_draw_bitmap_region(BALL2,533,8,j*76,i*69,76,69,0);
	         else if(apu[i][j]==3)
                al_draw_bitmap_region(BALL3,533,8,j*76,i*69,76,69,0);
	         else if(apu[i][j]==4)
                al_draw_bitmap_region(BALL4,533,8,j*76,i*69,76,69,0);
	         else if(apu[i][j]==5)
                al_draw_bitmap_region(BALL5,533,8,j*76,i*69,76,69,0);
    	}
	}
    al_draw_bitmap_region(buffer, 0, 0, 0, 0, 1601, 895,0);
	}
    /*destroy_bitmap(BALL1);
    destroy_bitmap(BALL2);
    destroy_bitmap(BALL3);
    destroy_bitmap(BALL4);
    destroy_bitmap(BALL5);*/
    al_destroy_bitmap(buffer);/*
	destroy_bitmap(NIVEL1);
	destroy_bitmap(NIVEL2);
	destroy_bitmap(NIVEL3);*/
}

int** Matriz::getmat(){
return this->apu;
}

void Matriz::comparar(int i,int j,int ciclo,int temporal,int puntos,int &suma){//ciclo permite no hacer un cicl infinito
    cout<<"y="<<i<<" x="<<j<<endl;
    temporal=apu[i][j];
    int direcciones[]={0,0,0,0};
    for(int l=0;l<4;l++)
    {
        if(i+l<10)
            if(apu[i+l][j]==temporal)///ABAJO
                direcciones[0]++;
        if(i-l>=0)
            if(apu[i-l][j]==temporal)///ARRIBA
                direcciones[1]++;
        if(j+l<10)
            if(apu[i][j+l]==temporal)///DERECHA
                direcciones[2]++;
        if(j-l>=0)
            if(apu[i][j-l]==temporal)///IZQUIERDA
                direcciones[3]++;
    }
    for(int k=0;k<4;k++)
        if(direcciones[k]==4)
            suma+=puntos;
    cout<<"Puntos "<<suma<<endl;
    if(direcciones[0]==4)
        for(int l=0;l<4;l++)
            apu[i+l][j]=0;
    if(direcciones[1]==4)
        for(int l=0;l<4;l++)
            apu[i-l][j]=0;
    if(direcciones[2]==4)
        for(int l=0;l<4;l++)
            apu[i][j+l]=0;
    if(direcciones[3]==4)
        for(int l=0;l<4;l++)
            apu[i][j-l]=0;
}
int Matriz::aumentar(int color){
   int aum=0;
   for(int i=columnas;i>0;i++){
   			if(apu[9][i]!=0)//VERIFICA SI PUEDE AVANZAR EN EL TABLERO
   				aum++;
   		}
	if(aum==0){
		for(int i=filas-1;i>0;i--){
   			for(int j=0;j<columnas;j++){
   					apu[i][j]=apu[i+1][j];	//DESPLAZA EL TABLERO UNA LINEA HACIA ABAJO
   			}
		}
		for(int i=columnas;i>0;i++){
   			apu[0][i]=1+rand()%color;//NUMERO DE COLORES E INGRESA NUEVA LINEA
   		}
   		return 1;
	}
	else{//SI A NO PODIA AVANZAR PIERDE EL TABLERO ESTA LLENO
		cout<<endl<<"GAME OVER"<<endl;
		return 2;//PERDIO
	}

}
