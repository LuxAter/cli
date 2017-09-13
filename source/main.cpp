#include <iostream>
#include <regex>

#include "output.hpp"
#include "parser.hpp"

int main(int argc, const char* argv[]) {
  cli::Parser parser;
  parser.AddArgument("[0-3]?[0-9]-[0-1]?[0-9]-[0-9]{2,4}", "year", "regex");
  parser.AddArgument("Int", "a", "int");
  parser.AddArgument("Double", "double", "double");
  std::map<std::string, cli::Any> args = parser.ParseArgs(argc, argv);
  std::cout << args["year"] << "<<\n";
  std::cout << args["a"] << "<<\n";
  std::cout << args["double"] << "<<\n";

  return 0;
}
