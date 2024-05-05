#include <iostream>
using namespace std;

class Nodo{
public:
    int Valor;
    Nodo* Siguiente;

};

void imprimirLista(Nodo* n){
    while(n!=NULL){
        cout<<n->Valor<<endl;
        n=n->Siguiente;
    }
}

void insertarAlFrente(Nodo**head, int nuevoValor){
    //pasos para insertar nuevo valor al frente de la lista
    //1- Preparar un nuevo nodo
    Nodo * nuevoNodo = new Nodo();
    nuevoNodo->Valor = nuevoValor;
    //2- Ponerlo al frente de la lista
    nuevoNodo->Siguiente = *head;
    //3- Mover la cabeza de la lista al nuevo nodo
    *head = nuevoNodo;
}
void insertarAlFinal(Nodo **head, int nuevoValor){
    //1-preparar un nuevo nodo
    Nodo * nuevoNodo = new Nodo();
    nuevoNodo->Valor = nuevoValor; 
    nuevoNodo->Siguiente = NULL;
    //2-si la lista esta vacia, el nuevo nodo sera la cabeza de la lista
    if(*head==NULL){
        *head = nuevoNodo;
        return;
    }
    //3-Encontrar el ultimo nodo de la lista 
    Nodo * ultimo = *head;
    while(ultimo->Siguiente != NULL){
        ultimo = ultimo->Siguiente;
    }
    //insertar el nuevo nodo despues del ultimo (al final)
    ultimo->Siguiente = nuevoNodo;
}
void insertarEnPosicion (Nodo*anterior,int nuevoValor){
    //1-verificar si el nodo anterior es NULL
    if(anterior==NULL){
        cout<<"nodo anterior no puede ser NULL"<<endl;
        return;
    }
    //2-preparar el nuevo nodo 
    Nodo* nuevoNodo = new Nodo();
    nuevoNodo->Valor = nuevoValor;
    //3-insertar el nuevo nodo despues del anterior
    nuevoNodo->Siguiente = anterior->Siguiente;
    anterior->Siguiente = nuevoNodo;

}

int main(){
    Nodo* head = new Nodo();
    Nodo* segundo = new Nodo();
    Nodo* tercero = new Nodo();

    head->Valor = 1;
    head->Siguiente = segundo;
    segundo->Valor = 2;
    segundo->Siguiente = tercero;
    tercero->Valor = 3;
    tercero->Siguiente = NULL;

    insertarAlFrente(&head, -1);
    //insertarAlFinal(&head, 4);
    insertarEnPosicion(segundo, 7);
    imprimirLista(head);
}