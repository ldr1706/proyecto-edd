#include "nodo.h"

using namespace std;


Nodo::Nodo(){
  this->dato = '\0';
  this->finalPalabra = false;
  for(int i = 0; i < 26; i++){
    this->hijos[i] = nullptr;
  }
}


Nodo::Nodo(char valor, bool esFinal){
  this->dato = valor;
  this->finalPalabra = esFinal;
  for(int i = 0; i < 26; i++){
    this->hijos[i] = nullptr;
  }
}

void Nodo::crearNodoHijo(int posicion, Nodo* nodo){
  this->hijos[posicion] = nodo;
}

char Nodo::obtenerDato(){
  return this->dato;
}


bool Nodo::esFinalPalabra(){
  return this->finalPalabra;
}


void Nodo::fijarDato(char valor, bool esFinal){
  this->dato = valor;
  this->finalPalabra = esFinal;
}


Nodo* Nodo::buscar(char val){
  int posicionArreglo = val - 97;
  if(this->hijos[posicionArreglo] != nullptr){
    return hijos[posicionArreglo];
  }
  else{
    return nullptr;
  }
}

Nodo* Nodo::obtenerHijo(int posicion){
  return this->hijos[posicion];
}

