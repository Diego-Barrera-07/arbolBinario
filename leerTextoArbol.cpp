#include <iostream>
#include <fstream>
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

void inOrdenLeft(nodo raiz){ //de mayor a menor
    if(raiz != NULL){
        inOrdenLeft(raiz->der);
        cout <<raiz-> valor << ", ";
        inOrdenLeft(raiz->izq);
    }
}


int main()
{
    ifstream f;
    int i = 0;
    string listaPalabras;

    f.open("texto.dat", ios::in);

    if (!f)
    {
        cout << "No existe el archivo o no se pudo abrir";
        exit(1);
    }

    while (!f.eof())
    {
        i++;
        getline(f, listaPalabras);
    }

    // Convertir string a vector
    vector<int> numbers(listaPalabras.begin(), listaPalabras.end());
 
    string space_delimiter = " ";
    vector<string> words{};

    size_t pos = 0;
    while ((pos = listaPalabras.find(space_delimiter)) != string::npos)
    {
        words.push_back(listaPalabras.substr(0, pos));
        listaPalabras.erase(0, pos + space_delimiter.length());
    }
    for (const auto &str : words)
    {
        cout << str << " ";
        inOrdenLeft(str);
    }


    


    return 0;
}