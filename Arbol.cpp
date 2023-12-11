#include <iostream>
#include "Arbol.hpp"

/*class NodoArbol {
public:
    int numeroSeguimiento;
    NodoArbol* izquierda;
    NodoArbol* derecha;

    NodoArbol(int numSeg)
        : numeroSeguimiento(numSeg), izquierda(nullptr), derecha(nullptr) {}
};*/
Arbol:: Arbol() { raiz = nullptr; }

void Arbol:: insertar(Pedido& pedido) 
{ 
    raiz = insertar(raiz, pedido);
}

NodoArbol* Arbol:: insertar(NodoArbol* nodo, Pedido& pedido)
{
    if(!nodo)
        return new NodoArbol(pedido);
    if(pedido.getNumSeguimiento() <= nodo->obtenerPedido().getNumSeguimiento())
        nodo->setAnterior(insertar(nodo->getAnterior(), pedido));
    else
        nodo->setSiguiente(insertar(nodo->getSiguiente(), pedido));
    return nodo;
}

void Arbol::dibujar()
{
    int h = altura(raiz);
    vector<string> output(h), linkAbove(h);
    dibujarNodo(output, linkAbove, raiz, 0, 5, ' ');

    for(int i = 1; i < h; i++) {
        for(int j = 0; j < static_cast<int>(linkAbove[i].size()); j++) {
            if(linkAbove[i][j] != ' ') {
                int size = output[i - 1].size();
                if(size < j + 1)
                    output[i - 1] += string(j + 1 - size, ' ');
                int jj = j;
                if(linkAbove[i][j] == 'L') {
                    while(output[i - 1][jj] == ' ')
                        jj++;
                    for(int k = j + 1; k < jj - 1; k++)
                        output[i - 1][k] = '_';
                } else if(linkAbove[i][j] == 'R') {
                    while(output[i - 1][jj] == ' ')
                        jj--;
                    for(int k = j - 1; k > jj + 1; k--)
                        output[i - 1][k] = '_';
                }
                linkAbove[i][j] = '|';
            }
        }
    }

    cout << '\n' << '\n';
    for(int i = 0; i < h; i++) {
        if(i)
            cout << linkAbove[i] << '\n';
        cout << output[i] << '\n';
    }
    cout << '\n' << '\n';
}

int Arbol::altura(NodoArbol* nodo)
{
    if(!nodo)
        return 0;
    return 1 + max(altura(nodo->getAnterior()), altura(nodo->getSiguiente()));
}

void Arbol::dibujarNodo(vector<string>& output, vector<string>& linkAbove, NodoArbol* nodo, int nivel, int p, char linkChar)
{
    if(!nodo)
        return;

    int h = output.size();
    string SP = " ";

    if(p < 0) {
        string extra(-p, ' ');
        for(string& s : output)
            if(!s.empty())
                s = extra + s;
        for(string& s : linkAbove)
            if(!s.empty())
                s = extra + s;
    }
    if(nivel < h - 1)
        p = max(p, (int)output[nivel + 1].size());
    if(nivel > 0)
        p = max(p, (int)output[nivel - 1].size());
    p = max(p, (int)output[nivel].size());

    if(nodo->getAnterior()) {
        int numeroQueQuieroImprimirEnElArbol = nodo->getAnterior()->obtenerPedido().getNumSeguimiento();
            //nodo->izq->dato; // En vez de este valor, tenéis que coger el número de la habitación del paciente.
        string izqdato = SP + to_string(numeroQueQuieroImprimirEnElArbol) + SP;
        dibujarNodo(output, linkAbove, nodo->getAnterior(), nivel + 1, p - izqdato.size(), 'L');
        p = max(p, (int)output[nivel + 1].size());
    }

    int space = p - output[nivel].size();
    if(space > 0)
        output[nivel] += string(space, ' ');
    int numeroQueQuieroImprimirEnElArbol = nodo->obtenerPedido().getNumSeguimiento();
        //nodo->dato; // En vez de este valor, tenéis que coger el número de la habitación del paciente.
    string nododato = SP + to_string(numeroQueQuieroImprimirEnElArbol) + SP;
    output[nivel] += nododato;

    space = p + SP.size() - linkAbove[nivel].size();
    if(space > 0)
        linkAbove[nivel] += string(space, ' ');
    linkAbove[nivel] += linkChar;

    if(nodo->getSiguiente())
        dibujarNodo(output, linkAbove, nodo->getSiguiente(), nivel + 1, output[nivel].size(), 'R');
}

