#include <iostream>
using namespace std;

template <typename T>
struct Nodo {
    T dato;
    Nodo<T>* siguiente;
};

template <typename T>
class Lista
{
private:
    Nodo<T>* inicio;
public:
    Lista()
    {
        inicio=nullptr;
    }

    void agregar(T valor)
    {
        Nodo<T>* nuevo=new Nodo<T>;
        nuevo->dato=valor;
        nuevo->siguiente=inicio;
        inicio=nuevo;
    }

    void contar()
    {
        Nodo<T>* i=inicio;
        int may=0;
        int minu=0;

        while(i!=nullptr)
        {
            if(isupper(i->dato))
                may++;
            else if(islower(i->dato))
                minu++;
            i=i->siguiente;
        }

        cout<<"Cantidad de mayúsculas: "<<may<<endl;
        cout<<"Cantidad de minúsculas: "<<minu<<endl;
    }
};

main()
{
    Lista<char> lista;
    char op;
    char c;
    do {
        cout<<"Ingrese un caracter: ";
        cin>>c;
        lista.agregar(c);
        cout<<"Continuar agregando? S/N...";
        cin>>op;
    } while(op!='n' && op!='N');
    lista.contar();
}
