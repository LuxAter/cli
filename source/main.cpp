#include <iostream>

#include "output.hpp"

int main() {
  std::cout << cli::Red() << "Hello " << cli::BlueBg() << "World"
            << cli::Default() << "!!!" << cli::DefaultBg() << "\n";
  /* code */
  return 0;
}
