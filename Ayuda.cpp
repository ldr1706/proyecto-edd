#include "Ayuda.h"
#include "Diccionario.h"
#include "Palabra.h"
#include <cctype>
#include <fstream>
#include <iostream>
#include <sstream>
#include <stack>
#include <string>
#include <vector>

using namespace std;

Ayuda::Ayuda() {}
std::vector<string> listaPalabras;
std::vector<std::string> palabrasInversas;

Palabra pal;

void Ayuda::ejecutar() {
  std::string entrada;
  while (true) {
    std::cout << "$ ";
    std::getline(std::cin, entrada);
    ejecutarComando(entrada);
  }
}

void Ayuda::registrarComando(const std::string &comando,
                             const std::string &descripcion) {
  comandos[comando] = descripcion;
}

void Ayuda::ejecutarComando(const std::string &entrada) {
  std::istringstream entry(entrada);
  std::string comando;
  Diccionario dicci;
  entry >> comando;
  if (comando == "ayuda") {
    mostrarAyuda();
  } else if (comando == "iniciar") {
    std::string archivo;
    entry >> archivo;
    if (!archivo.empty()) {
      listaPalabras = dicci.inicializar_diccionario(archivo);
    } else {
      std::cout << "Error: Uso incorrecto de 'iniciar'. Debe proporcionar "
                   "el nombre del archivo."
                << std::endl;
    }
  } else if (comando == "iniciar_inverso") {
    std::string archivo;
    entry >> archivo;
    if (!archivo.empty()) {
      palabrasInversas = dicci.iniciar_inverso(archivo);
    } else {
      std::cout << "Error: Uso incorrecto de 'iniciar_inverso'. Debe "
                   "proporcionar el nombre del archivo."
                << std::endl;
    }
  } else if (comando == "puntaje") {
    std::string palabra;
    int puntaje = 0;
    entry >> palabra;
    if (!palabra.empty()) {
      puntaje = pal.puntaje_palabra(palabra, listaPalabras);
      if(puntaje == 0){
        puntaje = pal.puntaje_palabra(palabra, palabrasInversas);
      }
      cout << "El puntaje de la palabra " << palabra << " es: " << puntaje << endl;
    } else {
      std::cout << "Error: Uso incorrecto de 'puntaje'. Debe proporcionar la "
                   "palabra para la cual calcular el puntaje."
                << std::endl;
    }
  } else if (comando == "salir") {
    salir();
  } else {
    std::cout << "Error: Comando desconocido. Escribe 'ayuda' para listar los "
                 "comandos disponibles."
              << std::endl;
  }
}
void Ayuda::mostrarAyuda() const {
  std::cout << "Lista de comandos disponibles:\n" << std::endl;
  std::cout
      << "iniciar diccionario.txt: Inicializa el sistema a partir del "
         "archivo diccionario.txt, que contiene un diccionario de palabras "
         "aceptadas en el idioma inglés (idioma original del juego). El "
         "comando debe almacenar las palabras del archivo de forma que sea "
         "fácil recuperarlas posteriormente. Las palabras deben ser "
         "verificadas para no almacenar aquellas que incluyen símbolos "
         "inválidos (como guiones, números y signos de puntuación)\n"
      << std::endl;
  std::cout << "iniciar_inverso diccionario.txt: Inicializa el sistema a "
               "partir del archivo diccionario.txt, que contiene un "
               "diccionario de palabras aceptadas en el idioma inglés (idioma "
               "original del juego). A diferencia del comando inicializar, "
               "este comando almacena las palabras en sentido inverso (leídas "
               "de derecha a izquierda), teniendo en cuenta que sea fácil "
               "recuperarlas posteriormente. Las palabras también deben ser "
               "verificadas para no almacenar aquellas que incluyen símbolos "
               "inválidos (como guiones, números y signos de puntuación)\n"
            << std::endl;
  std::cout << "puntaje: El comando permite conocer la puntuación que puede "
               "obtenerse con una palabra dada, de acuerdo a la tabla de "
               "puntuación de cada letra presentada anteriormente. Sin "
               "embargo, el comando debe verificar que la palabra sea válida, "
               "es decir, que exista en el diccionario (tanto original como en "
               "sentido inverso), y que esté escrita con símbolos válidos\n"
            << std::endl;
  std::cout << "salir: salir del sistema\n" << std::endl;
}
void Ayuda::salir() {
  std::cout << "Saliendo..." << std::endl;
  exit(0);
}
