#include <iostream>
using namespace std;

typedef struct tnodo *pnodo;

struct tnodo
{
    int dato;
    pnodo sig;
};

struct tlista
{
    pnodo inicio;
    pnodo fin;
};

void crearnodo(pnodo &nodo);
void initlist(tlista &lista);
bool emptylist(tlista lista);
void pushinicio(tlista &lista, pnodo nuevo, int &cont);
void pushfinal(tlista &lista, pnodo nuevo, int &cont);
void pushorden(tlista &lista, pnodo nuevo, int &cont);
void mostrar(tlista lista);
pnodo popinicio(tlista &lista, int &cont);
pnodo popfinal(tlista &lista, int &cont);
pnodo popnodo(tlista &lista, int elim, int &cont);
bool buscar(tlista lista, int dato);
void cantidad(int cont);

main()
{
    tlista lista;
    pnodo nodo;
    int op,cont=0;
    initlist(lista);
    do{
        cout<<"1. agregar inicio"<<endl;
        cout<<"2. agregar final"<<endl;
        cout<<"3. agregar ordenado"<<endl;
        cout<<"4. borrar inicio"<<endl;
        cout<<"5. borrar final"<<endl;
        cout<<"6. borrar nodo"<<endl;
        cout<<"7. mostrar"<<endl;
        cout<<"8. cantidad de elementos"<<endl;
        cout<<"9. salir"<<endl;
        cout<<"Ingrese opcion: ";
        cin>>op;
        switch(op)
        {
        case 1:
            crearnodo(nodo);
            pushinicio(lista, nodo,cont);
            break;
        case 2:
            crearnodo(nodo);
            pushfinal(lista, nodo,cont);
            break;
        case 3:
            crearnodo(nodo);
            pushorden(lista, nodo,cont);
            break;
        case 4:
            cout<<"Nodo eliminado: "<<popinicio(lista,cont)->dato;
            break;
        case 5:
            cout<<"Nodo eliminado: "<<popfinal(lista,cont)->dato;
            break;
        case 6:
            int elim;
            cout<<"Ingrese Nodo a eliminar: ";
            cin>>elim;
            cout<<"Nodo eliminado: "<<popnodo(lista, elim,cont)->dato;
            break;
        case 7:
            mostrar(lista);
            break;
        case 8:
            cantidad(cont);
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

void initlist(tlista &lista)
{
    lista.inicio=NULL;
    lista.fin=NULL;
}

bool emptylist(tlista lista)
{
    if(lista.inicio==NULL && lista.fin==NULL)
        return true;
    else
        return false;
}

void pushinicio(tlista &lista, pnodo nuevo,int &cont)
{
    if(emptylist(lista))
    {
        lista.inicio=nuevo;
        lista.fin=nuevo;
    }
    else
    {
        nuevo->sig=lista.inicio;
        lista.inicio=nuevo;
    }
    cont++;
}

void pushfinal(tlista &lista, pnodo nuevo,int &cont)
{
    pnodo i;
    if(emptylist(lista))
    {
        lista.inicio=nuevo;
        lista.fin=nuevo;
    }
    else
    {
        lista.fin->sig=nuevo;
        lista.fin=nuevo;

    }
    cont++;
}

void pushorden(tlista &lista, pnodo nuevo,int &cont)
{
    pnodo i;
    if(emptylist(lista))
    {
        lista.inicio=nuevo;
        lista.fin=nuevo;
    }
    else
    {
        if(lista.inicio->dato>nuevo->dato)
        {
            nuevo->sig=lista.inicio;
            lista.inicio=nuevo;
        }
        else
        {
            for(i=lista.inicio;i->sig!=NULL && (i->sig)->dato<nuevo->dato;i=i->sig);
            nuevo->sig=i->sig;
            i->sig=nuevo;
        }
    }
    cont++;
}

void mostrar(tlista lista)
{
    if(emptylist(lista))
        cout<<"Lista vacia"<<endl;
    else
    {
        for(pnodo i=lista.inicio;i!=NULL;i=i->sig)
        {
            cout<<"Nodo: "<<i->dato<<endl;
        }
    }
}

pnodo popinicio(tlista &lista,int &cont)
{
    pnodo borrar,cero;
    cero=new tnodo;
    cero->dato=NULL;
    if(emptylist(lista))
        borrar=cero;
    else
    {
        if(lista.inicio->sig==NULL)
        {
            borrar=lista.inicio;
            lista.inicio=NULL;
            lista.fin=NULL;
            borrar->sig=NULL;
        }
        else
        {
            borrar=lista.inicio;
            lista.inicio=lista.inicio->sig;
            borrar->sig=NULL;
        }
        cont--;
    }
    return borrar;
}

pnodo popfinal(tlista &lista,int &cont)
{
    pnodo borrar, i, cero;
    cero=new tnodo;
    cero->dato=NULL;
    if(emptylist(lista))
        borrar=cero;
    else
    {
        if(lista.inicio==lista.fin)
        {
            borrar=lista.inicio;
            lista.inicio=NULL;
            lista.fin=NULL;
            borrar->sig=NULL;
        }
        else
        {
            for(i=lista.inicio;i->sig!=lista.fin;i=i->sig);
            borrar=lista.fin;
            lista.fin=i;
            i->sig=NULL;
            borrar->sig=NULL;
        }
        cont--;
    }
    return borrar;
}

pnodo popnodo(tlista &lista, int elim, int &cont)
{
    pnodo borrar, i, cero;
    cero=new tnodo;
    cero->dato=NULL;
    if(emptylist(lista))
    {
        borrar=cero;
    }
    else
    {
        if(lista.inicio==lista.fin)
        {
            if(lista.inicio->dato==elim)
            {
                borrar=lista.inicio;
                lista.inicio=NULL;
                lista.fin=NULL;
                borrar->sig=NULL;
                cont--;
            }
            else
                borrar=cero;
        }
        else if(lista.inicio->dato==elim)
        {
            borrar=lista.inicio;
            lista.inicio=borrar->sig;
            borrar->sig=NULL;
            cont--;
        }
        else
        {
            for(i=lista.inicio; i->sig!=NULL && (i->sig)->dato!=elim; i=i->sig);
            if(i->sig!=NULL)
            {
                borrar=i->sig;
                lista.fin=i;
                i->sig=borrar->sig;
                borrar->sig=NULL;
                cont--;
            }
            else
                borrar=cero;
        }
    }
    return borrar;
}

void cantidad(int cont)
{
    if(cont==0)
        cout<<"Lista vacia";
    else
        cout<<"Cantidad: "<<cont;
}
