#ifndef PEDIDO_H
#define PEDIDO_H
#include <string>
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;
class Pedido
{
    public:
        Pedido(int dni, bool estandar);
        int getDni() const;
        bool getTipo() const;
        int getNumSeguimiento();
        Pedido generarPedidoAleatoria();
        void setNumseg(int num);
        void setPrioridad(int num);
        int getPrioridad() const;
        void informe();
        ~Pedido();
    private:
        int numSegui;
        int dni_cliente;
        int numPrioridad;
        bool es_urgente;
};
#endif