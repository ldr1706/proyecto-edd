#ifndef DICCIONARIO_H
#define DICCIONARIO_H

#include <cctype>
#include <fstream>
#include <iostream>
#include <sstream>
#include <stack>
#include <string>
#include <vector>
class Diccionario {
public:
  Diccionario();
  std::vector<std::string> inicializar_diccionario(const std::string &archivo);
  std::vector<std::string> iniciar_inverso(const std::string &archivo);
};

#include "Diccionario.cpp"
#endif
