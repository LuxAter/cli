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
    PS_VERTICAL = 1 << 4,
    PS_HORIZONTAL = 1 << 5,
    PS_GRID = 1 << 4 | 1 << 5
  };
  std::string Prompt(const std::string& prompt, const std::string& prompt_style,
                     uint16_t flags = 0) {
    std::string input;
    bool echo = flags & P_ECHO;
    bool password = flags & P_PASSWORD;
    bool number = flags & P_NUMBER;
    bool ifloat = flags & P_FLOAT;
    bool decimal = false;
    std::cout << prompt << ' ' << prompt_style << std::flush;
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
    std::cout << "\033[0m\n";
    return input;
  }
  std::string Prompt(const std::string& prompt, uint16_t flags = 0) {
    return Prompt(prompt, "", flags);
  }
  std::string PromptSuggest(const std::string& prompt,
                            const std::vector<std::string>& options,
                            const std::string& prompt_style,
                            const std::string& suggest_style,
                            const std::string& select_style,
                            uint16_t flags = 0, uint16_t width = 79) {
    std::string input, usr_input;
    bool echo = flags & P_ECHO;
    bool password = flags & P_PASSWORD;
    bool number = flags & P_NUMBER;
    bool ifloat = flags & P_FLOAT;
    bool horizontal = flags & PS_HORIZONTAL;
    bool vertical = flags & PS_VERTICAL;
    bool grid = horizontal && vertical;
    if (!grid && !vertical && !horizontal){
      horizontal = true;
    }
    bool decimal = false;
    std::cout << prompt << ' ' << std::flush;
    uint8_t ch = 0;
    int8_t i = -1;
    std::array<std::string, 5> suggest;
    while (ch != 10) {
      if (i == -1) {
        suggest = estl::fuzz::Fuzz<5>(input, options,
                                      estl::fuzz::LevenshteinCaseInsensitive);
      }
      if(grid){
      }else if(horizontal){
        std::cout << "\n\033[2K";
        for (std::size_t j = 0; j < suggest.size(); ++j) {
          if (static_cast<int8_t>(j) == i) {
            std::cout << select_style << suggest[j] << "\033[0m ";
          } else {
            std::cout << suggest_style << suggest[j] << "\033[0m ";
          }
        }
        std::cout << "\033[A\033[G";
      }else if(vertical){
        for(std::size_t j = 0; j < suggest.size(); ++j){
          if(static_cast<int8_t>(j) == i){
            std::cout << "\n\033[2K" << select_style << suggest[j] << "\033[0m";
          }else{
            std::cout << "\n\033[2K" << suggest_style << suggest[j] << "\033[0m";
          }
        }
        std::cout << "\033[" << suggest.size() << "A\033[G";
      }
      std::cout << "\033[2K" << prompt << ' ' << prompt_style << input
                << "\033[0m" << std::flush;
      ch = Ascii(GetCh());
      switch (ch) {
        case 10:
          break;
        case 127:
          if (i != -1) {
            i = -1;
          }
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
        case 9:
          i += 1;
          if (i == -1) {
            usr_input = input;
          }
          if (i == 5) {
            input = usr_input;
            i = -1;
          }
          if (i != -1) {
            input = suggest[i];
          }
          break;
        default:
          if (i != -1) {
            i = -1;
          }
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
    if(grid){

    }else if(horizontal){
      std::cout << "\n\033[G\033[2K";
    }else if(vertical){
      for(std::size_t j = 0; j < suggest.size(); ++j){
        std::cout << "\n\033[G\033[2K";
      }
      std::cout << "\033[" << suggest.size() - 1 << "A\033[G";
    }
    return input;
  }
  std::string PromptSuggest(const std::string& prompt,
                            const std::vector<std::string>& options,
                            uint16_t flags = PS_HORIZONTAL, uint16_t width = 79) {
    return PromptSuggest(prompt, options, "", "", "\033[1m", flags, width);
  }
  std::string PromptSuggest(const std::string& prompt,
                            const std::vector<std::string>& options,
                            const std::string& prompt_style,
                            uint16_t flags = PS_HORIZONTAL, uint16_t width = 79) {
    return PromptSuggest(prompt, options, prompt_style, "", "\033[1m", flags, width);
  }
  std::string PromptSuggest(const std::string& prompt,
                            const std::vector<std::string>& options,
                            const std::string& prompt_style,
                            const std::string& suggest_style,
                            uint16_t flags = PS_HORIZONTAL, uint16_t width = 79) {
    return PromptSuggest(prompt, options, prompt_style, suggest_style,
                         suggest_style + "\033[1m", flags, width);
  }
}  // namespace cli

#endif  // CLI_PROMPT_HPP_
