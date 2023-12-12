#include "NodoArbol.hpp"
#include <vector>
using namespace std;

class Arbol
{
    public:
        Arbol();
        int arbolLongitud();
        void setLongitud(int num);
        void insertarPedido(Pedido &p);
        void mostrarEnOrden();
        void insertar(Pedido &p);
        void pintar();
        void dibujar();
        void pintarEstandar();
        void pintarUrgente();
        void inorden();
        void estandarSeguimientoMenor();
        void estandarSeguimientoMayor();
        Pedido& obtenerUrgenteIdMayor();
        Pedido& obtenerUrgenteIdMenor();
        int numeroSeguimientoImpar();
        void eliminarPedidoSegui(int numSegui);

        ~Arbol();
    private:
        NodoArbol *raiz;
        NodoArbol* insertar(NodoArbol* nodo, Pedido& pedido);
        NodoArbol* encontrarNodo(NodoArbol* nodo, int numSegui);
        NodoArbol* encontrarNodoPadre(NodoArbol* nodo, int numSegui);
        NodoArbol* encontrarNodoSucesor(NodoArbol* nodo);
        void pintar(NodoArbol*);
        int altura(NodoArbol*);
        void dibujarNodo(vector<string>& output, vector<string>& linkAbove, NodoArbol* nodo, int nivel, int minPos, char linkChar);
        void pintarEstandar(NodoArbol*);
        void pintarUrgente(NodoArbol*);
        void inorden(NodoArbol*);
        void enorden(NodoArbol*);
        void eliminarNodo(NodoArbol* nodo);
        void mostrarNodoHoja(NodoArbol* nodo);
        Pedido estandarSeguimientoMenor(NodoArbol*);
        Pedido estandarSeguimientoMayor(NodoArbol*);
        void urgenteIdMayor(NodoArbol*);
        void urgenteIdMenor(NodoArbol*);
        void numeroSeguimientoImpar(NodoArbol*);
        Pedido* mayorPedido;
        Pedido* menorPedido;
        int longitud;
        int impares;
};