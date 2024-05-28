#include "Graph.h"
#include "utilidades.h"
#include "Diccionario.h"
#include <algorithm>
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <stack>
#include <unordered_map>
#include <unordered_set>
#include <cctype>
//constructores
Graph::Graph() {
}
Graph::Graph(const std::vector<std::string>& vertices) : vertices(vertices) {
    int size = vertices.size();
    matriz.resize(size, std::vector<int>(size, 0));
}
Graph::Graph(int size) {
    matriz.resize(size, std::vector<int>(size, 0));
    vertices.resize(size);
}
//setters y getters 
void Graph::setMatriz(const std::vector<std::vector<int>>& matriz) {
  this->matriz = matriz;
}
void Graph::setVertices(const std::vector<std::string>& vertices) {
  this->vertices = vertices;
  int size = vertices.size();
  matriz.resize(size, std::vector<int>(size, 0));
}
const std::vector<std::vector<int>>& Graph::getMatriz() const {
  return matriz;
}
const std::vector<std::string>& Graph::getVertices() const {
  return vertices;
}
//functiones
bool Graph::diferencia(std::string& pal1, std::string& pal2) {
    int diferencias = 0;
    for (size_t i = 0; i < pal1.length(); ++i) {
        if (pal1[i] != pal2[i]) {
            diferencias++;
        }
    }
  if (diferencias>1) {
      return false;
  } else{return true;}
}
void Graph::crearGrafo(std::vector<string> palabras){
this->setVertices(palabras);
int size = this->vertices.size();
this->matriz.resize(size, std::vector<int>(size, 0));
for (int i = 0; i < size; ++i) {
  for (int j = i + 1; j < size; ++j) {
    if (diferencia(this->vertices[i], this->vertices[j])) {
      matriz[i][j] = 1;
      matriz[j][i] = 1;
   }
  }
 }
}
void Graph::dfs(int v, std::vector<bool>& visited, std::unordered_set<std::string>& resultado) {
    std::stack<int> stack;
    stack.push(v);
    while (!stack.empty()) {
        int current = stack.top();
        stack.pop();
        if (!visited[current]) {
            visited[current] = true;
            resultado.insert(vertices[current]);
            for (int i = 0; i < matriz[current].size(); ++i) {
                if (matriz[current][i] == 1 && !visited[i]) {
                    stack.push(i);
                }
            }
        }
    }
}
bool Graph::valido(const std::string& letras) {
    int comodinCount = 0;
    for (char c : letras) {
        if (!isalpha(c) && c != '?') {
            return false;
        }
        if (c == '?') {
            comodinCount++;
        }
    }
    if (comodinCount>1) {
            return false; 
    }
    return true;
}

std::unordered_set<std::string> Graph::generarPalabras(string letras) {
  std::unordered_set<std::string> resultado;
  std::vector<std::string> comb;
  bool tieneComodin = (letras.find('?') != std::string::npos);
    if (!tieneComodin) {
        comb.push_back(letras);
    } else {
        for (char c = 'a'; c <= 'z'; ++c) {
            std::string temp = letras;
            std::replace(temp.begin(), temp.end(), '?', c);
            comb.push_back(temp);
        }
    }
  for (const string& combo : comb) {
      std::string perm = combo;
      std::sort(perm.begin(), perm.end());
      do {
          if (std::find(vertices.begin(), vertices.end(), perm) != vertices.end()) {
              resultado.insert(perm);
          }
      } while (std::next_permutation(perm.begin(), perm.end()));
  }
  return resultado;
}

void Graph::posibles_palabras(string letras) {
  if (!valido(letras)) {
      std::cout << "La cadena letras tiene símbolos inválidos. Recuerde solo usar un comodín '?'" << std::endl;
      return;
  }
  std::unordered_set<std::string> posibles = generarPalabras(letras);
  std::unordered_set<std::string> validas;
  for (const auto& palabra : posibles) {
      auto it = std::find(vertices.begin(), vertices.end(), palabra);
      if (it != vertices.end()) {
          int index = std::distance(vertices.begin(), it);
          std::vector<bool> visited(vertices.size(), false);
          dfs(index, visited, validas);
      }
  }
  if (validas.empty()) {
      std::cout << "No se encontraron palabras posibles." << std::endl;
      return;
  }
  std::cout << "Las posibles palabras a construir con las letras " << letras << " son:" << std::endl;
  for (const auto& palabra : validas) {
      int puntuacion=puntajePalabra(palabra);
      std::cout << palabra << " (Longitud: " << palabra.size() << ", Puntuación: " << puntuacion << ")" << std::endl;
  }
}
