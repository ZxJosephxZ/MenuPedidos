#include "NodoLista.hpp"

class Lista
{
    public:
        Lista();
        ~Lista();
        int obtenerPedidoMax() const;
        int obtenerPedidoMin() const;
        void obtenerPedidoLista(int max) const;
        void enListar(const Pedido &pedido);
        void desListar();
        bool estaVacia()const;
        bool tipoDato()const;
        void agregarLista(const Pedido &pedido);
        Pedido obtenerPedido()const;
        void mostrar();
        int obtenerListaLongitud();
    private:
        NodoLista *lista;
        NodoLista *ultimo;
        int longitud;
};