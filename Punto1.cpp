#include <iostream>
using namespace std;

typedef struct tnodo *pnodo;

struct tnodo
{
    int dato;
    pnodo sig;
};

void crearnodo(pnodo &nodo);
void initlist(pnodo &lista);
bool emptylist(pnodo lista);
void pushinicio(pnodo &lista, pnodo nuevo);
void pushfinal(pnodo &lista, pnodo nuevo);
void pushorden(pnodo &lista, pnodo nuevo);
void mostrar(pnodo lista);
pnodo popinicio(pnodo &lista);
pnodo popfinal(pnodo &lista);
pnodo popnodo(pnodo &lista, int elim);
bool buscar(pnodo lista, int dato);
int minimo(pnodo lista);

main()
{
    pnodo lista,nodo;
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
        cout<<"8. minimo"<<endl;
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
            if(emptylist(lista)==false)
                cout<<"Nodo minimo: "<<minimo(lista);
            else
                cout<<"Lista vacia";
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

void crearnodo(pnodo &nodo)
{
    nodo=new tnodo;
    if(nodo!=NULL)
    {
         cout<<"Ingrese valor: ";
         cin>>nodo->dato;
         nodo->sig=NULL;
    }
    else{
        cout<<"Memoria insuficiente"<<endl;
     }
}

void initlist(pnodo &lista)
{
    lista=NULL;
}

bool emptylist(pnodo lista)
{
    if(lista==NULL)
        return true;
    else
        return false;
}

void pushinicio(pnodo &lista, pnodo nuevo)
{
    nuevo->sig=lista;
    lista=nuevo;
}

void pushfinal(pnodo &lista, pnodo nuevo)
{
    pnodo i;
    if(emptylist(lista))
    {
        lista=nuevo;
    }
    else
    {
        for(i=lista;i->sig!=NULL;i=i->sig);
        i->sig=nuevo;
    }
}

void pushorden(pnodo &lista, pnodo nuevo)
{
    pnodo i;
    if(emptylist(lista))
    {
        lista=nuevo;
    }
    else
    {
        if(lista->dato>nuevo->dato)
        {
            nuevo->sig=lista;
            lista=nuevo;
        }
        else
        {
            for(i=lista;i->sig!=NULL && (i->sig)->dato<nuevo->dato;i=i->sig);
            nuevo->sig=i->sig;
            i->sig=nuevo;
        }
    }
}

void mostrar(pnodo lista)
{
    if(emptylist(lista))
        cout<<"Lista vacia"<<endl;
    else
    {
        for(pnodo i=lista;i!=NULL;i=i->sig)
        {
            cout<<"Nodo: "<<i->dato<<endl;
        }
    }
}

pnodo popinicio(pnodo &lista)
{
    pnodo borrar;
    if(emptylist(lista))
        borrar=NULL;
    else
    {
        borrar=lista;
        lista=lista->sig;
        borrar->sig=NULL;
    }
    return borrar;
}

pnodo popfinal(pnodo &lista)
{
    pnodo borrar, i;
    if(emptylist(lista))
        borrar=NULL;
    else
    {
        if(lista->sig==NULL)
        {
            borrar=lista;
            lista=lista->sig;
            borrar->sig=NULL;
        }
        else
        {
            for(i=lista;(i->sig)->sig!=NULL;i=i->sig);
            borrar=i->sig;
            i->sig=NULL;
            borrar->sig=NULL;
        }
    }
    return borrar;
}

pnodo popnodo(pnodo &lista, int elim)
{
    pnodo borrar, i;
    if(emptylist(lista))
    {
        borrar=NULL;
    }
    else
    {
        if(lista->dato==elim)
        {
            borrar=lista;
            lista=borrar->sig;
            borrar->sig=NULL;
        }
        else
        {
            for(i=lista; i->sig!=NULL && (i->sig)->dato!=elim; i=i->sig);
            if(i->sig!=NULL)
            {
                borrar=i->sig;
                i->sig=borrar->sig;
                borrar->sig=NULL;
            }
            else
                borrar=NULL;
        }
    }
    return borrar;
}

bool buscar(pnodo lista, int dato)
{
    pnodo i;
    bool a=false;
    if(emptylist(lista)==false)
    {
        for(i=lista;i->sig!=NULL && a==false;i=i->sig)
            if(i->dato==dato)
                a=true;
    }
    return a;
}

int minimo(pnodo lista)
{
    int m=lista->dato;
    if(lista->sig==NULL)
        m=m;
    else
        for(pnodo i=lista;i!=NULL;i=i->sig)
            if(m>i->dato)
                m=i->dato;
    return m;
}
