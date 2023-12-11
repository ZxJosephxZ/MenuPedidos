#ifndef PILA_H
#define PILA_H

#include "NodoPila.hpp"
class Pila
{
    public:
        Pila();
        ~Pila();
        void apilar(const Pedido &pedido);
        void desapilar();
        bool estaVacia()const;
        bool tipoDato()const;
        void setPrioridad(int num);
        int pilaLongitud();
        Pedido obtenerPedido()const;
        void setNumseg(int num);
        void mostrar();
    private:
        NodoPila *cima;
        int longitud;
};
#endif