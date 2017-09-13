#include <iostream>
#include <regex>

#include "output.hpp"
#include "parser.hpp"

int main(int argc, const char* argv[]) {
  cli::Parser parser;

  // std::string tm_str;
  // std::cin >> tm_str;
  // struct tm ctm;
  // strptime(tm_str.c_str(), "%H:%M:%S", &ctm);
  // printf("Hour: %d Min: %d Sec: %d", ctm.tm_hour, ctm.tm_min, ctm.tm_sec);

  parser.AddArgument("Int", "a", "int");
  parser.AddArgument("Double", "double", "double");
  parser.AddArgument("Date", "date", "date");
  parser.AddArgument("Time", "time", "time");
  parser.AddArgument("Date/Time", "date_time", "date_time");
  parser.AddArgument("String", "string", "string");
  std::map<std::string, cli::Any> args = parser.ParseArgs(argc, argv);
  std::cout << args["a"] << "<<\n";
  std::cout << args["double"] << "<<\n";
  std::cout << args["date"] << "<<\n";
  std::cout << args["time"] << "<<\n";
  std::cout << args["date_time"] << "<<\n";
  std::cout << args["string"] << "<<\n";

  return 0;
}
