#include "Pila.hpp"

Pila::Pila()
{
    cima = nullptr;
    longitud = 0;
};

void Pila::apilar(const Pedido &pedido)
{
    NodoPila *nuevoNodo = new NodoPila(pedido);
    nuevoNodo->setSiguiente(cima);
    cima = nuevoNodo;
    longitud++;
}

int Pila::pilaLongitud()
{
    return longitud;
}

void Pila::desapilar()
{
    if(!estaVacia() && longitud > 0)
    {
        NodoPila *temp = cima;
        cima = cima->getSiguiente();
        delete temp;
        longitud--;
    }
    else
    {
        cout << "ya esta vacio gilipollas" << endl;
    }
}

void Pila::setPrioridad(int num)
{
    cima->obtenerPedido().setPrioridad(num);
}

void Pila::setNumseg(int num)
{
    cima->obtenerPedido().setNumseg(num);
}

Pedido Pila::obtenerPedido()const
{
    return cima->obtenerPedido();
}

void Pila::mostrar()
{
    if(longitud > 0)
    {
        NodoPila *temp = cima;
        while(temp != nullptr)
        {
            temp->obtenerPedido().informe();
            temp = temp->getSiguiente();
        }
    }
    else
    {
        cout << "no hay contenido" <<endl;
    }
}

bool Pila:: tipoDato() const
{
    //el id lo he puesto igual a todos los parametros asique lo tomo como su distincion de prioridad
    return cima->obtenerPedido().getTipo();
}

bool Pila:: estaVacia() const
{
    return cima == nullptr;
}
Pila::~Pila()
{
    while(!estaVacia())
    {
        desapilar();
    }
}