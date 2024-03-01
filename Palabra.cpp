#include "Palabra.h"
#include "Diccionario.h"
#include "Ayuda.h"
using namespace std;
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>
#include <cctype> 
#include <list>
#include <algorithm>

Diccionario dicc;
  Palabra::Palabra() {}
  int Palabra::puntaje_palabra(string palabra, std::vector<std::string> palabras, std::vector<std::stack<char>> palabrasInverso) {
    bool b = true;
    int puntaje = 0;
    int score = 0;
    for (char c : palabra) {
        if (!std::isalpha(c)) {
            b = false;
        }
    }
    if(!b){
      std::cout << "La palabra contiene símbolos invalidos." << std::endl;
      return puntaje;
    }
     std::transform(palabra.begin(), palabra.end(), palabra.begin(), ::toupper);
    bool find = false;
    for (const std::string& palabri : palabras) {
        if (palabri == palabra) {
            find = true;
            break;
        }
    }
    if(find){
      for (char caracter : palabra) {
                switch (caracter) {
                    case 'A': case 'E': case 'I': case 'O': case 'N': case 'R': case 'T': case 'L': case 'S': case 'U':
                        score += 1;
                        break;
                    case 'D': case 'G':
                        score += 2;
                        break;
                    case 'B': case 'C': case 'M': case 'P':
                        score += 3;
                        break;
                    case 'F': case 'H': case 'V': case 'W': case 'Y':
                        score += 4;
                        break;
                    case 'K':
                        score += 5;
                        break;
                    case 'J': case 'X':
                        score += 8;
                        break;
                    case 'Q': case 'Z':
                        score += 10;
                        break;
                }
            }
       std::cout << "El puntaje de " << palabra << " es " << score << std::endl;
    }
    else{ std::cout << "No existe la palabra" << std::endl;}
    return score;
  }