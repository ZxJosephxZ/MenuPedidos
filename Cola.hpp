#ifndef COLA_H
#define COLA_H
#include "NodoCola.hpp"

class Cola
{
    public:
        Cola();
        ~Cola();
        void encolar(const Pedido &pedido);
        void desencolar();
        int  colaLongitud();
        bool estaVacia()const;
        void mostrar();
        int colaPrioridad();
        int numPedido();
        Pedido pedidoCola();
        void verPrimero();
    private:
        NodoCola *primer;
        NodoCola *ultimo;
        int longitud;
};
#endif