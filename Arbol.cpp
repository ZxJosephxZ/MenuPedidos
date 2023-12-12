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
Arbol:: Arbol() { raiz = nullptr; longitud = 0; }

int Arbol::arbolLongitud()
{
    return longitud;
}
void Arbol:: setLongitud(int num)
{
    longitud = num;
};

void Arbol:: insertar(Pedido& pedido) 
{ 
    raiz = insertar(raiz, pedido);
    longitud++;
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
    pintarEstandar(raiz->getAnterior());
    cout << '\n';
}
void Arbol::pintarEstandar(NodoArbol* nodo)
{
    if(!nodo) return;
    
    if(nodo->obtenerPedido().getNumSeguimiento() <= 500){
        pintarEstandar(nodo->getAnterior());
        if(nodo->obtenerPedido().getNumSeguimiento() != 500) nodo->obtenerPedido().informe();
        pintarEstandar(nodo->getSiguiente()); 
    }
        
}

void Arbol::pintarUrgente()
{
    pintarUrgente(raiz->getSiguiente());
    cout << '\n';
}
void Arbol::pintarUrgente(NodoArbol* nodo)
{
    if(!nodo) return;
    
    if(nodo->obtenerPedido().getNumSeguimiento() >= 500){
        pintarUrgente(nodo->getAnterior());
        if(nodo->obtenerPedido().getNumSeguimiento() != 500) nodo->obtenerPedido().informe();
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
        if(nodo->obtenerPedido().getNumSeguimiento() != 500) nodo->obtenerPedido().informe();
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
        return encontrarNodo(nodo->getAnterior(), numSegui);
    }
    else
    {
        return encontrarNodo(nodo->getSiguiente(), numSegui);
    }
}

void Arbol::eliminarPedidoSegui(int numSegui)
{
    NodoArbol* nodoEliminar = encontrarNodo(raiz, numSegui);
    if (nodoEliminar != nullptr)
    {
        eliminarNodo(nodoEliminar);
        setLongitud(arbolLongitud() - 1);
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
        return encontrarNodoPadre(nodo->getAnterior(),numSegui);
    }
    else
    {
        return encontrarNodoPadre(nodo->getSiguiente(),numSegui);
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
            else if (padre->getAnterior() == nodo)
            {
                delete (padre->getAnterior());
                padre->setAnterior(nullptr);
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
    else {
        NodoArbol* padre = encontrarNodoPadre(raiz,nodo->obtenerPedido().getNumSeguimiento());
        NodoArbol* sucesor = encontrarNodoSucesor(nodo);
        NodoArbol* padreSucesor = encontrarNodoPadre(raiz, sucesor->obtenerPedido().getNumSeguimiento());

        if (padreSucesor != nullptr) {
            if (padreSucesor->getSiguiente() == sucesor) {
                padreSucesor->setSiguiente(nullptr);
            } else {
                padreSucesor->setAnterior(nullptr);
            }
        } else {
            // Si no hay padre sucesor, actualiza el puntero de raíz
            raiz = sucesor;
        }

        if (padre != nullptr) {
            if (padre->getSiguiente() == nodo) {
                padre->setSiguiente(sucesor);
            } else {
                padre->setAnterior(sucesor);
            }
        }

        sucesor->setAnterior(nodo->getAnterior());
        sucesor->setSiguiente(nodo->getSiguiente());

        delete nodo;
    }

}

void Arbol::estandarSeguimientoMenor()
{
    Pedido menor=estandarSeguimientoMenor(raiz->getAnterior());
    cout << "\tPEDIDO ESTANDAR CON MENOR NUMERO DE SEGUIMIENTO\n";
    menor.informe();
}
Pedido Arbol::estandarSeguimientoMenor(NodoArbol* nodo) {
    while (nodo->getAnterior() != nullptr) {
    nodo = nodo->getAnterior();
    }
    return nodo->obtenerPedido();
}

void Arbol::estandarSeguimientoMayor()
{
    Pedido mayor=estandarSeguimientoMayor(raiz->getAnterior());
    cout << "\tPEDIDO ESTANDAR CON MAYOR NUMERO DE SEGUIMIENTO\n";
    mayor.informe();
}
Pedido Arbol::estandarSeguimientoMayor(NodoArbol* nodo) {
    while (nodo->getSiguiente() != nullptr){// && nodo->getSiguiente()->obtenerPedido().getNumSeguimiento() <= 500) {
    nodo = nodo->getSiguiente();
    }
    return nodo->obtenerPedido();
}

Pedido& Arbol::obtenerUrgenteIdMenor() {
    menorPedido = nullptr;
    
    urgenteIdMenor(raiz->getSiguiente());
    return *menorPedido;
}

void Arbol::urgenteIdMenor(NodoArbol* nodo){
    
    if (nodo != nullptr) {
        if (menorPedido == nullptr || nodo->obtenerPedido().getPrioridad() < menorPedido->getPrioridad()) {
            menorPedido = &nodo->obtenerPedido();
        }
        urgenteIdMenor(nodo->getAnterior());
        urgenteIdMenor(nodo->getSiguiente());
    }
}

Pedido& Arbol::obtenerUrgenteIdMayor() {
    mayorPedido = nullptr;
    urgenteIdMayor(raiz->getSiguiente());
    return *mayorPedido;
}
void Arbol::urgenteIdMayor(NodoArbol* nodo){
    if (nodo != nullptr) {
        if (mayorPedido == nullptr || nodo->obtenerPedido().getPrioridad() > mayorPedido->getPrioridad()) {
            mayorPedido = &nodo->obtenerPedido();
        }
        urgenteIdMayor(nodo->getAnterior());
        urgenteIdMayor(nodo->getSiguiente());
    }
}

int Arbol::numeroSeguimientoImpar(){
    impares = 0;
    numeroSeguimientoImpar(raiz);
    return impares;
}

void Arbol::numeroSeguimientoImpar(NodoArbol* nodo){
    if (nodo != nullptr) {
        if(nodo->obtenerPedido().getNumSeguimiento() != 500 && nodo->obtenerPedido().getNumSeguimiento()%2 != 0 ) {
            impares++;
        }
        numeroSeguimientoImpar(nodo->getAnterior());
        numeroSeguimientoImpar(nodo->getSiguiente());
    }
}

Arbol::~Arbol() {}
