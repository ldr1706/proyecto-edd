#include "Ayuda.h"
#include "Diccionario.h"
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <stack>
#include <cctype>
int main() {
    Ayuda ayuda;
    std::cout << "Escribe 'ayuda' para listar los comandos disponibles." << std::endl;
    ayuda.ejecutar();
    return 0;
}
