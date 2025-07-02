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
        nuevo->dato = valor;
        nuevo->siguiente=inicio;
        inicio=nuevo;
    }
    int primos()
    {
        Nodo<T>* i=inicio;
        int contador=0;

        while(i!=nullptr)
        {
            if(esprimo(i->dato))
            {
                contador++;
            }
            i=i->siguiente;
        }
        return contador;
    }
    bool esprimo(int n)
    {
        if(n<=1)
            return false;
        for(int i=2; i*i<=n; ++i)
        {
            if(n%i==0)
                return false;
        }
        return true;
    }
};

main()
{
    Lista<int> lista;
    char op;
    int n;
    do{
        cout<<"Ingrese numero: ";
        cin>>n;
        lista.agregar(n);
        cout<<"Continuar agregando? S/N...";
        cin>>op;
    }while(op!='n' && op!='N');
    cout<<"Cantidad de primos: "<<lista.primos();
}
