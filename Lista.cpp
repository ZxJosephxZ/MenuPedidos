#include "Lista.hpp"

Lista::Lista()
{
    lista= nullptr;
    ultimo=nullptr;
    longitud = 0;
};

int Lista:: obtenerPedidoMax() const
{
    NodoLista *lista1 = lista;
    int max = 0;
    while(lista1 != nullptr)
    {
        if(max < lista1->obtenerPedido().getPrioridad())
        {
            max = lista1->obtenerPedido().getPrioridad();
        }
        lista1 = lista1->getSiguiente();
    }
    return (max);
}

int Lista:: obtenerPedidoMin() const
{
    NodoLista *lista1 = lista;
    int min = 0;
    if(lista1 != nullptr)
    {
        min = lista1->obtenerPedido().getPrioridad();
    }
    while(lista1 != nullptr)
    {
        if(min > lista1->obtenerPedido().getPrioridad())
        {
            min = lista1->obtenerPedido().getPrioridad();
        }
        lista1 = lista1->getSiguiente();
    }
    return (min);
}

int Lista::obtenerListaLongitud()
{
    return longitud;
}

void Lista:: obtenerPedidoLista(int max) const
{
    NodoLista *lista1 = lista;

    if(lista1 == nullptr)
    {
        cout << "pedido no encontrado" << endl;
    }
    while(lista1 != nullptr)
    {
        if(lista1->obtenerPedido().getPrioridad() == max)
        {
            lista1->obtenerPedido().informe();
        }
        lista1 = lista1->getSiguiente();
    }

}

void Lista::enListar(const Pedido &pedido)
{
    NodoLista *nuevoNodo = new NodoLista(pedido);
    nuevoNodo->setSiguiente(lista);
    lista = nuevoNodo;
    longitud++;
}
void Lista::desListar()
{
    if(!estaVacia() && longitud > 0)
    {
        NodoLista *temp = lista;
        lista = lista->getSiguiente();
        delete temp;
        longitud--;
    }
    else
    {
        cout << "ya esta vacio gilipollas" << endl;
    }
}

Pedido Lista::obtenerPedido()const
{
    return lista->obtenerPedido();
}

void Lista::mostrar()
{
    if(longitud > 0)
    {
        NodoLista *temp = lista;
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

bool Lista:: tipoDato() const
{
    //el id lo he puesto igual a todos los parametros asique lo tomo como su distincion de prioridad
    return lista->obtenerPedido().getTipo() == true;
}

bool Lista:: estaVacia() const
{
    return lista == nullptr;
}
Lista::~Lista()
{
    while(!estaVacia())
    {
        desListar();
    }
}

void Lista:: agregarLista(const Pedido &pedido)
{
    NodoLista* nuevoNodo = new NodoLista(pedido);
    
    if (!lista) {
        // La lista está vacía, el nuevo nodo es el primero
        lista = nuevoNodo;
        ultimo = nuevoNodo;
    } else {
        NodoLista* actual = lista;
        while (actual && actual->obtenerPedido().getPrioridad() > pedido.getPrioridad()) {
            actual = actual->getSiguiente();
        }

        if (!actual) {
            // El nuevo pedido es el último
            nuevoNodo->setAnteriror(ultimo);
            ultimo->setSiguiente(nuevoNodo);
            ultimo = nuevoNodo;
        } else if (actual == lista) {
            // El nuevo pedido es el primero
            nuevoNodo->setSiguiente(lista);
            lista->setAnteriror(nuevoNodo);
            lista = nuevoNodo;
        } else {
            // El nuevo pedido está en el medio
            nuevoNodo->setSiguiente(actual);
            nuevoNodo->setAnteriror(actual->getAnterior());
            actual->getAnterior()->setSiguiente(nuevoNodo);
            actual->setAnteriror(nuevoNodo);
        }
    }

    // Incrementamos la longitud de la lista
    longitud++;
}