#include "Gestor.hpp"
#include <stdlib.h>
#include <random>

Gestor::Gestor(){};

void Gestor::genera12Pedidos()
{
    srand(static_cast<unsigned>(time(nullptr)));
    if(pila.pilaLongitud() >= 0 && pila.pilaLongitud() < 48)
    {
        for(int i = 0; i<12;i++)
        {
            Pedido pedido1(pedido1.generarPedidoAleatoria());
            pila.apilar(pedido1);
        }
        cout << "Pedidos creados con  exito y depositado en la pila" << endl;
    }
    else
    {
        cout << "pila llena" << endl;
    }
    
};

void Gestor::muestraPedidosEstandar()
{
    cout << "Lista estandar:" << endl;
    estandar.mostrar();
}

void Gestor::maxPedidoEstandar()
{
    cout << "Pedido estandar con mayor prioridad:" << endl;
    Lista nuevoNodo = estandar;
}

void Gestor::muestraPedidosUrgentes()
{
    cout << "Lista urgente:" <<endl;
    urgente.mostrar();
}

void Gestor::maxPedidoUrgente()
{
    cout << "Pedido urgente con menor prioridad:" << endl;
    urgente.obtenerPedidoLista(urgente.obtenerPedidoMin());
}

void Gestor::enlistarPedidos()
{
    if(colaA.estaVacia() && colaB.estaVacia() && colaC.estaVacia() && colaD.estaVacia())
    {
        cout << "no se puede establecer la simulacion, colas vacias" << endl;
    }
    while(!colaA.estaVacia() || !colaB.estaVacia() || !colaC.estaVacia() || !colaD.estaVacia())
    {
        if(!colaA.estaVacia())
        {
            estandar.agregarLista(colaA.pedidoCola());
            colaA.desencolar();
        }
        if(!colaB.estaVacia())
        {
            estandar.agregarLista(colaB.pedidoCola());
            colaB.desencolar();
        }
        if(!colaC.estaVacia())
        {
            urgente.agregarLista(colaC.pedidoCola());
            colaC.desencolar();
        }
        if(!colaD.estaVacia())
        {
            urgente.agregarLista(colaD.pedidoCola());
            colaD.desencolar();
        }
    }
}

void Gestor::muestraPedidos()
{
    if(!pila.estaVacia())
    {
        pila.mostrar();
    }
    else
    {
        cout << "pila vacia" << endl;
    }
};

void Gestor::borraPedidosPila()
{
    cout << "Pedidos borrados con exito" << endl;
    pila.~Pila();
};

void Gestor::buscarPedidos()
{
    maxPedidoEstandar();
    maxPedidoUrgente();
}

int Gestor::PedidosEnPila()
{
    return pila.pilaLongitud();
}

int Gestor::PedidosEnSalaA()
{
    return colaA.colaLongitud();
}

int Gestor::PedidosEnSalaB()
{
    return colaB.colaLongitud();
}

int Gestor::PedidosEnSalaC()
{
    return colaC.colaLongitud();
}

int Gestor::PedidosEnSalaD()
{
    return colaD.colaLongitud();
}

int Gestor::PedidosEnListaEstandar()
{
    return estandar.obtenerListaLongitud();
}

int Gestor::PedidosEnListaUrgentes()
{
    return urgente.obtenerListaLongitud();
}

int Gestor::PedidosEnArbol(){
    return raiz.arbolLongitud();
}

void Gestor::reiniciar()
{
    estandar.~Lista();
    urgente.~Lista();
    pila.~Pila();
    colaA.~Cola();
    colaB.~Cola();
    colaC.~Cola();
    colaD.~Cola();
    cout << "Reinicio realizado con exito" << endl;
};

