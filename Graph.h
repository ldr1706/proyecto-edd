  #ifndef GRAPH_H
#define GRAPH_H
#include "Diccionario.h"
#include "math.h"
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <stack>
#include <cctype>
#include <list>
#include <queue>
#include <stack>
using namespace std;
class Graph{
public:
  std::vector<std::vector<int>> matriz;
  vector<string> vertices;
//constructores
  Graph();
  Graph(const std::vector<string>& vertices);
  Graph(int size);
//getters y setters 
void setMatriz(const std::vector<std::vector<int>>& matriz);
void setVertices(const std::vector<std::string>& vertices);
const std::vector<std::vector<int>>& getMatriz() const;
const std::vector<std::string>& getVertices() const;
//funcitione
int getSize() const ;
const std::vector<string>& getNeighbors(int vertex)const;
void printGraph(const std::vector<std::vector<int>>& adjMatrix);
bool diferencia(std::string& pal1, std::string& pal2);
void crearGrafo(std::vector<string> palabras );
void dfs(int v, std::vector<bool>& visited, std::unordered_set<std::string>& resultado);
bool valido(const std::string& letras);
std::unordered_set<std::string> generarPalabras(string letras);
void posibles_palabras(string letras);
};
#include "Graph.cpp"
#endif
