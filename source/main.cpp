#include "regex.hpp"

#include <iostream>

int main(int argc, const char* argv[]) {
  std::cout << cli::GenerateDateRegex("%d-%m-%y");
  /* Code */
  return 0;
}
