#ifndef PALABRA_H
#define PALABRA_H

#include <iostream>
#include <sstream>
#include <vector>
#include <functional>
#include <string>
#include <stack>

using namespace std;
class Palabra{
public:
Palabra();
int puntaje_palabra(string palabra, std::vector<std::string> palabras, std::vector<std::stack<char>> palabrasInverso);

};
#endif