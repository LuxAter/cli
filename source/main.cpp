#include "color.hpp"
#include "prompt.hpp"
#include "get_char.hpp"

#include <iostream>

int main(int argc, char *argv[])
{
  cli::Prompt("Test", cli::P_ECHO);
  std::string word = cli::PromptSuggest("User:", {"Arden", "Tristan", "Grace", "Genie", "Alec", "Sean", "Ryan"}, "", cli::GetColor("cyan"), cli::GetColor("yellow"), cli::P_ECHO);
  std::cout << ">>" << word << "<<\n";
  /* CODE */
  return 0;
}
