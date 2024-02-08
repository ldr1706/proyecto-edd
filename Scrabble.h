#ifndef SCRABBLE_H
#define SCRABBLE_H

#include <iostream>
#include <sstream>
#include <vector>
#include <functional>
#include <map>
#include <string>

class Scrabble {
public:
    Scrabble();
    void ejecutar(); 
private:
    //comandos
    void ayuda();
    void ayuda_comando(const std::string& comando);
    void inicializar_diccionario(const std::vector<std::string>& args);
    void iniciar_inverso(const std::vector<std::string>& args);
    void puntaje_palabra(const std::vector<std::string>& args);
    void salir();
    //las otras funciones
    void registrarComando(
        const std::string& comando,
        std::function<void(const std::vector<std::string>&)> func,
        const std::string& textoAyuda);
    void ejecutarComando(const std::string& entrada);
    void mostrarAyuda() const;
    void mostrarAyudaComando(const std::string& comando) const;
    //almacenamiento comandos
    std::map<std::string, std::pair<std::function<void(const std::vector<std::string>&)>, std::string>> comandos;
};

#endif

