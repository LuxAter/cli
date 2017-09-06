#include "cursor.hpp"

#include <iostream>

int main() {
  // std::cout << cli::Bold(cli::Italic("Hello") + "World") + "!";
  std::cout << cli::Underline("Hello") << "\n";
  std::cout << cli::Magenta(cli::CrossOut("World")) << "\n";
  std::cout << cli::Color("Hello World", cli::GREEN) << "\n";
  std::cout << cli::Color("Hello World", cli::LIGHT_GREEN) << "\n";
  std::cout << cli::ColorBg("Hello World", cli::RED) << "\n";
  std::cout << cli::ColorBg("Hello World", 255, 127, 126) << "\n";

  // int b = 0;
  // for (int r = 0; r < 255; r += 2) {
  // for (int g = 0; g < 255; g += 2) {
  // std::cout << cli::Color("#", r, g, b);
  // }
  // std::cout << std::endl;
  // }

  return 0;
}
