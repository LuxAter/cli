#ifndef CLI_COLOR_HPP_
#define CLI_COLOR_HPP_

#include <cstdint>
#include <cstdio>
#include <cstdlib>

#include <algorithm>
#include <map>
#include <string>

namespace cli {
  uint8_t ColorSupport() {
    if (std::getenv("COLORTERM") != NULL) {
      return 4;
    } else if (std::getenv("TERM") != NULL) {
      std::string term(std::getenv("TERM"));
      if (term == "xterm") {
        return 3;
      } else if (term == "xterm-256color") {
        return 4;
      } else if (term == "linux") {
        return 2;
      } else if (term == "screen-256color") {
        return 3;
      }
    }
    return 0;
  }

  std::string GetColor(std::string color, bool background = false) {
    std::transform(color.begin(), color.end(), color.begin(), ::tolower);
    uint8_t support = ColorSupport();
    if (support == 0 || color == "") {
      return "";
    } else {
      std::map<std::string, std::string> color_map = {
          {"black", (background ? "\033[40m" : "\033[30m")},
          {"red", (background ? "\033[41m" : "\033[31m")},
          {"green", (background ? "\033[42m" : "\033[32m")},
          {"yellow", (background ? "\033[43m" : "\033[33m")},
          {"blue", (background ? "\033[44m" : "\033[34m")},
          {"magenta", (background ? "\033[45m" : "\033[35m")},
          {"cyan", (background ? "\033[46m" : "\033[36m")},
          {"light_grey", (background ? "\033[47m" : "\033[37m")},
          {"dark_grey", (background ? "\033[100m" : "\033[90m")},
          {"light_red", (background ? "\033[101m" : "\033[91m")},
          {"light_green", (background ? "\033[102m" : "\033[92m")},
          {"light_yellow", (background ? "\033[103m" : "\033[93m")},
          {"light_blue", (background ? "\033[104m" : "\033[94m")},
          {"light_magenta", (background ? "\033[105m" : "\033[95m")},
          {"light_cyan", (background ? "\033[106m" : "\033[96m")},
          {"white", (background ? "\033[107m" : "\033[97m")},
      };
      if (color == "reset" || color == "default" || color == "null") {
        return (background ? "\033[49m" : "\033[39m");
      } else if (color_map.find(color) != color_map.end()) {
        return color_map.find(color)->second;
      } else {
        unsigned color_int = 0;
        sscanf(color.c_str(), "#%x", &color_int);
        uint8_t b = color_int & 255;
        uint8_t g = (color_int >> 8) & 255;
        uint8_t r = (color_int >> 16) & 255;
        return (background ? "\033[48;2;" : "\033[38;2;") + std::to_string(r) +
               ';' + std::to_string(g) + ';' + std::to_string(b) + 'm';
      }
    }
    return "";
  }
  std::string GetColor(double r, double g, double b, bool background = false) {
    uint8_t support = ColorSupport();
    if (support == 0) {
      return "";
    } else {
      if (r < 0.0 || g < 0.0 || b < 0.0) {
        return "";
      } else if (r > 1.0 || g > 1.0 || b > 1.0) {
        return (background ? "\033[48;2;" : "\033[38;2;") +
               std::to_string(static_cast<uint8_t>(r)) + ';' +
               std::to_string(static_cast<uint8_t>(g)) + ';' +
               std::to_string(static_cast<uint8_t>(b)) + 'm';
      } else {
        return (background ? "\033[48;2;" : "\033[38;2;") +
               std::to_string(static_cast<uint8_t>(r * 255)) + ';' +
               std::to_string(static_cast<uint8_t>(g * 255)) + ';' +
               std::to_string(static_cast<uint8_t>(b * 255)) + 'm';
      }
    }
    return "";
  }

  std::string Color(const std::string& src, const std::string& fg, std::string bg = "") {
    return GetColor(fg) + GetColor(bg, true) + src + "\033[39;49m";
  }
  std::string Color(const std::string& src, double fg_r, double fg_g, double fg_b,
                    double bg_r = -1, double bg_g = -1, double bg_b = -1) {
    return GetColor(fg_r, fg_g, fg_b) + GetColor(bg_r, bg_g, bg_b, true) + src +
           "\033[39;49m";
  }
}  // namespace cli

#endif  // CLI_COLOR_HPP_
