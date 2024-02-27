#include "Scrabble.h"
using namespace std;
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
        "inicializar diccionario.txt",
        [this](const std::vector<std::string>& args) {
            inicializar_diccionario(args);
        },
        "Inicializa el sistema a partir del archivo diccionario.txt, que contiene un diccionario de palabras aceptadas en el idioma inglés (idioma original del juego). El comando debe almacenar las palabras del archivo de forma que sea fácil recuperarlas posteriormente. Las palabras deben ser verificadas para no almacenar aquellas que incluyen símbolos inválidos (como guiones, números y signos de puntuación)"
    );
    registrarComando(
        "iniciar inverso diccionario.txt",
        [this](const std::vector<std::string>& args) {
            iniciar_inverso(args);
        },
        "Inicializa el sistema a partir del archivo diccionario.txt, que contiene un diccionario de palabras aceptadas en el idioma inglés (idioma original del juego). A diferencia del comando inicializar, este comando almacena las palabras en sentido inverso (leídas de derecha a izquierda), teniendo en cuenta que sea fácil recuperarlas posteriormente. Las palabras también deben ser verificadas para no almacenar aquellas que incluyen símbolos inválidos (como guiones, números y signos de puntuación)"
    );
    registrarComando(
        "puntaje palabra",
        [this](const std::vector<std::string>& args ) {
            puntaje_palabra(args);
        },
        "El comando permite conocer la puntuación que puede obtenerse con una palabra dada, de acuerdo a la tabla de puntuación de cada letra presentada anteriormente. Sin embargo, el comando debe verificar que la palabra sea válida, es decir, que exista en el diccionario (tanto original como en sentido inverso), y que esté escrita con símbolos válidos"
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
