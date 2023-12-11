#include "Cola.hpp"

Cola::Cola()
{
    primer = nullptr;
    ultimo = nullptr;
    longitud = 0;
};

void Cola::encolar(const Pedido &p)
{
    NodoCola *nodo = new NodoCola(p);
    if(estaVacia())
    {
        primer = nodo;
        ultimo = nodo;
        longitud++;
    }
    else
    {
        ultimo->setSiguiente(nodo);
        ultimo = nodo;
        longitud++;
    }
};

int Cola::numPedido()
{
    return primer->obtenerPedido().getPrioridad();
};

Pedido Cola::pedidoCola()
{
    return primer->obtenerPedido();
};

int Cola::colaPrioridad()
{
    return primer->obtenerPedido().getPrioridad();
};

void Cola::desencolar()
{
    if(!estaVacia())
    {
        NodoCola *temp = primer;
        primer = primer->getSiguiente();
        delete(temp);
        longitud--;
    }
    else
    {
        cout << "cola vacia" << endl;
    }
};

void Cola::mostrar()
{
    NodoCola *temp = primer;
    if(!estaVacia())
    {
        while(temp != nullptr)
        {
            temp->obtenerPedido().informe();
            temp = temp->getSiguiente();
        }
    }
    else
    {
        cout << "cola vacia" << endl;
    }
};

int Cola:: colaLongitud()
{
    
    return longitud;
};

void Cola::verPrimero()
{
    if(!estaVacia())
    {
        cout << primer->obtenerPedido().getPrioridad() << endl;
    }
    else
    {
        cout << "la cola esta vacia" << endl;
    }
};
Cola::~Cola()
{
    while(!estaVacia())
        desencolar();
};

bool Cola::estaVacia() const
{
    return primer == nullptr;
};
