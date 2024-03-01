#ifndef DICCIONARIO_H
#define DICCIONARIO_H

#include <string>
#include <vector>
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <stack>
#include <cctype>
class Diccionario {
public:
    Diccionario();
std::vector<std::string> inicializar_diccionario(const std::string& archivo);
std::vector<std::stack<char>> iniciar_inverso(const std::string& archivo);
    
};
#endif
