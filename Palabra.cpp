#include "Palabra.h"
#include <algorithm>
#include <cctype>
#include <fstream>
#include <iostream>
#include <list>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

Palabra::Palabra() {}
int Palabra::puntaje_palabra(string palabra,std::vector<std::string> palabras) {

  bool b = true;
  int score = 0;
  for (char c : palabra) {
    if (!std::isalpha(c)) {
      b = false;
    }
  }
  if (!b) {
    std::cout << "La palabra contiene símbolos invalidos." << std::endl;
    return score;
  }
  bool find = false;
  for (const std::string &palabri : palabras) {
    if (palabri == palabra) {
      find = true;
      break;
    }
  }
  std::transform(palabra.begin(), palabra.end(), palabra.begin(), ::toupper);
  if (find) {
    for (char caracter : palabra) {
      switch (caracter) {
      case 'A':
      case 'E':
      case 'I':
      case 'O':
      case 'N':
      case 'R':
      case 'T':
      case 'L':
      case 'S':
      case 'U':
        score += 1;
        break;
      case 'D':
      case 'G':
        score += 2;
        break;
      case 'B':
      case 'C':
      case 'M':
      case 'P':
        score += 3;
        break;
      case 'F':
      case 'H':
      case 'V':
      case 'W':
      case 'Y':
        score += 4;
        break;
      case 'K':
        score += 5;
        break;
      case 'J':
      case 'X':
        score += 8;
        break;
      case 'Q':
      case 'Z':
        score += 10;
        break;
      }
    }
  }
  return score;
}