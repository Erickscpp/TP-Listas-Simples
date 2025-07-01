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
void ordenar(tlista &lista);
void juntarlistas(tlista &lista1, tlista &lista2,tlista &lista3);
void juntarlistasorden(tlista &lista1, tlista &lista2,tlista &lista3);

main()
{
    tlista lista1,lista2,lista3;
    pnodo nodo;
    int op,cont1=0,cont2=0,elim;
    initlist(lista1);
    initlist(lista2);
    initlist(lista3);
    do{
        cout<<"1. agregar inicio lista 1"<<endl;
        cout<<"2. agregar inicio lista 2"<<endl;
        cout<<"3. agregar final lista 1"<<endl;
        cout<<"4. agregar final lista 2"<<endl;
        cout<<"5. agregar ordenado lista 1"<<endl;
        cout<<"6. agregar ordenado lista 2"<<endl;
        cout<<"7. borrar inicio lista 1"<<endl;
        cout<<"8. borrar inicio lista 2"<<endl;
        cout<<"9. borrar final lista 1"<<endl;
        cout<<"10. borrar final lista 2"<<endl;
        cout<<"11. borrar nodo lista 1"<<endl;
        cout<<"12. borrar nodo lista 2"<<endl;
        cout<<"13. mostrar lista 1"<<endl;
        cout<<"14. mostrar lista 2"<<endl;
        cout<<"15. ordenar lista 1"<<endl;
        cout<<"16. ordenar lista 2"<<endl;
        cout<<"17. juntar listas sin ordenar"<<endl;
        cout<<"18. juntar listas ordenadamente"<<endl;
        cout<<"19. salir"<<endl;
        cout<<"Ingrese opcion: ";
        cin>>op;
        switch(op)
        {
        case 1:
            crearnodo(nodo);
            pushinicio(lista1, nodo,cont1);
            break;
        case 2:
            crearnodo(nodo);
            pushinicio(lista2, nodo,cont2);
            break;
        case 3:
            crearnodo(nodo);
            pushfinal(lista1, nodo,cont1);
            break;
        case 4:
            crearnodo(nodo);
            pushfinal(lista2, nodo,cont2);
            break;
        case 5:
            crearnodo(nodo);
            pushorden(lista1, nodo,cont1);
            break;
        case 6:
            crearnodo(nodo);
            pushorden(lista2, nodo,cont2);
            break;
        case 7:
            cout<<"Nodo eliminado: "<<popinicio(lista1,cont1)->dato;
            break;
        case 8:
            cout<<"Nodo eliminado: "<<popinicio(lista2,cont2)->dato;
            break;
        case 9:
            cout<<"Nodo eliminado: "<<popfinal(lista1,cont1)->dato;
            break;
        case 10:
            cout<<"Nodo eliminado: "<<popfinal(lista2,cont2)->dato;
            break;
        case 11:
            cout<<"Ingrese Nodo a eliminar: ";
            cin>>elim;
            cout<<"Nodo eliminado: "<<popnodo(lista1, elim,cont1)->dato;
            break;
        case 12:
            cout<<"Ingrese Nodo a eliminar: ";
            cin>>elim;
            cout<<"Nodo eliminado: "<<popnodo(lista2, elim,cont2)->dato;
            break;
        case 13:
            mostrar(lista1);
            break;
        case 14:
            mostrar(lista2);
            break;
        case 15:
            ordenar(lista1);
            mostrar(lista1);
            break;
        case 16:
            ordenar(lista2);
            mostrar(lista2);
            break;
        case 17:
            juntarlistas(lista1,lista2,lista3);
            mostrar(lista3);
            break;
        case 18:
            juntarlistasorden(lista1,lista2,lista3);
            mostrar(lista3);
            break;
        case 19:
            break;
        default:
            cout<<endl<<op<<" no es una opcion"<<endl;
            break;
        }
        cout<<endl<<endl<<endl;
    }while(op!=19);
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

void ordenar(tlista &lista)
{
    int aux;
    for(pnodo i=lista.inicio;i->sig!=NULL;i=i->sig)
    {
        for(pnodo j=i->sig;j!=NULL;j=j->sig)
        {
            if(i->dato>j->dato)
            {
                aux=i->dato;
                i->dato=j->dato;
                j->dato=aux;
            }
        }
    }
    cout<<"LISTA ORDENADA"<<endl;
}

void juntarlistas(tlista &lista1,tlista &lista2,tlista &lista3)
{
    for(pnodo i=lista1.inicio;i!=NULL;i=i->sig)
        if(emptylist(lista3))
        {
            lista3.inicio=i;
            lista3.fin=i;
        }
        else
        {
            lista3.fin->sig=i;
            lista3.fin=i;
        }
    for(pnodo j=lista2.inicio;j!=NULL;j=j->sig)
        if(emptylist(lista3))
        {
            lista3.inicio=j;
            lista3.fin=j;
        }
        else
        {
            lista3.fin->sig=j;
            lista3.fin=j;
        }
        cout<<"LISTAS JUNTAS"<<endl;
}

void juntarlistasorden(tlista &lista1, tlista &lista2,tlista &lista3)
{
    int aux;
    juntarlistas(lista1,lista2,lista3);
    for(pnodo i=lista3.inicio;i->sig!=NULL;i=i->sig)
    {
        for(pnodo j=i->sig;j!=NULL;j=j->sig)
        {
            if(i->dato>j->dato)
            {
                aux=i->dato;
                i->dato=j->dato;
                j->dato=aux;
            }
        }
    }
}
