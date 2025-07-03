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
void pushfinal(pnodo &lista, pnodo nuevo);
void pushorden(pnodo &lista, pnodo nuevo);
pnodo popinicio(pnodo &lista);
pnodo popfinal(pnodo &lista);
pnodo popnodo(pnodo &lista, int elim);
void mostrar(pnodo lista);
bool buscar(pnodo lista, int dato);

main()
{
    pnodo lista, nodo;
    int op;
    initlist(lista);
    do{
        cout<<"1. agregar inicio"<<endl;
        cout<<"2. agregar final"<<endl;
        cout<<"3. agregar ordenado"<<endl;
        cout<<"4. borrar inicio"<<endl;
        cout<<"5. borrar final"<<endl;
        cout<<"6. borrar nodo"<<endl;
        cout<<"7. mostrar"<<endl;
        cout<<"8. buscar nodo"<<endl;
        cout<<"9. salir"<<endl;
        cout<<"Ingrese opcion: ";
        cin>>op;
        switch(op)
        {
        case 1:
            crearnodo(nodo);
            pushinicio(lista, nodo);
            break;
        case 2:
            crearnodo(nodo);
            pushfinal(lista, nodo);
            break;
        case 3:
            crearnodo(nodo);
            pushorden(lista, nodo);
            break;
        case 4:
            cout<<"Nodo eliminado: "<<popinicio(lista)->dato;
            break;
        case 5:
            cout<<"Nodo eliminado: "<<popfinal(lista)->dato;
            break;
        case 6:
            int elim;
            cout<<"Ingrese Nodo a eliminar: ";
            cin>>elim;
            cout<<"Nodo eliminado: "<<popnodo(lista, elim)->dato;
            break;
        case 7:
            mostrar(lista);
            break;
        case 8:
            int b;
            cout<<"Ingrese dato: ";
            cin>>b;
            if(buscar(lista,b))
                cout<<"Nodo Existente";
            else
                cout<<"Nodo no Existente";
            break;
        case 9:
            break;
        default:
            cout<<endl<<op<<" no es una opcion"<<endl;
            break;
        }
        cout<<endl<<endl<<endl;
    }while(op!=9);
}

void initlist(pnodo &lista)
{
    lista=NULL;
}

void crearnodo(pnodo &nodo)
{
    nodo=new tnodo;
    if(nodo!=NULL)
    {
         cout<<"Ingrese valor: ";
         cin>>nodo->dato;
         nodo->sig=NULL;
         nodo->ant=NULL;
    }
    else
    {
        cout<<"Memoria insuficiente"<<endl;
    }
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

void pushfinal(pnodo &lista, pnodo nuevo)
{
    pnodo i;
    if(lista==NULL)
        lista=nuevo;
    else
    {
        for(i=lista;i->sig!=NULL;i=i->sig);
        i->sig=nuevo;
        nuevo->ant=i;
    }
}

void pushorden(pnodo &lista, pnodo nuevo)
{
    pnodo i;
    if(lista==NULL)
        lista=nuevo;
    else
        if(nuevo->dato<lista->dato)
        {
            nuevo->sig=lista;
            lista->ant=nuevo;
            lista=nuevo;
        }
        else
        {
            for(i=lista;i->sig!=NULL && nuevo->dato>(i->sig)->dato;i=i->sig);
            if(i->sig!=NULL)
            {
                nuevo->sig=i->sig;
                nuevo->ant=i;
                (i->sig)->ant=nuevo;
                i->sig=nuevo;
            }
            else
            {
                i->sig=nuevo;
                nuevo->ant=i;
            }
        }
}

pnodo popinicio(pnodo &lista)
{
    pnodo borrar;
    if(lista==NULL)
    {
        borrar=new tnodo;
        borrar->dato=NULL;
    }
    else
    {
        if(lista->sig==NULL)
        {
            borrar=lista;
            lista=NULL;
        }
        else
        {
            borrar=lista;
            lista=lista->sig;
            lista->ant=NULL;
            borrar->sig=NULL;
        }
    }
    return borrar;
}

pnodo popfinal(pnodo &lista)
{
    pnodo i, borrar;
    if(lista==NULL)
    {
        borrar=new tnodo;
        borrar->dato=NULL;
    }
    else
        if(lista->sig==NULL)
        {
            borrar=lista;
            lista=NULL;
        }
        else
        {
            for(i=lista;i->sig!=NULL;i=i->sig);
            borrar=i;
            (i->ant)->sig=NULL;
            i->ant=NULL;
        }
    return borrar;
}

pnodo popnodo(pnodo &lista, int elim)
{
    pnodo borrar,i;
    if(lista==NULL)
    {
        borrar=new tnodo;
        borrar->dato=NULL;
    }
    else
        if(lista->dato==elim)
        {
            borrar=lista;
            lista=lista->sig;
            lista->ant=NULL;
            borrar->sig=NULL;
        }
        else
        {
            for(i=lista;i!=NULL && i->dato!=elim;i=i->sig);
            if(i!=NULL)
            {
                borrar=i;
                (i->ant)->sig=i->sig;
                (i->sig)->ant=i->ant;
                borrar->sig=NULL;
                borrar->ant=NULL;
            }
            else
            {
                borrar=new tnodo;
                borrar->dato=NULL;
            }
        }
    return borrar;
}

void mostrar(pnodo lista)
{
    if(lista==NULL)
        cout<<"Lista Vacia";
    else
        for(pnodo i=lista;i!=NULL;i=i->sig)
            cout<<"Nodo: "<<i->dato<<endl;
}

bool buscar(pnodo lista, int dato)
{
    pnodo i;
    if(lista==NULL)
        return false;
    else
    {
        for(i=lista;i!=NULL && i->dato!=dato;i=i->sig);
        if(i==NULL)
            return false;
        else
            return true;
    }
}
