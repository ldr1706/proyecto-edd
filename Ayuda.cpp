#include "Ayuda.h"
#include "Diccionario.h"
#include "Palabra.h"
#include "arbol_trie.h"
#include "utilidades.h"
#include <cctype>
#include <cstddef>
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
Arbol *arbol = new Arbol();
Arbol *arbolInverso = new Arbol();
bool arbolInicializado = false;
bool arbolInversoInicializado = false;

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
      if (puntaje == 0) {
        puntaje = pal.puntaje_palabra(palabra, palabrasInversas);
      }
      cout << "El puntaje de la palabra " << palabra << " es: " << puntaje
           << endl;
    } else {
      std::cout << "Error: Uso incorrecto de 'puntaje'. Debe proporcionar la "
                   "palabra para la cual calcular el puntaje."
                << std::endl;
    }
  } else if (comando == "iniciar_arbol") {
    std::string archivo;
    entry >> archivo;
    if(arbolInicializado == false){
      arbolInicializado = leerArchivo(archivo, arbol);
    }
    else{
      cout << "El árbol del diccionario ya ha sido inicializado." << endl;
    }
  }else if(comando == "iniciar_arbol_inverso"){
    std::string archivo;
    entry >> archivo;
    if(arbolInversoInicializado == false){
      arbolInversoInicializado = leerArchivo(archivo, arbolInverso);
    }
    else{
      cout << "El árbol inverso del diccionario ya ha sido inicializado." << endl;
    }
  }else if (comando == "salir") {
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
  std::cout << "iniciar_arbol diccionario.txt: Inicializa el sistema a partir "
               "Inicializa el sistema a partir del archivo diccionario.txt, que contiene"                "un diccionario de palabras aceptadas en el idioma inglés" 
               "(idioma original del juego). A diferencia del comando inicializar,"
               "este comando almacena las palabras en uno o más árboles de letras" 
               "(como se considere conveniente). Las palabras deben ser verificadas" 
               "para no almacenar aquellas que incluyen símbolos inválidos" 
               "(como guiones,números y signos de puntuación)."
            << std::endl;
  std::cout << "iniciar_arbol_inverso diccionario.txt: Inicializa el sistema a"
               " partir del archivo diccionario.txt, que contiene un diccionario"
               "de palabras aceptadas en el idioma inglés (idioma original del juego)." 
               "A diferencia de los comandos iniciar_inverso e iniciar_arbol, este" 
               "comando almacena las palabras en uno o más árboles de letras,"
               "pero en sentido inverso (leídas de derecha a izquierda). Las palabras" 
               "también deben ser verificadas para no almacenar aquellas que incluyen"
               "símbolos inválidos (como guiones, números y signos de puntuación)."
            << std::endl;
  std::cout << "palabras_por_prefijo prefijo: Dado un prefijo de pocas letras," 
               "el comando recorre el(los) árbol(es) de letras (construído(s)"
               "con el comando iniciar_arbol) para ubicar todas las palabras posibles a" 
               "construir a partir de ese prefijo. A partir del recorrido,"  
               "se presenta al usuario en pantalla todas las posibles palabras," 
               "la longitud de cada una y la puntuación que cada una puede obtener"
            << std::endl;
  std::cout << "palabras_por_sufijo sufijo: Dado un sufijo de pocas letras,"
               "el comando recorre el(los) árbol(es) de letras (construído(s)"
               "con el comando iniciar_arbol_inverso) para ubicar todas las palabras" 
               "posibles a construir que terminan con ese sufijo. A partir del" 
               "recorrido, se presenta al usuario en pantalla todas las posibles" 
               "palabras, la longitud de cada una y la puntuación que cada" 
               "una puede obtener."
            << std::endl;
  std::cout << "salir: salir del sistema\n" << std::endl;
}

void Ayuda::salir() {
  std::cout << "Saliendo..." << std::endl;
  exit(0);
}

bool Ayuda::leerArchivo(string nombreArchivo, Arbol *arbol) {
  int cantidadLineas = 0;
  ifstream archivo(nombreArchivo);
  if (!archivo.is_open()) {
    cout << "El archivo diccionario.txt no existe o no puede ser leído." << endl;
    return false;
  }
  string linea;
  if (!archivo.eof()) {
    while (getline(archivo, linea)) {
      cantidadLineas++;
      //cout << "Palabra:" << linea << endl;
      arbol->insertarPalabra(linea);
    }
  }
  cout << "Arbol inicializado con: " << cantidadLineas << " palabras" << endl;
  return true;
}

bool Ayuda::leerArchivoInverso(string nombreArchivo, Arbol *arbol){
  int cantidadLineas = 0;
  ifstream archivo(nombreArchivo);
  if(!archivo.is_open()){
    cout << "El archivo diccionario.txt no existe o no puede ser leído." << endl;
    return false;
  }
  string linea;
  if (!archivo.eof()) {
    while (getline(archivo, linea)) {
      cantidadLineas++;
      std::stack<char> pila;
      for(char letra: linea){
        if(isalpha(letra)){
          pila.push(letra);
        }
      }
    std::string palabraInversa = stackToString(pila);
      arbol->insertarPalabra(palabraInversa);
    }
  }
  cout << "Arbol Inverso inicializado con: " << cantidadLineas << " palabras" << endl;
  return true;
}
