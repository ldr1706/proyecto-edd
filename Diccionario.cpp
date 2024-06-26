#include "Diccionario.h"
#include "utilidades.h"
#include <cctype>
#include <fstream>
#include <iostream>
#include <sstream>
#include <stack>
#include <string>
#include <vector>
using namespace std;


Diccionario::Diccionario() {}

std::vector<std::string>
Diccionario::inicializar_diccionario(const std::string &archivo) {
  std::vector<std::string> palabras;
  string linea;
  string palabra;
  std::ifstream arch(archivo);
  if (arch.is_open() && palabras.empty()) {
    while (std::getline(arch, linea)) {
      std::istringstream iss(linea);
      while (iss >> palabra) {
        palabras.push_back(palabra);
      }
    }
    cout << "Se inicializó correctamente el diccionario" << endl;
  } else if (arch.is_open() && !palabras.empty()) {
    cout << "El diccionario ya ha sido inicializado" << endl;
  }

  else if (!arch.is_open()) {
    cout << "No se puede inicializar el diccionario" << endl;
  }
  return palabras;
}

std::vector<std::string>
Diccionario::iniciar_inverso(const std::string &archivo) {
  std::vector<std::string> palabrasInverso;
  std::ifstream arch(archivo);
  if (!arch.is_open()) {
    std::cout << "El archivo diccionario.txt no existe o no puede ser leído."
              << std::endl;
    return palabrasInverso;
  } else {
    if (!palabrasInverso.empty()) {
      cout << "El diccionario inverso ya ha sido inicializado." << endl;
    } else {
      cout << "El diccionario inverso se ha inicializado correctamente" << endl;
      std::string palabra;
      while (arch >> palabra) {
        std::stack<char> pila;
        for (char letra : palabra) {
          if (std::isalpha(letra)) {
            pila.push(letra);
          }
        }
        std::string palabraInversa = stackToString(pila);
        palabrasInverso.push_back(palabraInversa);
      }
    }
    arch.close();
  }
  return palabrasInverso;
}
