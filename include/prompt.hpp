#ifndef CLI_PROMPT_HPP_
#define CLI_PROMPT_HPP_

#include <iostream>
#include <string>
#include <vector>

#include "estl/fuzz.hpp"

#include "get_char.hpp"

namespace cli {
  enum PromptFlags {
    P_ECHO = 1 << 0,
    P_PASSWORD = 1 << 1,
    P_NUMBER = 1 << 2,
    P_FLOAT = 1 << 3,
  };
  std::string Prompt(const std::string& prompt, uint16_t flags = 0) {
    std::string input;
    bool echo = flags & P_ECHO;
    bool password = flags & P_PASSWORD;
    bool number = flags & P_NUMBER;
    bool ifloat = flags & P_FLOAT;
    bool decimal = false;
    std::cout << prompt << ' ' << std::flush;
    uint8_t ch = 0;
    while (ch != 10) {
      ch = Ascii(GetCh());
      switch (ch) {
        case 10:
          break;
        case 127:
          if (ifloat && (input.back() == 44 || input.back() == 46)) {
            decimal = false;
          }
          input.pop_back();
          std::cout << "\033[D \033[D" << std::flush;
          break;
        case 0:
          break;
        case 27:
          break;
        default:
          if (number) {
            if (ch >= 48 && ch <= 57) {
              input += ch;
              if (echo && password) {
                std::cout << '*' << std::flush;
              } else if (echo) {
                std::cout << ch << std::flush;
              }
            }
          } else if (ifloat) {
            if (ch >= 48 && ch <= 57) {
              input += ch;
              if (echo && password) {
                std::cout << '*' << std::flush;
              } else if (echo) {
                std::cout << ch << std::flush;
              }
            } else if (decimal == false && (ch == 46 || ch == 44)) {
              decimal = true;
              input += ch;
              if (echo && password) {
                std::cout << '*' << std::flush;
              } else if (echo) {
                std::cout << ch << std::flush;
              }
            }
          } else {
            input += ch;
            if (echo && password) {
              std::cout << '*' << std::flush;
            } else if (echo) {
              std::cout << ch << std::flush;
            }
          }
      }
    }
    std::cout << '\n';
    return input;
  }
  std::string PromptSuggest(const std::string& prompt,
                            const std::vector<std::string>& options,
                            uint16_t flags = 0) {
    std::string input;
    bool echo = flags & P_ECHO;
    bool password = flags & P_PASSWORD;
    bool number = flags & P_NUMBER;
    bool ifloat = flags & P_FLOAT;
    bool decimal = false;
    std::cout << prompt << ' ' << std::flush;
    uint8_t ch = 0;
    while (ch != 10) {
      ch = Ascii(GetCh());
      std::cout << "\n";
      std::array<std::string, 5> suggest = estl::fuzz::Fuzz<5>(input, options);
      for(auto& it : suggest){
        std::cout << it << ' ';
      }
      std::cout << "\033[A\033[G" << prompt << ' ' << input << std::flush;
      switch (ch) {
        case 10:
          break;
        case 127:
          if (ifloat && (input.back() == 44 || input.back() == 46)) {
            decimal = false;
          }
          input.pop_back();
          std::cout << "\033[D \033[D" << std::flush;
          break;
        case 0:
          break;
        case 27:
          break;
        default:
          if (number) {
            if (ch >= 48 && ch <= 57) {
              input += ch;
              if (echo && password) {
                std::cout << '*' << std::flush;
              } else if (echo) {
                std::cout << ch << std::flush;
              }
            }
          } else if (ifloat) {
            if (ch >= 48 && ch <= 57) {
              input += ch;
              if (echo && password) {
                std::cout << '*' << std::flush;
              } else if (echo) {
                std::cout << ch << std::flush;
              }
            } else if (decimal == false && (ch == 46 || ch == 44)) {
              decimal = true;
              input += ch;
              if (echo && password) {
                std::cout << '*' << std::flush;
              } else if (echo) {
                std::cout << ch << std::flush;
              }
            }
          } else {
            input += ch;
            if (echo && password) {
              std::cout << '*' << std::flush;
            } else if (echo) {
              std::cout << ch << std::flush;
            }
          }
      }
    }
    std::cout << '\n';
    return input;
  }
}  // namespace cli

#endif  // CLI_PROMPT_HPP_
