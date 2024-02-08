#include "Scrabble.h"
Scrabble::Scrabble() {
    registrarComando(
        "ayuda",
        [this](const std::vector<std::string>& args) {
            if (args.empty()) {
                mostrarAyuda();
            } else {
                ayuda_comando(args[0]);
            }
        },
        "Lista los comandos disponibles o muestra ayuda sobre un comando específico. Uso: ayuda <comando>"
    );
    registrarComando(
        "inicializar_diccionario",
        [this](const std::vector<std::string>& args) {
            inicializar_diccionario(args);
        },
        "Inicializa el diccionario para el juego Scrabble."
    );
    registrarComando(
        "iniciar_inverso",
        [this](const std::vector<std::string>& args) {
            iniciar_inverso(args);
        },
        "Inicializa el diccionario inverso para el juego Scrabble."
    );
    registrarComando(
        "puntaje_palabra",
        [this](const std::vector<std::string>& args ) {
            puntaje_palabra(args);
        },
        "Calcula el puntaje de una palabra en el juego Scrabble."
    );

    registrarComando(
        "salir",
        [this](const std::vector<std::string>& args) {
            salir();
        },
        "Salir de la aplicación."
    );
}

void Scrabble::ejecutar() {
    std::string entrada;
    while (true) {
        std::cout << "$ ";
        std::getline(std::cin, entrada);
        ejecutarComando(entrada);
    }
}
void Scrabble::registrarComando(const std::string& comando, std::function<void(const std::vector<std::string>&)> func, const std::string& textoAyuda) {
    comandos[comando] = {func, textoAyuda};
}
void Scrabble::ejecutarComando(const std::string& entrada) {
    std::istringstream entry(entrada);
    std::string comando;
    entry >> comando;
    std::vector<std::string> args;
    std::string arg;
    while (entry >> arg) {
        args.push_back(arg);
    }
    auto iterator = comandos.find(comando);
    if (iterator != comandos.end()) {
          iterator->second.first(args);
    } else {
        std::cout << "Error: Comando desconocido. Escribe 'ayuda' para listar los comandos disponibles." << std::endl;
    }
}

void Scrabble::mostrarAyuda() const {
    std::cout << "Lista de comandos disponibles:" << std::endl;
    std::cout <<"\n";
    for (const auto& par : comandos) {
        std::cout << par.first << ":  " << par.second.second << std::endl;
      std::cout <<"\n";
    }
}
void Scrabble::mostrarAyudaComando(const std::string& comando) const {
    auto iterator = comandos.find(comando);
    if (iterator != comandos.end()) {
        std::cout << "Descripción de '" << comando << "':" << std::endl;
        std::cout << iterator->second.second << std::endl;
    } else {
        std::cout << "Error: Comando desconocido." << std::endl;
    }
}

void Scrabble::ayuda_comando(const std::string& comando) {
    mostrarAyudaComando(comando);
}

void Scrabble::inicializar_diccionario(const std::vector<std::string>&args) {
    std::cout << "Inicializando el diccionario..." << std::endl;
}
void Scrabble::iniciar_inverso(const std::vector<std::string>& args) {
    std::cout << "Inicializando el diccionario inverso..." << std::endl;
}
void Scrabble::puntaje_palabra(const std::vector<std::string>& args ) {
    std::cout << "Calculando puntaje de palabra..." << std::endl;
}
void Scrabble::salir() {
    std::cout << "Saliendo..." << std::endl;
    exit(0);
}
//MAIN
int main() {
    Scrabble juego;
    std::cout << "Escribe 'ayuda' para listar los comandos disponibles." << std::endl;
    juego.ejecutar();
    return 0;
}
