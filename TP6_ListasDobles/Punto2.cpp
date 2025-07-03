#include<iostream>
using namespace std;

typedef struct tnodo *pnodo;
typedef struct tnodo{
                    int dato;
                    pnodo sig;
                    pnodo ant;
                    };
typedef struct tlista{
                    pnodo inicio;
                    pnodo fin;
                    };

void IniciarLista(tlista &lista)
{
    lista.inicio = NULL;
    lista.fin = NULL;
}

void CrearNodo(pnodo &nuevo, int valor)
{
    nuevo = new tnodo;
    if(nuevo != NULL)
    {
        nuevo -> dato = valor;
        nuevo -> sig = NULL;
        nuevo -> ant = NULL;
    }
}

void AgregarInicio(tlista &lista, pnodo nuevo)
{
    if(lista.inicio == NULL){
        lista.inicio = nuevo;
        lista.fin = nuevo;
    }
    else{
        nuevo->sig = lista.inicio;
        lista.inicio->ant = nuevo;
        lista.inicio = nuevo;
    }
}

void AgregarFinal(tlista &lista, pnodo nuevo){
    if(lista.inicio == NULL){
        lista.inicio = nuevo;
        lista.fin = nuevo;
    }
    else{
        lista.fin->sig = nuevo;
        nuevo->ant = lista.fin;
        lista.fin = nuevo;
    }
}

void QuitarInicio(tlista &lista){
    if(lista.inicio==NULL && lista.fin==NULL)
        cout<<"Lista vacia";
    else
        if(lista.inicio==lista.fin)
        {
            lista.inicio=NULL;
            lista.fin=NULL;
        }
        else
        {
            lista.inicio=lista.inicio->sig;
            (lista.inicio->ant)->sig=NULL;
            lista.inicio->ant=NULL;
        }
}

void QuitarFinal(tlista &lista)
{
    if(lista.inicio==NULL && lista.fin==NULL)
        cout<<"Lista vacia";
    else
        if(lista.inicio==lista.fin)
        {
            lista.inicio=NULL;
            lista.fin=NULL;
        }
        else
        {
            lista.fin=lista.fin->ant;
            (lista.fin->sig)->ant=NULL;
            lista.fin->sig=NULL;
        }
}

int main(){

    return 0;
}

/* EXPLICACION:
QuitarInicio:
Primero pregunta si la lista esta vacia, si es asi, devuelve un mensaje; Si no, pregunta si la lista tiene un solo elemento,
si es asi, apunta la lista a NULL eliminando ese elemento; Si la lista tiene mas de un elemento, hace que el puntero de inicio de la lista
apunte al siguiente nodo, y desvincula el nodo que se quiere eliminar con el actual inicio.

QuitarFinal:
Primero pregunta si la lista esta vacia, si es asi, devuelve un mensaje; Si no, pregunta si la lista tiene un solo elemento,
si es asi, apunta la lista a NULL eliminando ese elemento; Si la lista tiene mas de un elemento, hace que el puntero de fin de la lista
apunte al anterior nodo, y desvincula el nodo que se quiere eliminar con el actual fin.
*/
