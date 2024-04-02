#include "arbol_trie.h"
#include "nodo.h"
#include <cstddef>

using namespace std;


Arbol::Arbol(){
  this->raiz = new Nodo();
}


Arbol::Arbol(char valor){
  this->raiz = new Nodo(valor, false);
}


void Arbol::insertarPalabra(string palabra){
  Nodo* auxiliar = this->raiz;
  bool bandera = false;
  for(int i = 0; i < palabra.length(); i++){
    if(i == palabra.length() - 1){
      bandera = true;
    }
    char letra = palabra[i];
    auxiliar = insertarNodo(auxiliar, letra, bandera);
  }  
}


Nodo* Arbol::insertarNodo(Nodo* padre, char valor,bool finalPalabra){
  Nodo* nodoAbuscar = padre->buscar(valor);
  int posicionAinsertar = valor - 97; //97 es el valor de 'a' en ascii
  if(nodoAbuscar == nullptr){
    Nodo* nuevoNodo = new Nodo(valor, finalPalabra);
    padre->crearNodoHijo(posicionAinsertar, nuevoNodo);
    return nuevoNodo;
  }
  else{
    return nodoAbuscar;
  }
}

bool Arbol::buscarPalabra(string palabra){
  Nodo* aux = this->raiz;
  bool bandera = false;
  for(int i = 0; i < palabra.length(); i++){
    char letra = palabra[i];
    aux = aux->buscar(letra);
    if(aux == nullptr){
      return false;
    }
  }
  return aux->esFinalPalabra() && aux != nullptr;
  /*if(aux->esFinalPalabra() == true){
    return true;
  }
  else{
    return false;
  }*/
}

Nodo* Arbol::buscarPrefijo(string prefijo){
  Nodo* aux = this->raiz;
  for(int i = 0; i < prefijo.length(); i++){
    char letra = prefijo[i];
    aux = aux->buscar(letra);
    if(aux == nullptr){
      return nullptr;
    }
  }
  return aux;
}

void Arbol::imprimirPalabrasPorPrefijo(string prefijo){
  Nodo* aux = this->buscarPrefijo(prefijo);
  if(aux == nullptr){
    cout << "No hay palabras con ese prefijo en el arbol" << endl;
    return;
  }
  cout << "Prefijo encontrado" << endl;
  imprimirPalabrasRecursiva(aux, prefijo);
}

void Arbol::imprimirPalabrasRecursiva(Nodo* nodo, string prefijo){
  if(nodo == nullptr){
    return;
  }
  if(nodo->esFinalPalabra() == true){
    cout << "\n" << prefijo;
  }
  for(int i = 0; i < 26; i++){
    if(nodo->obtenerHijo(i) != nullptr){
      char letra = i + 97;
      imprimirPalabrasRecursiva(nodo->obtenerHijo(i), prefijo + string(1,letra));
    }
  }
}


