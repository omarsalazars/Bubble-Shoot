#ifndef JUEGO_H
#define JUEGO_H
#include "allegro5/allegro.h"
#include "Burbuja.h"

class Coordenada{
    public:
        int x,y;
};

class Nodo{
    public:
        Coordenada c;
        Nodo *sig;
};

class Pila{
    public:
        Nodo *inicio=NULL;
        void push(Nodo*);
        void pop();
        Nodo* top(){return this->inicio;}
        bool empty(){return this->inicio==NULL;}
};

class Juego
{
    private:
        ALLEGRO_BITMAP *mapa;
        int **Matriz,**mat2,**mat1,filas,cols;
        Burbuja ***burbujas;
        bool **vis;
        Pila p;
    public:
        Juego();
        Juego(int);
        virtual ~Juego();
        ALLEGRO_BITMAP *getMapa(){return this->mapa;}
        int** getMatriz(){return this->Matriz;}
        void dibujarBurbujas();
        void compararMatrices();
        void dfs(int x,int y,int val,int& contador);
        void dfs2(int x,int y,bool& tope);
        void dfs3(int x,int y);
        void revisarIslas();
        void igualarMatrizDfs();
        void actualizarMatrizDfs(int);
        void limpiarVisitados();
        void imprimirMatrices();
        bool Terminado();
};

#endif // JUEGO_H