void Arbol::pintarEstandar()
{
    pintarEstandar(raiz);
    cout << '\n';
}
void Arbol::pintarEstandar(NodoArbol* nodo)
{
    if(!nodo) return;
    
    if(nodo->obtenerPedido().getNumSeguimiento() <= 500){
        pintarEstandar(nodo->getAnterior());
        if(nodo->obtenerPedido().getNumSeguimiento() != 500) cout << nodo->obtenerPedido().getNumSeguimiento() << " ";
        pintarEstandar(nodo->getSiguiente()); 
    }
        
}

void Arbol::pintarUrgente()
{
    pintarUrgente(raiz);
    cout << '\n';
}
void Arbol::pintarUrgente(NodoArbol* nodo)
{
    if(!nodo) return;
    
    if(nodo->obtenerPedido().getNumSeguimiento() >= 500){
        pintarUrgente(nodo->getAnterior());
        if(nodo->obtenerPedido().getNumSeguimiento() != 500) cout << nodo->obtenerPedido().getNumSeguimiento() << " ";
        pintarUrgente(nodo->getSiguiente()); 
    }
        
}

void Arbol::inorden()
{
    inorden(raiz);
    cout << '\n';
}

void Arbol::inorden(NodoArbol* nodo) {
    if (nodo != nullptr) {
        inorden(nodo->getAnterior());
        if(nodo->obtenerPedido().getNumSeguimiento() != 500) nodo->obtenerPedido().informe(); // Muestra el pedido en lugar de solo el número de seguimiento
        inorden(nodo->getSiguiente());
    }
}

void Arbol::mostrarEnOrden()
{
    enorden(raiz);
}

void Arbol::enorden(NodoArbol* nodo)
{
    if (nodo == nullptr)
    {
        return;
    }
    enorden(nodo->getSiguiente());
    if (nodo->getSiguiente() == nullptr && nodo->getAnterior() == nullptr)
    {
        mostrarNodoHoja(nodo);
    }
    enorden(nodo->getAnterior());
}

void Arbol::mostrarNodoHoja(NodoArbol* nodo)
{
    nodo->obtenerPedido().informe();
}

NodoArbol* Arbol::encontrarNodo(NodoArbol* nodo, int numSegui)
{
    if (nodo == nullptr || nodo->obtenerPedido().getNumSeguimiento() == numSegui)
    {
        return nodo;
    }

    if (numSegui < nodo->obtenerPedido().getNumSeguimiento())
    {
        return encontrarNodo(nodo->getSiguiente(), numSegui);
    }
    else
    {
        return encontrarNodo(nodo->getAnterior(), numSegui);
    }
}

void Arbol::eliminarPedidoSegui(int numSegui)
{
    NodoArbol* nodoEliminar = encontrarNodo(raiz, numSegui);
    if (nodoEliminar != nullptr)
    {
        eliminarNodo(nodoEliminar);
    }
    else
    {
        cout << "No se encontro el pedido" << endl;
    }
}

NodoArbol* Arbol::encontrarNodoPadre(NodoArbol* nodo, int numSegui)
{
    if (nodo == nullptr || (nodo->getSiguiente() != nullptr && nodo->getSiguiente()->obtenerPedido().getNumSeguimiento() == numSegui) ||
    (nodo->getAnterior() != nullptr && nodo->getAnterior()->obtenerPedido().getNumSeguimiento() == numSegui))
    {
        return nodo;
    }
    if (numSegui < nodo->obtenerPedido().getNumSeguimiento())
    {
        return encontrarNodoPadre(nodo->getSiguiente(),numSegui);
    }
    else
    {
        return encontrarNodoPadre(nodo->getAnterior(),numSegui);
    }
}

NodoArbol* Arbol::encontrarNodoSucesor(NodoArbol* nodo)
{
    NodoArbol* actual = nodo->getAnterior();
    while (actual != nullptr && actual->getSiguiente() != nullptr)
    {
        actual = actual->getSiguiente();
    }
    return actual;
}

