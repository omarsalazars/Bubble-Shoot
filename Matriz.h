#ifndef MATRIZ_H
#define MATRIZ_H
#include "Burbuja.h"

class Matriz
{
    private:
        Burbuja **burbujas;
        int i,j,filas,columnas,**apu;
        double puntos;
    public:
        Matriz();
        ~Matriz();
        void llenar();
        void mostrar(int);
        int** getmat();
        void comparar(int,int,int,int,int,int&);
        int aumentar(int);
};

#endif // MATRIZ_H
