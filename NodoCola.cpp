#include "NodoCola.hpp"

NodoCola::NodoCola(const Pedido& p): pedido(p), siguiente(nullptr){};

NodoCola* ::NodoCola:: getSiguiente() const
{
    return (siguiente);
}

void ::NodoCola:: setSiguiente(NodoCola *siguiente)
{
    this->siguiente = siguiente;
}

Pedido& NodoCola :: obtenerPedido()
{
    return (pedido);
}
NodoCola::~NodoCola()
{
};