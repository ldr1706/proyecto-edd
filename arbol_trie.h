#ifndef ARBOL_TRIE_H_
#define ARBOL_TRIE_H_

#include <iostream>
#include <string>
#include <vector>
#include "nodo.h"

using namespace std;


class Arbol{
  protected:
    Nodo* raiz;
  public:
    Arbol();
    Arbol(char valor);
    void insertarPalabra(string palabra);
    Nodo* insertarNodo(Nodo* padre, char valor, bool finalPalabra);
    bool buscarPalabra(string palabra);
    Nodo* buscarPrefijo(string prefijo);
    void imprimirPalabrasPorPrefijo(string prefijo, vector<string> &vec);
    void imprimirPalabrasRecursiva(Nodo* nodo, string prefijo, vector<string> &palabras);
};

#include "arbol_trie.cxx"
#endif