void Arbol::eliminarNodo(NodoArbol* nodo)
{
    if (nodo->getSiguiente() == nullptr && nodo->getAnterior() == nullptr)
    {
        NodoArbol* padre = encontrarNodoPadre(raiz,nodo->obtenerPedido().getNumSeguimiento());
        if (padre != nullptr)
        {
            if (padre->getSiguiente() == nodo)
            {
                delete(padre->getSiguiente());
                padre->setSiguiente(nullptr);
            }
            else
            {
                delete(raiz);
                raiz = nullptr;
            }
        }
    }else if (nodo->getSiguiente() == nullptr)
    {
        NodoArbol* sucesor = nodo->getAnterior();
        NodoArbol* padre = encontrarNodoPadre(raiz,nodo->obtenerPedido().getNumSeguimiento());
        if (padre == nullptr)
        {
            if (padre->getSiguiente() == nodo)
            {
                padre->setSiguiente(sucesor);
            }
            else
            {
                padre->setAnterior(sucesor);
            }
        }
        else
        {
            raiz = sucesor;
        }
        delete(nodo);
    }
    else if (nodo->getAnterior() == nullptr)
    {
        NodoArbol* sucesor = nodo->getSiguiente();
        NodoArbol* padre = encontrarNodoPadre(raiz,nodo->obtenerPedido().getNumSeguimiento());
        if (padre != nullptr)
        {
            if (padre->getSiguiente() == nodo)
            {
                padre->setSiguiente(sucesor);
            }
            else
            {
                padre->setAnterior(sucesor);
            }
        }
        else
        {
            raiz = sucesor;
        }
        delete (nodo);
    }
    else
    {
        NodoArbol* sucesor = encontrarNodoSucesor(nodo);
        nodo->obtenerPedido() = sucesor->obtenerPedido();
        eliminarNodo(sucesor);
    }

}

void Arbol::estandarSeguimientoMenor()
{
    Pedido menor=estandarSeguimientoMenor(raiz);
    cout << "\tPEDIDO ESTANDAR CON MENOR NUMERO DE SEGUIMIENTO\n";
    menor.informe();
}
Pedido Arbol::estandarSeguimientoMenor(NodoArbol* nodo) {
    if (nodo != nullptr && nodo->obtenerPedido().getNumSeguimiento() <= 500) {
        while (nodo->getAnterior() != nullptr) {
        nodo = nodo->getAnterior();
        }
    if(nodo->obtenerPedido().getNumSeguimiento() != 500) return nodo->obtenerPedido();
    }
}

void Arbol::estandarSeguimientoMayor()
{
    Pedido mayor=estandarSeguimientoMayor(raiz);
    cout << "\tPEDIDO ESTANDAR CON MAYOR NUMERO DE SEGUIMIENTO\n";
    mayor.informe();
}
Pedido Arbol::estandarSeguimientoMayor(NodoArbol* nodo) {
    nodo = nodo->getAnterior();
    if (nodo->getSiguiente() != nullptr ) {
        while (nodo->getSiguiente() != nullptr && nodo->getSiguiente()->obtenerPedido().getNumSeguimiento() <= 500) {
        nodo = nodo->getSiguiente();
        }
    if(nodo->obtenerPedido().getNumSeguimiento() != 500) return nodo->obtenerPedido();
    }
}


/*
void Arbol::insertar(Pedido val) { 
    raiz = insertar(raiz, val); 
    }
    
class ArbolBinarioBusqueda {
private:
    NodoArbol* raiz;

    // Función auxiliar para la inserción de un pedido en el árbol
    NodoArbol* insertarPedido(NodoArbol* nodo, int numSeg, int tipoPedido) {
        if (nodo == nullptr) {
            return new NodoArbol(numSeg);
        }

        if (numSeg <= nodo->numeroSeguimiento) {
            nodo->izquierda = insertarPedido(nodo->izquierda, numSeg, tipoPedido);
        } else {
            nodo->derecha = insertarPedido(nodo->derecha, numSeg, tipoPedido);
        }

        return nodo;
    }

    // Función auxiliar para recorrer el árbol en orden
    void inorden(NodoArbol* nodo) {
        if (nodo != nullptr) {
            inorden(nodo->izquierda);
            std::cout << nodo->numeroSeguimiento << " ";
            inorden(nodo->derecha);
        }
    }

public:
    ArbolBinarioBusqueda() : raiz(nullptr) {
        // Inicializar la raíz con el valor 500
        raiz = new NodoArbol(500);
    }

    // Función pública para insertar un pedido en el árbol
    void insertarPedido(int numSeg, int tipoPedido) {
        raiz = insertarPedido(raiz, numSeg, tipoPedido);
    }

    // Función pública para mostrar el árbol en orden
    void mostrarEnOrden() {
        inorden(raiz);
        std::cout << std::endl;
    }
};
 
int main() {
    ArbolBinarioBusqueda arbol;

    // Insertar pedidos en el árbol
    arbol.insertarPedido(400, 0); // Pedido estandar
    arbol.insertarPedido(600, 1); // Pedido urgente
    arbol.insertarPedido(300, 0); // Pedido estandar
    arbol.insertarPedido(650,0);
    arbol.insertarPedido(700, 1); // Pedido urgente

    // Mostrar el árbol en orden
    std::cout << "Árbol en orden: ";
    arbol.mostrarEnOrden();

    return 0;
}*/
Arbol::~Arbol() {}
