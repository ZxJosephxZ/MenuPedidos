
#include "Pedido.hpp"
#include <iostream>
using  namespace std;
class NodoLista
{
    public:
        NodoLista(const Pedido&p);
        NodoLista* getSiguiente() const;
        NodoLista* getAnterior() const;
        void setSiguiente(NodoLista *siguiente);
        void setAnteriror(NodoLista *anterior);
        Pedido& obtenerPedido();
        ~NodoLista();
    private:
        NodoLista *siguiente;
        NodoLista *anterior;
        Pedido pedido;
};