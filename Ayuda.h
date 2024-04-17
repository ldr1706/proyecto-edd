#ifndef AYUDA_H
#define AYUDA_H

#include "arbol_trie.h"
#include <cctype>
#include <fstream>
#include <iostream>
#include <map>
#include <sstream>
#include <stack>
#include <string>
#include <vector>

class Ayuda {
public:
  Ayuda();

  void ejecutar();
  void registrarComando(const std::string &comando, const std::string &descripcion);
  void ejecutarComando(const std::string &entrada);
  void mostrarAyuda() const;
  void salir();
  bool leerArchivo(std::string nombreArchivo, Arbol* arbol);
  bool leerArchivoInverso(std::string nombreArchivo, Arbol* arbol);

private:
  std::map<std::string, std::string> comandos;
};

#include "Ayuda.cpp"
#endif
