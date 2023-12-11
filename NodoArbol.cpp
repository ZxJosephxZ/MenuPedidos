#include "NodoArbol.hpp"

NodoArbol::NodoArbol(const Pedido &p): pedido(p),siguiente(nullptr), anterior(nullptr){};

NodoArbol*::NodoArbol::getAnterior() const
{
    return anterior;
};

Pedido& NodoArbol :: obtenerPedido()
{
    return (pedido);
}

NodoArbol*::NodoArbol::getSiguiente() const
{
    return siguiente;
};

void ::NodoArbol:: setAnterior(NodoArbol *anterior)
{
    this->anterior=anterior;
}

void ::NodoArbol:: setSiguiente(NodoArbol *siguiente)
{
    this->siguiente=siguiente;
}