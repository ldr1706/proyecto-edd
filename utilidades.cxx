#include "utilidades.h"

#include <cctype>
#include <algorithm>

std::string stackToString(std::stack<char> stack) {
  std::string result;
  while (!stack.empty()) {
    result += stack.top();
    stack.pop();
  }
  return result;
}

std::string stringInverso(std::string palabra){
  std::stack<char> pila;
  for(int i = 0; i < palabra.length(); i++){
    pila.push(palabra[i]);
  }
  return stackToString(pila);
}

int puntajePalabra(std::string palabra){
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
  std::transform(palabra.begin(), palabra.end(), palabra.begin(), ::toupper);
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
  return score;
}
