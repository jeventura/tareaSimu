#include <iostream>
using namespace std;

class Nodo
{
public:
    int Valor;
    Nodo *Siguiente;
    Nodo *Anterior;
};

void imprimirLista(Nodo *n)
{
    while (n != nullptr)
    {
        cout << n->Valor << endl;
        n = n->Siguiente;
    }
}

void insertarAlFrente(Nodo **head, int nuevoValor){
    // pasos para insertar nuevo valor al frente de la lista
    //  1- Preparar un nuevo nodo
    Nodo *nuevoNodo = new Nodo();
    nuevoNodo->Valor = nuevoValor;
    // 2- Ponerlo al frente de la lista
    nuevoNodo->Siguiente = *head;
    nuevoNodo->Anterior = nullptr; // Como el nuevo nodo será el primero, su anterior es nulo

    // 3- Verificamos que La lista no esta vacia ajustamos el nodo anterior al acutal
    if (*head != nullptr)
        (*head)->Anterior = nuevoNodo;

    // 3- Mover la cabeza de la lista al nuevo nodo
    *head = nuevoNodo;
}

void insertarAlFinal(Nodo **head, int nuevoValor)
{
    // 1-preparar un nuevo nodo
    Nodo *nuevoNodo = new Nodo();
    nuevoNodo->Valor = nuevoValor;
    nuevoNodo->Siguiente = nullptr;
    // 2-si la lista esta vacia, el nuevo nodo sera la cabeza de la lista
    if (*head == nullptr)
    {
        nuevoNodo->Anterior = nullptr; // si es encenrtra vacia el nuevo nodo no tiene , un nodo anterior
        *head = nuevoNodo;
        return;
    }
    // 3- encontrar el último nodo
    Nodo *ultimo = *head;
    while (ultimo->Siguiente != nullptr)
    {
        ultimo = ultimo->Siguiente;
    }
    // 4. es aqui donde realmente enlazamos las listas, y procedemos a enlazar los nosdos nuevos y anteriores
    ultimo->Siguiente = nuevoNodo;
    nuevoNodo->Anterior = ultimo;
}

void insertarEnPosicion(Nodo *anterior, int nuevoValor)
{
    // 1- verificar si el nodo anterior es NULL
    if (anterior == nullptr)
    {
        cout << "El nodo anterior no puede ser NULL" << endl;
        return;
    }
    // 2- preparar el nuevo nodo
    Nodo *nuevoNodo = new Nodo();
    nuevoNodo->Valor = nuevoValor;
    nuevoNodo->Siguiente = anterior->Siguiente; // Establece el siguiente del nuevo nodo como el siguiente del nodo anterior
    nuevoNodo->Anterior = anterior;             // Establece el anterior del nuevo nodo como el nodo anterior proporcionado
    // 3- si el nodo anterior tiene un siguiente nodo, ajustar el puntero anterior del siguiente nodo
    if (anterior->Siguiente != nullptr)
    {
        anterior->Siguiente->Anterior = nuevoNodo; // El nodo siguiente al nodo anterior ahora tendrá como anterior al nuevo nodo
    }
    // 4- digamos entonces que enlazamos el nuevo nodo después del nodo anterior
    anterior->Siguiente = nuevoNodo;
}

void eliminarAlFrente(Nodo **head) {
    // Verificar si la lista está vacía
    if (*head == nullptr) {
        cout << "La lista está vacía. No hay nada que eliminar." << endl;
        return;
    }
    
    // Guardar una referencia al nodo que será eliminado (el head actual)
    Nodo *nodoAEliminar = *head;
    
    // Mover la cabeza al siguiente nodo en la lista
    *head = (*head)->Siguiente;
    
    // Verificar si hay un nuevo head y ajustar su puntero anterior
    if (*head != nullptr) {
        (*head)->Anterior = nullptr;
    }
    
    // Liberar la memoria del nodo eliminado
    delete nodoAEliminar;
}
void eliminarAlFinal(Nodo **head) {
    // Verificar si la lista está vacía
    if (*head == nullptr) {
        cout << "La lista está vacía. No hay nada que eliminar." << endl;
        return;
    }
    
    // Si la lista tiene solo un nodo, eliminamos ese nodo
    if ((*head)->Siguiente == nullptr) {
        delete *head;
        *head = nullptr;
        return;
    }
    
    // Encontrar el último nodo
    Nodo *ultimo = *head;
    while (ultimo->Siguiente != nullptr) {
        ultimo = ultimo->Siguiente;
    }
    
    // Guardar una referencia al nodo que será eliminado (el último nodo)
    Nodo *nodoAEliminar = ultimo;
    
    // Actualizar el nodo anterior al último
    ultimo->Anterior->Siguiente = nullptr;
    
    // Liberar la memoria del nodo eliminado
    delete nodoAEliminar;
}

int main()
{
    Nodo *head = nullptr;

    insertarAlFrente(&head, 3);
    insertarAlFrente(&head, 2);
    insertarAlFrente(&head, 1);

    insertarAlFinal(&head, 4);
/*
    Nodo *nodoActual = head;
    while (nodoActual != nullptr && nodoActual->Valor != 3)
    {
        nodoActual = nodoActual->Siguiente;
    }
    if (nodoActual != nullptr)
    {
        insertarEnPosicion(nodoActual, 7);
    }

    cout << "Lista hacia adelante:" << endl;
    */
    //imprimirLista(head);
    /*
    cout << "Lista hacia atras:" << endl;
    Nodo *ultimo = head;

    // verifica recoririendo de la lista avanzando hacia el último nodo
    while (ultimo->Siguiente != nullptr)
    {
        ultimo = ultimo->Siguiente;
    }
    // verifica recoririendo hacia atrás a través de la lista, imprimiendo los valores de los nodos en orden inverso
    while (ultimo != nullptr)
    {
        cout << ultimo->Valor << endl;
        ultimo = ultimo->Anterior;
    }

    return 0;
    */
imprimirLista(head);


}
