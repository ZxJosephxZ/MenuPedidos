#include "Pedido.hpp"

Pedido :: Pedido(int dni, bool estandar): dni_cliente(dni), es_urgente(estandar)
{
    numSegui = 0;
    numPrioridad = 0;
};

int Pedido ::getDni() const
{
    return dni_cliente;
};

void Pedido::informe()
{
    if (getPrioridad() != 0)
    {
        cout << "El pedido a nombre del titular con DNI " << getDni() << " es de caracter";
        if(getTipo())
        {
            cout << " urgente, su ID es: " << getPrioridad() << " y su numero de seguimiento es: " << getNumSeguimiento() <<endl;
        }
        else if (getTipo() == 0)
        {
            cout << " estandar, su ID es: " << getPrioridad() << " y su numero de seguimiento es: " << getNumSeguimiento() <<endl;
        }
    }
    else
    {
            cout << "El pedido a nombre del titular con DNI " << getDni() << " es de caracter";
        if(getTipo())
        {
            cout << " urgente" << endl;
        }
        else if (getTipo() == 0)
        {
            cout << " estandar" <<endl;
        }
    }

}

void Pedido:: setPrioridad(int num)
{
    numPrioridad = num;
};

int Pedido:: getPrioridad() const
{
    return numPrioridad;
};

bool Pedido ::getTipo() const
{
    return es_urgente;
};

int Pedido ::getNumSeguimiento()
{
    return numSegui;
};

void Pedido:: setNumseg(int num)
{
    numSegui = num;
};

Pedido Pedido:: generarPedidoAleatoria()
{
    int dni = rand() % 90000000 + 10000000;
    int estandar = rand() % 2 == 0;
    return Pedido(dni,estandar);
};


Pedido::~Pedido(){};