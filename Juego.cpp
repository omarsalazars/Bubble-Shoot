#include "Juego.h"
#include <cstdio>
#include <fstream>

using namespace std;

void Pila::push(Nodo* nodo)
{
    Nodo *temp=this->inicio;
    this->inicio=nodo;
    this->inicio->sig=temp;
}

void Pila::pop()
{
    if(this->inicio==NULL)
        return;
    Nodo *temp=inicio;
    inicio=inicio->sig;
    delete temp;
}

Juego::Juego(){
}

Juego::Juego(int k)
{
    char cadena2[100]="holis/fondo";
    cadena2[11]=k+'0';
    cadena2[12]='.';
    cadena2[13]='p';
    cadena2[14]='n';
    cadena2[15]='g';

    this->mapa=al_load_bitmap(cadena2);
    if(!this->mapa)
        printf("No existe el archivo fondo1.png\n");
    char cadena[100]="niveles/";
    cadena[8]=k+'0';
    cadena[9]='.';
    cadena[10]='t';
    cadena[11]='x';
    cadena[12]='t';
    //cadena[6]=
    fstream f(cadena);
    f>>filas;
    f>>cols;
    this->Matriz=new int*[30];
    this->mat1=new int*[30];
    this->mat2=new int*[30];
    this->burbujas=new Burbuja**[30];
    this->vis=new bool*[30];
    for(int i=0;i<30;i++)
    {
        this->Matriz[i]=new int[cols];
        this->mat1[i]=new int[cols];
        this->mat2[i]=new int[cols];
        this->vis[i]=new bool[cols];
        this->burbujas[i]=new Burbuja*[cols];
    }
    for(int i=0;i<filas;i++)
        for(int j=0;j<cols;j++)
        {
            this->vis[i][j]=false;
            f>>Matriz[i][j];
            if(Matriz[i][j]!=0)
            {
                if(i%2==0)
                    this->burbujas[i][j]=new Burbuja(Matriz[i][j],220+j*40,i*40);
                else
                    this->burbujas[i][j]=new Burbuja(Matriz[i][j],240+j*40,i*40);
            }
            else
                this->burbujas[i][j]=NULL;
        }
        for(int i=filas;i<30;i++)
        {
            for(int j=0;j<cols;j++)
            {
                Matriz[i][j]=0;
                burbujas[i][j]=NULL;
                vis[i][j]=false;
            }
        }
    f.close();
}

Juego::~Juego()
{
    al_destroy_bitmap(this->mapa);
    for(int i=0;i<filas;i++)
    {
        delete this->Matriz[i];
        delete this->vis[i];
        for(int j=0;j<cols;j++)
            delete this->burbujas[i][j];
        delete this->burbujas[i];
    }
    delete this->burbujas;
    delete this->Matriz;
    delete this->vis;
}

void Juego::dibujarBurbujas()
{
    for(int i=0;i<30;i++)
    {
        for(int j=0;j<cols;j++)
        {
            if(this->burbujas[i][j]!=NULL)
            {
                burbujas[i][j]->Dibujar();
            }
        }
    }
}

void Juego::compararMatrices()
{
    for(int i=0;i<30;i++)
    {
        for(int j=0;j<cols;j++)
        {
            if(Matriz[i][j]!=0 && burbujas[i][j]==NULL)
            {
                    if(i%2==0)
                        this->burbujas[i][j]=new Burbuja(Matriz[i][j],220+j*40,i*40);
                    else
                        this->burbujas[i][j]=new Burbuja(Matriz[i][j],240+j*40,i*40);
            }
            else if(Matriz[i][j]==0 && burbujas[i][j]!=NULL)
            {
                delete burbujas[i][j];
                burbujas[i][j]=NULL;
            }
        }
    }
}

