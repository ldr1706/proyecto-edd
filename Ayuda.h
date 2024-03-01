#ifndef AYUDA_H
#define AYUDA_H

#include <string>
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <stack>
#include <cctype>
#include <map> 
#include "Diccionario.h"

class Ayuda {
public:
    Ayuda();
   
    void ejecutar();
     void registrarComando(const std::string& comando, const std::string& descripcion);
void ejecutarComando(const std::string& entrada);
    void mostrarAyuda() const;
    void salir();

private:
    std::map<std::string, std::string> comandos;
};

#endif
