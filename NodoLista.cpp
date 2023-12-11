#include "NodoLista.hpp"

NodoLista::NodoLista(const Pedido &p): siguiente(nullptr), anterior(nullptr),pedido(p){};

NodoLista* ::NodoLista:: getSiguiente() const
{
    return (siguiente);
}

 NodoLista* ::NodoLista:: getAnterior() const
 {
    return (anterior);
 }

void ::NodoLista:: setSiguiente(NodoLista *siguiente)
{
    this->siguiente = siguiente;
}

void ::NodoLista:: setAnteriror(NodoLista *anterior)
{
    this->anterior = anterior;
}

Pedido& NodoLista :: obtenerPedido()
{
    return (pedido);
}

NodoLista::~NodoLista(){};