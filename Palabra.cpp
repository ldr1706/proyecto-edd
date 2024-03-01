#include "Palabra.h"
#include "Diccionario.h"
#include "Ayuda.h"
using namespace std;

Diccionario dicc;
  Palabra::Palabra() {}
  void Palabra::puntaje_palabra(string palabra) {
    int puntaje_total = 0;
    string archivo = "diccionario.txt";
    std::vector<std::string> args = dicc.inicializar_diccionario(archivo);
    for (const std::string& palabra : args) {
        for (char letra : palabra) {
            letra = std::toupper(letra);
        } 
        for(int i=0; i<palabra.size(); i++)
        {
          if(palabra[i] == 'A' || palabra[i] == 'E' || palabra[i] == 'I' || palabra[i] == 'L' || palabra [i] == 'N' || palabra[i] == 'O' || palabra[i] == 'R' || palabra[i] == 'S' || palabra[i] == 'T' || palabra[i] == 'U')
          {
            puntaje_total += 1;
          }
          else if(palabra[i] == 'D' || palabra[i] == 'G')
          {
            puntaje_total += 2;
          }
          else if(palabra[i] == 'B' || palabra[i] == 'C' || palabra[i] == 'M' || palabra[i] == 'P')
          {
           puntaje_total += 3;
          }
          else if (palabra[i] == 'F' || palabra[i] == 'H' ||palabra[i] == 'V' || palabra[i] == 'W' || palabra[i] == 'Y')
          {
            puntaje_total += 4;
          }
          else if(palabra[i] == 'K')
          {
            puntaje_total += 5;
          }
          else if (palabra[i] == 'J' || palabra[i] == 'X')
          {
            puntaje_total += 8;
          }
          else if (palabra[i] == 'Q' || palabra[i] == 'Z')
          {
            puntaje_total += 10;
          }
        }
        }
    std::cout << "El puntaje total de la palabra es: " << puntaje_total << std::endl;
    }

