#include <iostream>
#include <cstdlib>
#include <ctime>
#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>
#include <allegro5/allegro_color.h>
#include "Matriz.h"
#include "Juego.h"
#include "Disparador.h"

using namespace std;

int main(){
	srand(time(0));
	al_init();
	al_init_image_addon();
	al_install_keyboard();
    al_install_mouse();//INICIALZA EL RATON
    ALLEGRO_DISPLAY *display=al_create_display(770,560);
	//ALLEGRO_BITMAP *buffer=al_create_bitmap(770,560);//IMPRIME TODAS LAS COSAS EN PANTALLA
	ALLEGRO_EVENT_QUEUE *event_queue=al_create_event_queue();
	al_register_event_source(event_queue, al_get_display_event_source(display));
	al_register_event_source(event_queue, al_get_keyboard_event_source());

	Juego *juego=new Juego(1);
	Disparador *disparador=new Disparador;
	///NIVEL1
/*
	al_draw_bitmap(juego->getMapa(),0,0,0);
	juego->dibujarBurbujas();
	disparador->DibujarRotado();
	disparador->cambiarBurbuja();
	disparador->getSiguiente()->Dibujar();
	al_flip_display();
	while(1)
	{
        ALLEGRO_EVENT ev;
        ALLEGRO_TIMEOUT timeout;
        al_init_timeout(&timeout, 0.01);
        al_wait_for_event_until(event_queue,&ev,&timeout);
        if(ev.type==ALLEGRO_EVENT_DISPLAY_CLOSE)
            break;
        if(ev.type==ALLEGRO_EVENT_KEY_DOWN)
        {
            switch(ev.keyboard.keycode)
            {
                case ALLEGRO_KEY_LEFT:
                    if(disparador->getGrado()>-80)
                    {
                        disparador->cambiarCoordenadas('l');
                    }
                    break;
                case ALLEGRO_KEY_RIGHT:
                    if(disparador->getGrado()<80)
                    {
                        disparador->cambiarCoordenadas('r');
                    }
                    break;
                case ALLEGRO_KEY_SPACE:
                    disparador->disparar();
                    //printf("DISPARO\n");
                    //printf("%d %d\n",disparador->getSiguiente()->getX(),disparador->getSiguiente()->getY());
                    break;
                default:
                    break;
            }
            al_draw_bitmap(juego->getMapa(),0,0,0);
            disparador->getSiguiente()->Dibujar();
            disparador->DibujarRotado();
            juego->dibujarBurbujas();
            al_flip_display();
        }
        if(disparador->getSiguiente()->getMoviendo())
        {
            al_draw_bitmap(juego->getMapa(),0,0,0);
            disparador->DibujarRotado();
            if(disparador->getSiguiente()->choque(juego->getMatriz()))
            {
                juego->compararMatrices();
                int a=0;
                juego->igualarMatrizDfs();
                juego->limpiarVisitados();
                juego->dfs(
                    disparador->getSiguiente()->getLogicX(),
                    disparador->getSiguiente()->getLogicY(),
                    disparador->getSiguiente()->getColor(),
                    a);
                if(a>=3)
                {
                    juego->actualizarMatrizDfs(1);
                    juego->revisarIslas();
                    juego->compararMatrices();
                    if(juego->Terminado())
                        break;
                }
                disparador->cambiarBurbuja();
            }
            disparador->getSiguiente()->Dibujar();
            disparador->getSiguiente()->mover();
            juego->dibujarBurbujas();
            al_flip_display();
        }
	}*/

	delete disparador;
	delete juego;


	///NIVEL 2
/*
    juego=new Juego(2);
	disparador=new Disparador;
	al_draw_bitmap(juego->getMapa(),0,0,0);
	juego->dibujarBurbujas();
	disparador->DibujarRotado();
	disparador->cambiarBurbuja();
	disparador->getSiguiente()->Dibujar();
	al_flip_display();
	while(1)
	{
        ALLEGRO_EVENT ev;
        ALLEGRO_TIMEOUT timeout;
        al_init_timeout(&timeout, 0.01);
        al_wait_for_event_until(event_queue,&ev,&timeout);
        if(ev.type==ALLEGRO_EVENT_DISPLAY_CLOSE)
            break;
        if(ev.type==ALLEGRO_EVENT_KEY_DOWN)
        {
            switch(ev.keyboard.keycode)
            {
                case ALLEGRO_KEY_LEFT:
                    if(disparador->getGrado()>-80)
                    {
                        disparador->cambiarCoordenadas('l');
                    }
                    break;
                case ALLEGRO_KEY_RIGHT:
                    if(disparador->getGrado()<80)
                    {
                        disparador->cambiarCoordenadas('r');
                    }
                    break;
                case ALLEGRO_KEY_SPACE:
                    disparador->disparar();
                    //printf("DISPARO\n");
                    //printf("%d %d\n",disparador->getSiguiente()->getX(),disparador->getSiguiente()->getY());
                    break;
                default:
                    break;
            }
            al_draw_bitmap(juego->getMapa(),0,0,0);
            disparador->getSiguiente()->Dibujar();
            disparador->DibujarRotado();
            juego->dibujarBurbujas();
            al_flip_display();
        }
        if(disparador->getSiguiente()->getMoviendo())
        {
            al_draw_bitmap(juego->getMapa(),0,0,0);
            disparador->DibujarRotado();
            if(disparador->getSiguiente()->choque(juego->getMatriz()))
            {
                juego->compararMatrices();
                int a=0;
                juego->igualarMatrizDfs();
                juego->limpiarVisitados();
                juego->dfs(
                    disparador->getSiguiente()->getLogicX(),
                    disparador->getSiguiente()->getLogicY(),
                    disparador->getSiguiente()->getColor(),
                    a);
                if(a>=3)
                {
                    juego->actualizarMatrizDfs(1);
                    juego->revisarIslas();
                    juego->compararMatrices();
                    if(juego->Terminado())
                        break;
                }
                disparador->cambiarBurbuja();
            }
            disparador->getSiguiente()->Dibujar();
            disparador->getSiguiente()->mover();
            juego->dibujarBurbujas();
            al_flip_display();
        }
	}
	delete disparador;
	delete juego;

*/
	//NIVEL 3
    juego=new Juego(3);
	disparador=new Disparador;
	al_draw_bitmap(juego->getMapa(),0,0,0);
	juego->dibujarBurbujas();
	disparador->DibujarRotado();
	disparador->cambiarBurbuja();
	disparador->getSiguiente()->Dibujar();
	al_flip_display();
	while(1)
	{
        ALLEGRO_EVENT ev;
        ALLEGRO_TIMEOUT timeout;
        al_init_timeout(&timeout, 0.01);
        al_wait_for_event_until(event_queue,&ev,&timeout);
        if(ev.type==ALLEGRO_EVENT_DISPLAY_CLOSE)
            break;
        if(ev.type==ALLEGRO_EVENT_KEY_DOWN)
        {
            switch(ev.keyboard.keycode)
            {
                case ALLEGRO_KEY_LEFT:
                    if(disparador->getGrado()>-80)
                    {
                        disparador->cambiarCoordenadas('l');
                    }
                    break;
                case ALLEGRO_KEY_RIGHT:
                    if(disparador->getGrado()<80)
                    {
                        disparador->cambiarCoordenadas('r');
                    }
                    break;
                case ALLEGRO_KEY_SPACE:
                    disparador->disparar();
                    //printf("DISPARO\n");
                    //printf("%d %d\n",disparador->getSiguiente()->getX(),disparador->getSiguiente()->getY());
                    break;
                default:
                    break;
            }
            al_draw_bitmap(juego->getMapa(),0,0,0);
            disparador->getSiguiente()->Dibujar();
            disparador->DibujarRotado();
            juego->dibujarBurbujas();
            al_flip_display();
        }
        if(disparador->getSiguiente()->getMoviendo())
        {
            al_draw_bitmap(juego->getMapa(),0,0,0);
            disparador->DibujarRotado();
            if(disparador->getSiguiente()->choque(juego->getMatriz()))
            {
                juego->compararMatrices();
                int a=0;
                juego->igualarMatrizDfs();
                juego->limpiarVisitados();
                juego->dfs(
                    disparador->getSiguiente()->getLogicX(),
                    disparador->getSiguiente()->getLogicY(),
                    disparador->getSiguiente()->getColor(),
                    a);
                if(a>=3)
                {
                    juego->actualizarMatrizDfs(1);
                    juego->revisarIslas();
                    juego->compararMatrices();
                    if(juego->Terminado())
                        break;
                }
                disparador->cambiarBurbuja();
            }
            disparador->getSiguiente()->Dibujar();
            disparador->getSiguiente()->mover();
            juego->dibujarBurbujas();
            al_flip_display();
        }
	}
	delete disparador;
	delete juego;


}
