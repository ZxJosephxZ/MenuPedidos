#include "NodoPila.hpp"

NodoPila::NodoPila(const Pedido& p): pedido(p), siguiente(nullptr){};
NodoPila* ::NodoPila:: getSiguiente() const
{
    return (siguiente);
}
void ::NodoPila:: setSiguiente(NodoPila *siguiente)
{
    this->siguiente = siguiente;
}

Pedido& NodoPila :: obtenerPedido()
{
    return (pedido);
}

NodoPila::~NodoPila()
{
};