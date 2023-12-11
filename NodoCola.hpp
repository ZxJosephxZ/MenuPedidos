#ifndef NODO_COLA_H
#define NODO_COLA_H

#include <iostream>
#include "Pedido.hpp"
using namespace std;
class NodoCola
{
    public:
        NodoCola(const Pedido &p);
        NodoCola* getSiguiente() const;
        void setSiguiente(NodoCola *siguiente);
        Pedido& obtenerPedido();
        ~NodoCola();
    private:
        NodoCola *siguiente;
        Pedido pedido;
};
#endif