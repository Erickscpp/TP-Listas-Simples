#include <iostream>
using namespace std;

typedef struct tnodo *pnodo;
typedef struct tnodo
{
     int dato;
     pnodo sig;
     pnodo ant;
};

void initlist(pnodo &lista);
void crearnodo(pnodo &nodo);
void pushinicio(pnodo &lista, pnodo nuevo);
void binario(int n);

main()
{
    int num;
    cout<<"Ingrese numero: ";
    cin>>num;
    binario(num);
}

void initlist(pnodo &lista)
{
    lista=NULL;
}

void crearnodo(pnodo &nodo, int dato)
{
    nodo=new tnodo;
    nodo->dato=dato;
    nodo->sig=NULL;
    nodo->ant=NULL;
}

void pushinicio(pnodo &lista, pnodo nuevo)
{
    if(lista==NULL)
        lista=nuevo;
    else
    {
        nuevo->sig=lista;
        lista->ant=nuevo;
        lista=nuevo;
    }
}

void binario(int n)
{
    pnodo lista, nodo;
    initlist(lista);
    int a;
    while(n>0)
    {
        a=n%2;
        crearnodo(nodo,a);
        pushinicio(lista,nodo);
        n=n/2;
    }
    for(pnodo i=lista;i!=NULL;i=i->sig)
        cout<<i->dato;
}
