
#include "Gestor.hpp"

int main(int argc, char** argv)
{
    Gestor gestor;
    char opcion;

    do {

        cout << "\n\t--------------------------------------------------------------"
                "--------\n";
        cout << "\tPedidos en la pila -> " << gestor.PedidosEnPila()
             << "\n\tPedidos en las colas:\n \t\tSala A-> " << gestor.PedidosEnSalaA() << "\tSala B-> "
             << gestor.PedidosEnSalaB() << "\tSala C-> " << gestor.PedidosEnSalaC()  << "\tSala D-> "
             << gestor.PedidosEnSalaD()
             << " \n\tPedidos en las listas:\n \t\tEstandar-> "
             << gestor.PedidosEnListaEstandar() << "\tUrgentes-> " << gestor.PedidosEnListaUrgentes()
             << "\n\tPedidos en el arbol -> " << gestor.PedidosEnArbol()
             << "\n";
        cout << "\t----------------------------------------------------------------"
                "------\n\n";

        cout << "\tA. Generar 12 Pedidos de forma aleatoria y almacenarlos en la "
                "Pila.\n";
        cout << "\tB. Consultar todos los Pedidos generados en la Pila (pendientes "
                "de entrar en las salas).\n";
        cout << "\tC. Borrar los Pedidos generados en la pila.\n";
        cout << "\tD. Simular llegada de los Pedidos en las colas.\n";
        cout << "\tE. Consultar los Pedidos de las salas A y B.\n";
        cout << "\tF. Consultar los Pedidos de las salas C y D.\n";
        cout << "\tG. Borrar los todos los Pedidos de las salas.\n";
        cout << "\tH. Simular la entrada de los Pedidos a las listas.\n";
        cout << "\tI. Mostrar los Pedidos que hay en la lista Estandar.\n";
        cout << "\tJ. Mostrar los Pedidos que hay en la lista Urgentes.\n";
        cout << "\tK. Buscar en las listas el Pedido Estandar de mayor prioridad y "
                "el pedido Urgente con menor prioridad "
                "prioridad.\n";
        cout << "\tL. Reiniciar el programa.\n";
        cout << "\tM. Crear y dibujar el ABB en consola.\n";
        cout << "\tN. Mostrar los datos de todos los Pedidos Estandar ordenados "
                "por numero de seguimiento en orden ascendente.\n";
        cout << "\tO. Mostrar los datos de todos los Pedidos Urgentes ordenados "
                "por numero de seguimiento en orden ascendente.\n";
        cout << "\tP. Mostrar los datos de todos los Pedidos recorriendo el arbol "
                "en inorden.\n";
        cout << "\tQ. Buscar en el ABB el Pedido Estándar con el numero de "
                "seguimiento mas alto y mas bajo, asi como los Pedidos Urgentes "
                "con el numero de ID mas alto y mas bajo.\n";
        cout << "\tR. Contar el numero de Pedidos almacenados en el ABB cuyos "
                "numeros de seguimiento son impares.\n";
        cout << "\tT. Mostrar los Pedidos que se encuentran almacenados en un nodo "
                "hoja.\n";
        cout << "\tU. Eliminar un Pedido indicado por su numero de seguimiento "
                "(que se pide desde consola) y mostrar el arbol "
                "resultante tras la eliminacion de dicho Pedido.\n";
        cout << "\tS. Salir.\n\n";

        cout << "\tIndique la opcion deseada: ";
        cin >> opcion;
        opcion = toupper(opcion);
        system("clear");
        system("cls");

        switch(opcion) {

        case 'A':
            gestor.genera12Pedidos();
            break;
        case 'B':
            gestor.muestraPedidos();
            break;
        case 'C':
            gestor.borraPedidosPila();
            break;
        case 'D':
            gestor.encolarPedidos();
            break;
        case 'E':
            gestor.muestraPedidosSalasAyB();
            break;
        case 'F':
            gestor.muestraPedidosSalasCyD();
            break;
        case 'G':
            gestor.borraPedidosColas();
            break;
        case 'H':
            gestor.enlistarPedidos();
            break;
        case 'I':
            gestor.muestraPedidosEstandar();
            break;
        case 'J':
            gestor.muestraPedidosUrgentes();
            break;
        case 'K':
            gestor.buscarPedidos();
            break;
        case 'L':
            gestor.reiniciar();
            break;
        case 'M':
            gestor.crearArbol();
            break;
        case 'N':
            gestor.mostrarEstandarArbol();
            break;
        case 'O':
            gestor.mostrarUrgenteArbol();
            break;
        case 'P':
            gestor.inordenArbol();
            break;
        case 'Q':
            gestor.buscarPedidosArbol();
            break;
        case 'R':
            gestor.contarImpares();
            break;
        case 'T':
            gestor.mostrarHojas();
            break;
        case 'U':
            gestor.eliminarNodoHoja();
            break;
        case 'S':
            cout << "Saliendo del programa...\n";
            break;
        default:
            cout << "Opcion incorrecta!\n\n";
            break;
        }
    } while(opcion != 'S');

    return 0;
}
