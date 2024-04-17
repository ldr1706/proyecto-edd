#include "utilidades.h"

std::string stackToString(std::stack<char> stack) {
  std::string result;
  while (!stack.empty()) {
    result += stack.top();
    stack.pop();
  }
  return result;
}