void Gestor::encolarPedidos()
{
    //srand(static_cast<unsigned>(time(nullptr)) + 1);
    std::random_device rd;
    std::mt19937 gen(rd()); // Utilizar una semilla diferente
    std::uniform_int_distribution<> ajusteDistribution(1, 49);
    std::uniform_int_distribution<> reajusteDistribution(1, 499);
    std::uniform_int_distribution<> ajusteDistribution1(49, 99);
    std::uniform_int_distribution<> reajusteDistribution1(500, 999);

    if(pila.estaVacia())
    {
        cout << "no se ha podido establecer la simulacion, pila vacia" << endl;
    }
    while(!pila.estaVacia())
    {
        if(!pila.tipoDato())
        {
            int ajuste = ajusteDistribution(gen);
            int reajuste = reajusteDistribution(gen);
            //va hacia a y b
            if(colaA.colaLongitud() <= colaB.colaLongitud())
            {
                pila.setPrioridad(ajuste);
                pila.setNumseg(reajuste);
                colaA.encolar(pila.obtenerPedido());
                pila.desapilar();
            }
            else
            {
                pila.setPrioridad(ajuste);
                pila.setNumseg(reajuste);
                colaB.encolar(pila.obtenerPedido());
                pila.desapilar();
            }
        }
        else
        {
            int ajuste = ajusteDistribution1(gen);
            int reajuste = reajusteDistribution1(gen);
            //va hacia c y d
            if(colaC.colaLongitud() <= colaD.colaLongitud())
            {
                pila.setPrioridad(ajuste);
                pila.setNumseg(reajuste);
                colaC.encolar(pila.obtenerPedido());
                pila.desapilar();
            }
            else
            {
                pila.setPrioridad(ajuste);
                pila.setNumseg(reajuste);
                colaD.encolar(pila.obtenerPedido());
                pila.desapilar();
            }
        }
    }
    cout << "simulacion terminada con exito"<<endl;
};

void Gestor:: borraPedidosColas()
{
    colaA.~Cola();
    colaB.~Cola();
    colaC.~Cola();
    colaD.~Cola();
    cout << "Liberacion realizada con exito" << endl;
};

void Gestor:: muestraPedidosSalasAyB()
{
    cout << "Sala A:" << endl;
    colaA.mostrar();
    cout << "Sala B:" << endl;
    colaB.mostrar();
};

void Gestor:: muestraPedidosSalasCyD()
{
    cout << "Sala C:" << endl;
    colaC.mostrar();
    cout << "Sala D:" << endl;
    colaD.mostrar();
};

void Gestor:: crearArbol(){
    if(estandar.estaVacia()&&urgente.estaVacia())
    {
        cout << "no se ha podido establecer la simulacion, listas vacias" << endl;
    }else{
        Pedido pedido500(pedido500.generarPedidoAleatoria());
        pedido500.setNumseg(500);
        raiz.insertar(pedido500);
        raiz.setLongitud(0);
        
        while(!estandar.estaVacia()){
            Pedido e=estandar.obtenerPedido();
            //raiz.insertar(estandar.obtenerPedido());
            raiz.insertar(e);
            estandar.desListar();
        }
        while(!urgente.estaVacia()){
            //raiz.insertar(urgente.obtenerPedido());
            Pedido u=urgente.obtenerPedido();
            raiz.insertar(u);
            urgente.desListar();
        }
    }
    
    cout << endl << "\nMi Abb: ";
    raiz.dibujar();
}

void Gestor:: mostrarEstandarArbol(){
    raiz.pintarEstandar();
}
void Gestor:: mostrarUrgenteArbol(){
    raiz.pintarUrgente();
}
void Gestor:: inordenArbol(){
    raiz.inorden();
}

void Gestor:: buscarPedidosArbol(){
    raiz.estandarSeguimientoMenor();
    raiz.estandarSeguimientoMayor();

    Pedido& MenorPrioridad = raiz.obtenerUrgenteIdMenor();
    cout << "\tPEDIDO URGENTE CON MENOR ID " << endl;
    MenorPrioridad.informe();
    
    Pedido& MayorPrioridad = raiz.obtenerUrgenteIdMayor();
    cout << "\tPEDIDO URGENTE CON MAYOR ID " << endl;
    MayorPrioridad.informe();
}

void Gestor::mostrarHojas()
{
    raiz.mostrarEnOrden();
}

void Gestor::eliminarNodoHoja()
{
    int numero;
    raiz.dibujar();
    cout << "Ingresa el numero de seguimiento: ";
    cin >> numero;
    numero = (int)numero;
    if ((numero > 0 && numero < 999) && numero != 500)
    {
        raiz.eliminarPedidoSegui(numero);
        raiz.dibujar();
    }
    else
    {   cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "numero introducido incorrectamente"<<endl;
    }
    
}

void Gestor:: contarImpares(){
    cout << "\n\tPedidos Impares -> " << raiz.numeroSeguimientoImpar() << endl;
}

Gestor::~Gestor(){};