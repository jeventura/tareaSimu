#include <iostream>
#include <cstdlib>

using namespace std;

// Definición de la estructura de nodo
struct Node {
    int data;
    Node* next;
    Node* prev;
};

// Función para crear un nuevo nodo
Node* createNode(int data) {
    Node* newNode = new Node();
    newNode->data = data;
    newNode->next = nullptr;
    newNode->prev = nullptr;
    return newNode;
}

// Clase para la lista circular doblemente enlazada
class CircularDoublyLinkedList {
private:
    Node* head;
    Node* tail;
    int size;

public:
    // Constructor
    CircularDoublyLinkedList() : head(nullptr), tail(nullptr), size(0) {}

    // Destructor
    ~CircularDoublyLinkedList() {
        while (size > 0)
            removeNode(head);
    }

    // Función para agregar un nodo al final de la lista
    void addNode(int data) {
        Node* newNode = createNode(data);
        if (head == nullptr) {
            head = newNode;
            tail = newNode;
            head->next = tail;
            tail->prev = head;
        } else {
            tail->next = newNode;
            newNode->prev = tail;
            newNode->next = head;
            head->prev = newNode;
            tail = newNode;
        }
        size++;
    }
    
    // Función para crear la lista
    void createList(int k) {
        for (int i = 1; i <= k; ++i) {
            addNode(i);
        }
    }
   
    // Función para eliminar un nodo de la lista
    void removeNode(Node* node) {
        if (size == 0)
            return;
        if (size == 1) {
            delete node;
            head = nullptr;
            tail = nullptr;
        } else {
            node->prev->next = node->next;
            node->next->prev = node->prev;
            if (node == head)
                head = node->next;
            else if (node == tail)
                tail = node->prev;
            delete node;
        }
        size--;
    }

    // Función para mostrar la lista
    void display() {
        if (size == 0)
            cout << "Lista vacia" << endl;
        else {
            Node* current = head;
            do {
                cout << current->data << " ";
                current = current->next;
            } while (current != head);
            cout << endl;
        }
    }

    // Algoritmo de Josephus
    void josephus(int k) {
        if (size == 0) {
            cout << "No hay nodos en la lista." << endl;
            return;
        }
        Node* current = head;
        display();
        for(int i = 0; i < size ; i++){
            if(i < size - 1){
                cout << "--" ;
            }else{
                cout << "-" << endl;
            }
            
        }
        
        while (size > 1) {
            for (int i = 0; i < k - 1; ++i) {
                current = current->next;
            }
            Node* nextNode = current->next;
            removeNode(current);
            current = nextNode;
            display();
        }
    }
    
    // Función para eliminar la lista y liberar memoria
    void clear() {
        while (size > 0) {
            removeNode(head);
        }
    }

    // Algoritmo de Josephus parcial
    void josephusPartial(int k, int j) {
        int initialSize = size;
        if (size == 0) {
            cout << "No hay nodos en la lista." << endl;
            return;
        }
        if(j > initialSize - 1) {
            cout << "No es posible tener mas ejecuciones que el tamano de la lista - 1." << endl;
            return;
        }
        Node* current = head;
        display();
        for(int i = 0; i < size ; i++){
            if(i < size - 1){
                cout << "--" ;
            }else{
                cout << "-" << endl;
            }
            
        }
        while (size > (initialSize - j)) {
            for (int i = 0; i < k - 1; ++i) {
                current = current->next;
            }
            Node* nextNode = current->next;
            removeNode(current);
            current = nextNode;
            display();
        }
    }
};

void printMenu(){
    cout << "############ MENU ############\n";
    cout << "1- Lista nueva\n";
    cout << "2- Consultar lista\n";
    cout << "3- Ejecutar algoritmo de manera completa sobre lista\n";
    cout << "4- Ejecutar algoritmo de manera parcial sobre lista\n";
    cout << "5- Eliminar lista\n";
    cout << "6- Salir\n";
    cout << "Su opcion: ";
}

int main() {

    CircularDoublyLinkedList list;

    int n, k, j, opcion;

    do{
        cout << endl;
        printMenu();
        cin >> opcion;
        switch(opcion){
            case 1:
                cout << "Ingrese el tamano de la lista: ";
                cin >> n;
                list.createList(n);
                cout << "Lista llenada exitosamente" << endl;
                break;
            case 2:
                list.display();
                break;
            case 3:
                cout << "Ingrese la cantidad de pasos para el algoritmo de Josephus: ";
                cin >> k;
                list.josephus(k);
                break;
            case 4:
                cout << "Ingrese la cantidad de pasos para el algoritmo de Josephus parcial: ";
                cin >> k;
                cout << "Ingrese cuantos ejecuciones se mostraran: ";
                cin >> j;
                list.josephusPartial(k, j);
                break;
            case 5:
                list.clear();
                cout << "Lista eliminada exitosamente." << endl ;
                break;
            default:
                cout << "Valor ingresado no valido" << endl ;
                break;
        }
        k = 0, j = 0;
    }while(opcion != 6);

    return 0;
}