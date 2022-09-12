#include <iostream>
#include <stdlib.h>
#include <vector>

using namespace std;

struct estructuraNodo
{
    int valor;
    struct estructuraNodo *izq;
    struct estructuraNodo *der;
};

typedef struct estructuraNodo *nodo;

void insertar(int valorInsertar, nodo &raiz)
{
    if (raiz == NULL)
    {
        nodo nuevo = new (struct estructuraNodo);
        nuevo->valor = valorInsertar;
        nuevo->izq = NULL;
        nuevo->der = NULL;
        raiz = nuevo;
    }
    else
    {
        if (valorInsertar < raiz->valor)
        {
            insertar(valorInsertar, raiz->izq);
        }
        else if (valorInsertar > raiz->valor)
        {
            insertar(valorInsertar, raiz->der);
        }
        else
        {
            //  Numero repetidos terminan acá
        }
    }
}

void preOrden(nodo raiz)
{
    if (raiz != NULL)
    {
        cout << raiz->valor << ", ";
        preOrden(raiz->izq);
        preOrden(raiz->der);
    }
}

void inOrden(nodo raiz)
{
    if (raiz != NULL)
    {
        inOrden(raiz->izq);
        cout << raiz->valor << ", ";
        inOrden(raiz->der);
    }
}

void postOrden(nodo raiz)
{
    if (raiz != NULL)
    {
        postOrden(raiz->izq);
        cout << raiz->valor << ",  ";
        postOrden(raiz->der);
    }
}

bool buscar(int valorBuscar, nodo raiz){
    if(raiz != NULL){
        if(valorBuscar == raiz->valor){
            return true;
        } else if(valorBuscar > raiz->valor){
            return buscar(valorBuscar, raiz -> der);
        } else if(valorBuscar < raiz->valor){
            return buscar(valorBuscar, raiz->izq);
        } else {
            return false;
        }
    };
    return false;
}

int heightRaiz(nodo &raiz){
    // si eel árbol está vacío
    if (raiz == NULL) {
        return 0;
    }

    // recorre para el sub árbol de izquierda a derecha y toma la altura máxima
    return 1 + max (heightRaiz (raiz-> izq), heightRaiz (raiz-> der));
}

int heightTree(nodo &raiz){
    // si el árbol está vacío
    if (raiz == NULL) {
    cout << "El árbol está vacio"<< endl;
    } else{
    cout << "La altura del árbol es: " << heightRaiz(raiz);
    }
}

int countNodes(nodo &raiz){
    if(raiz == NULL){
        return 0;
    }
    
    if (raiz->izq == NULL and raiz->der== NULL){
        return 1;
    } else{
        int x = 0;
        int y = 0;
        if(raiz->izq != NULL){
            x = countNodes(raiz->izq);
        }
        if(raiz->der != NULL){
            y = countNodes(raiz->der);
        }
        return 1 + x + y;
    }
}


int countNodesLeft(nodo &raiz){
    if(raiz == NULL){
        return 0;
    }
    
    if (raiz->izq == NULL){
        return 1;
    } else{
        int x = 0;
        if(raiz->izq != NULL){
            x = countNodes(raiz->izq);
        }
        return 1 + x;
    }
}

int countNodesRigth(nodo &raiz){
    if(raiz == NULL){
        return 0;
    }
    
    if (raiz->der == NULL){
        return 1;
    } else{
        int y = 0;
        if(raiz->der != NULL){
            y = countNodes(raiz->der);
        }
        return 1 + y;
    }
}


int pesoArbol(int x, int y){
    if(x == y){
        return x;
    } else if(x < y){
        return y;
    } else {
        return x;
    }
}


int main()
{
    int numeroBuscar;
    nodo arbol = NULL;

    // int numeros[] = { 13, 3, 20, 7, 8, 9, 10, 11};
    vector<int> numeros = {35, 15, 80, 10, 20, 18, 17, 50, 100, 70, 40};
    //   vector<int> numeros = { 13, 3, 20, 7, 8, 9, 10, 11};
    // int tamañoArray = numeros.size();

    for(int i = 0; i< numeros.size(); i++){
        insertar(numeros[i], arbol);
    };

    cout << "En preOrden" << endl;
    preOrden(arbol);
    cout << endl << "-----------" << endl;
    cout << "En inOrden" << endl;
    inOrden(arbol);
    cout << endl << "-----------" << endl;
    cout << "En postOrden" << endl;
    postOrden(arbol);
    cout << endl << "-----------" << endl;


    cout << "Ya viste los numeros del arbol, busca uno de ellos" << endl;
    cin >> numeroBuscar;
    cout << "Buscando numero" << endl;
    cout << (buscar(numeroBuscar, arbol) ? "El valor ha sido encontrado" : "No se ha podido encontrar el valor"); 
    cout << endl << "-----------" << endl;



    cout << endl;
    heightTree(arbol);
    cout << endl;
    cout << "El total de nodos del arbol binario a la izquierda es: "<< countNodesLeft(arbol);
    cout << endl;
    cout << "El total de nodos del arbol binario a la derecha es: "<< countNodesRigth(arbol);
    cout << endl;

    // Peso del arbol

    int ramaIzquierda = countNodesLeft(arbol);
    int ramaDerecha = countNodesRigth(arbol);

    pesoArbol(ramaIzquierda, ramaDerecha);

    return 0;
}
