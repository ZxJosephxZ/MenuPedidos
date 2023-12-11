#include "Pedido.hpp"

class NodoArbol
{
    public:
        NodoArbol(const Pedido &p);
        NodoArbol* getSiguiente() const;
        void setSiguiente(NodoArbol *siguiente);
        NodoArbol* getAnterior() const;
        void setAnterior(NodoArbol *anterior);
        Pedido& obtenerPedido();
    private:
        NodoArbol *siguiente;
        NodoArbol *anterior;
        Pedido pedido;
};