void Juego::dfs(int x,int y,int val,int& contador) //REVISAR GRUPOS DE 3
{
    //printf("ESTOY EN: %d %d: %d\n",x,y,mat[y][x]);
    int dis[6][2]={{-1,-1},{-1,0},{0,1},{1,0},{1,-1},{0,-1}};//fila par
    int dis2[6][2]={{-1,0},{-1,1},{0,1},{1,1},{1,0},{0,-1}};//fila impar
    if(this->vis[y][x])
        return;
    vis[y][x]=true;
    if(mat1[y][x]!=val)
    {
        if(mat1[y][x]!=0)
        {
            Nodo *nodo=new Nodo;
            nodo->c.x=x;
            nodo->c.y=y;
            p.push(nodo);
        }
        return;
    }
    else
    {
        mat1[y][x]=0;
        contador++;
    }
    if(y%2==0)
    {
        for(int i=0;i<6;i++)
        {
            if( (y+dis[i][0]>=0 && y+dis[i][0]<30) && (x+dis[i][1]>=0 && x+dis[i][1]<cols))
            {
                dfs(x+dis[i][1],y+dis[i][0],val,contador);
            }
        }
    }
    else
    {
        for(int i=0;i<6;i++)
        {
            if( (y+dis2[i][0]>=0 && y+dis2[i][0]<30) && (x+dis2[i][1]>=0 && x+dis2[i][1]<cols))
            {
                dfs(x+dis2[i][1],y+dis2[i][0],val,contador);
            }
        }
    }
}

void Juego::dfs2(int x,int y,bool& tope)//REVISAR ISLAS
{
    //printf("ESTOY EN 2: %d %d: %d\n",x,y,mat2[y][x]);
    int dis[6][2]={{-1,-1},{-1,0},{0,1},{1,0},{1,-1},{0,-1}};//fila par
    int dis2[6][2]={{-1,0},{-1,1},{0,1},{1,1},{1,0},{0,-1}};//fila impar
    if(mat2[y][x]==0 || vis[y][x])
        return;
    vis[y][x]=true;
    mat2[y][x]=0;
    if(y==0)
    {
        tope=true;
    }
    if(y%2==0)
    {
        for(int i=0;i<6;i++)
        {
            if( (y+dis[i][0]>=0 && y+dis[i][0]<30) && (x+dis[i][1]>=0 && x+dis[i][1]<cols))
            {
                dfs2(x+dis[i][1],y+dis[i][0],tope);
            }
        }
    }
    else
    {
        for(int i=0;i<6;i++)
        {
            if( (y+dis2[i][0]>=0 && y+dis2[i][0]<30) && (x+dis2[i][1]>=0 && x+dis2[i][1]<cols))
            {
                dfs2(x+dis2[i][1],y+dis2[i][0],tope);
            }
        }
    }
}

void Juego::revisarIslas()
{
    int mat2[30][cols];
    for(int i=0;i<30;i++)
    for(int j=0;j<cols;j++)
        mat2[i][j]=Matriz[i][j];
    while(!p.empty())
    {
        this->igualarMatrizDfs();
        this->limpiarVisitados();
        bool tope=false;
        //printf("JAJA %d %d\n",p.top()->c.x,p.top()->c.y);
        dfs2(p.top()->c.x,p.top()->c.y,tope);
        if(!tope)
        {
            this->actualizarMatrizDfs(2);
            this->compararMatrices();
        }
        p.pop();
        if(tope)
        {
            //printf("ESTA PEGADO\n");
        }
    }
}

void Juego::igualarMatrizDfs()
{
    for(int i=0;i<30;i++)
    {
        for(int j=0;j<cols;j++)
        {
            mat1[i][j]=Matriz[i][j];
            mat2[i][j]=Matriz[i][j];
        }
    }
}

void Juego::actualizarMatrizDfs(int k)
{
    if(k==1)
        for(int i=0;i<30;i++)
            for(int j=0;j<cols;j++)
                Matriz[i][j]=mat1[i][j];
    else
        for(int i=0;i<30;i++)
            for(int j=0;j<cols;j++)
                Matriz[i][j]=mat2[i][j];
}

void Juego::limpiarVisitados()
{
    for(int i=0;i<30;i++)
    {
        for(int j=0;j<cols;j++)
        {
            vis[i][j]=false;
        }
    }
}

void Juego::imprimirMatrices()
{
    printf("MATRIZ:\n");
    for(int i=0;i<12;i++)
    {
        for(int j=0;j<cols;j++)
        {
            printf("%d ",Matriz[i][j]);
        }
        printf("\n");
    }
    printf("MAT1:\n");
    for(int i=0;i<12;i++)
    {
        for(int j=0;j<cols;j++)
        {
            printf("%d ",mat2[i][j]);
        }
        printf("\n");
    }
}

bool Juego::Terminado()
{
    for(int i=0;i<30;i++)
    {
        for(int j=0;j<cols;j++)
        {
            if(Matriz[i][j]!=0)
                return false;
        }
    }
    return true;
}
