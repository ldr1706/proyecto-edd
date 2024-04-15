#ifndef __NODO__H__
#define __NODO__H__
#include <string>


using namespace std;

class Nodo {
protected:
  char dato;
  Nodo* hijos[26];
  bool finalPalabra;

public:
  Nodo();
  Nodo(char valor, bool esFinal);
  void crearNodoHijo(int posicion, Nodo* hijo);
  char obtenerDato();
  bool esFinalPalabra();
  void fijarDato(char valor, bool esFinal);
  Nodo* buscar(char val);
  Nodo* obtenerHijo(int posicion);
};

#endif