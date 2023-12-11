#ifndef NODO_PILA_H
#define NODO_PILA_H

#include <iostream>
#include "Pedido.hpp"
using namespace std;
class NodoPila
{
    public:
        NodoPila(const Pedido& p);
        NodoPila* getSiguiente() const;
        void setSiguiente(NodoPila *siguiente);
        Pedido& obtenerPedido();
        ~NodoPila();
    private:
        Pedido pedido;
        NodoPila *siguiente;
};

#endif