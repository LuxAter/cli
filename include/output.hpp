#ifndef CLI_OUTPUT_HPP
#define CLI_OUTPUT_HPP

#include <math.h>
#include <array>

namespace cli {
  enum Colors {
    BLACK = 0,
    RED = 1,
    GREEN = 2,
    YELLOW = 3,
    BLUE = 4,
    MAGENTA = 5,
    CYAN = 6,
    GREY = 7,
    LIGHT_BLACK = 8,
    LIGHT_RED = 9,
    LIGHT_GREEN = 10,
    LIGHT_YELLOW = 11,
    LIGHT_BLUE = 12,
    LIGHT_MAGENTA = 13,
    LIGHT_CYAN = 14,
    WHITE = 15
  };

  // Attrubute functions
  inline std::string Reset() { return "\033[0m"; }
  inline std::string Reset(std::string str) {
    return "\033[0m" + str + "\033[0m";
  }
  inline std::string Bold(std::string str) {
    return "\033[1m" + str + "\033[21m";
  }
  inline std::string Dim(std::string str) {
    return "\033[2m" + str + "\033[22m";
  }
  inline std::string Italic(std::string str) {
    return "\033[3m" + str + "\033[23m";
  }
  inline std::string Underline(std::string str) {
    return "\033[4m" + str + "\033[24m";
  }
  inline std::string Blink(std::string str) {
    return "\033[5m" + str + "\033[25m";
  }
  inline std::string BlinkFast(std::string str) {
    return "\033[6m" + str + "\033[26m";
  }
  inline std::string Reverse(std::string str) {
    return "\033[7m" + str + "\033[27m";
  }
  inline std::string Conceal(std::string str) {
    return "\033[8m" + str + "\033[28m";
  }
  inline std::string CrossOut(std::string str) {
    return "\033[9m" + str + "\033[29m";
  }

  // Start attrubute functions
  inline std::string StartBold() { return "\033[1m"; }
  inline std::string StartDim() { return "\033[2m"; }
  inline std::string StartItalic() { return "\033[3m"; }
  inline std::string StartUnderline() { return "\033[4m"; }
  inline std::string StartBlink() { return "\033[5m"; }
  inline std::string StartBLinkFast() { return "\033[6m"; }
  inline std::string StartReverse() { return "\033[7m"; }
  inline std::string StartConceal() { return "\033[8m"; }
  inline std::string StartCrossOut() { return "\033[9m"; }

  // End attrubute functions
  inline std::string EndBold() { return "\033[1m"; }
  inline std::string EndDim() { return "\033[2m"; }
  inline std::string EndItalic() { return "\033[3m"; }
  inline std::string EndUnderline() { return "\033[4m"; }
  inline std::string EndBlink() { return "\033[5m"; }
  inline std::string EndBLinkFast() { return "\033[6m"; }
  inline std::string EndReverse() { return "\033[7m"; }
  inline std::string EndConceal() { return "\033[8m"; }
  inline std::string EndCrossOut() { return "\033[9m"; }

  // Foreground color functions
  inline std::string Default() { return "\033[39m"; }
  inline std::string Default(std::string str) {
    return "\033[39m" + str + "\033[39m";
  }
  inline std::string Black() { return "\033[30m"; }
  inline std::string Black(std::string str) {
    return "\033[30m" + str + "\033[39m";
  }
  inline std::string Red() { return "\033[31m"; }
  inline std::string Red(std::string str) {
    return "\033[31m" + str + "\033[39m";
  }
  inline std::string Green() { return "\033[32m"; }
  inline std::string Green(std::string str) {
    return "\033[32m" + str + "\033[39m";
  }
  inline std::string Yellow() { return "\033[33m"; }
  inline std::string Yellow(std::string str) {
    return "\033[33m" + str + "\033[39m";
  }
  inline std::string Blue() { return "\033[34m"; }
  inline std::string Blue(std::string str) {
    return "\033[34m" + str + "\033[39m";
  }
  inline std::string Magenta() { return "\033[35m"; }
  inline std::string Magenta(std::string str) {
    return "\033[35m" + str + "\033[39m";
  }
  inline std::string Cyan() { return "\033[36m"; }
  inline std::string Cyan(std::string str) {
    return "\033[36m" + str + "\033[39m";
  }
  inline std::string Grey() { return "\033[37m"; }
  inline std::string Grey(std::string str) {
    return "\033[37m" + str + "\033[39m";
  }

  // Light foreground color functions
  inline std::string LightBlack() { return "\033[90m"; }
  inline std::string LightBlack(std::string str) {
    return "\033[90m" + str + "\033[39m";
  }
  inline std::string LightRed() { return "\033[91m"; }
  inline std::string LightRed(std::string str) {
    return "\033[91m" + str + "\033[39m";
  }
  inline std::string LightGreen() { return "\033[92m"; }
  inline std::string LightGreen(std::string str) {
    return "\033[92m" + str + "\033[39m";
  }
  inline std::string LightYellow() { return "\033[93m"; }
  inline std::string LightYellow(std::string str) {
    return "\033[93m" + str + "\033[39m";
  }
  inline std::string LightBlue() { return "\033[41m"; }
  inline std::string LightBlue(std::string str) {
    return "\033[94m" + str + "\033[39m";
  }
  inline std::string LightMagenta() { return "\033[95m"; }
  inline std::string LightMagenta(std::string str) {
    return "\033[95m" + str + "\033[39m";
  }
  inline std::string LightCyan() { return "\033[96m"; }
  inline std::string LightCyan(std::string str) {
    return "\033[96m" + str + "\033[39m";
  }
  inline std::string White() { return "\033[97m"; }
  inline std::string White(std::string str) {
    return "\033[97m" + str + "\033[39m";
  }

  // Background color funcitons
  inline std::string DefaultBg() { return "\033[49m"; }
  inline std::string DefaultBg(std::string str) {
    return "\033[49m" + str + "\033[49m";
  }
  inline std::string BlackBg() { return "\033[40m"; }
  inline std::string BlackBg(std::string str) {
    return "\033[40m" + str + "\033[49m";
  }
  inline std::string RedBg() { return "\033[41m"; }
  inline std::string RedBg(std::string str) {
    return "\033[41m" + str + "\033[49m";
  }
  inline std::string GreenBg() { return "\033[42m"; }
  inline std::string GreenBg(std::string str) {
    return "\033[42m" + str + "\033[49m";
  }
  inline std::string YellowBg() { return "\033[43m"; }
  inline std::string YellowBg(std::string str) {
    return "\033[43m" + str + "\033[49m";
  }
  inline std::string BlueBg() { return "\033[44m"; }
  inline std::string BlueBg(std::string str) {
    return "\033[44m" + str + "\033[49m";
  }
  inline std::string MagentaBg() { return "\033[45m"; }
  inline std::string MagentaBg(std::string str) {
    return "\033[45m" + str + "\033[49m";
  }
  inline std::string CyanBg() { return "\033[46m"; }
  inline std::string CyanBg(std::string str) {
    return "\033[46m" + str + "\033[49m";
  }
  inline std::string GreyBg() { return "\033[47m"; }
  inline std::string GreyBg(std::string str) {
    return "\033[47m" + str + "\033[49m";
  }

  // Light background color functions
  inline std::string LightBlackBg() { return "\033[100m"; }
  inline std::string LightBlackBg(std::string str) {
    return "\033[100m" + str + "\033[49m";
  }
  inline std::string LightRedBg() { return "\033[101m"; }
  inline std::string LightRedBg(std::string str) {
    return "\033[101m" + str + "\033[49m";
  }
  inline std::string LightGreenBg() { return "\033[102m"; }
  inline std::string LightGreenBg(std::string str) {
    return "\033[102m" + str + "\033[49m";
  }
  inline std::string LightYellowBg() { return "\033[103m"; }
  inline std::string LightYellowBg(std::string str) {
    return "\033[103m" + str + "\033[49m";
  }
  inline std::string LightBlueBg() { return "\033[104m"; }
  inline std::string LightBlueBg(std::string str) {
    return "\033[104m" + str + "\033[49m";
  }
  inline std::string LightMagentaBg() { return "\033[105m"; }
  inline std::string LightMagentaBg(std::string str) {
    return "\033[105m" + str + "\033[49m";
  }
  inline std::string LightCyanBg() { return "\033[106m"; }
  inline std::string LightCyanBg(std::string str) {
    return "\033[106m" + str + "\033[49m";
  }
  inline std::string WhiteBg() { return "\033[107m"; }
  inline std::string WhiteBg(std::string str) {
    return "\033[107m" + str + "\033[49m";
  }

  // All foreground color funcitons
  inline std::string ColorFg(unsigned int color) {
    std::string str;
    switch (color) {
      case BLACK:
        str = Black();
        break;
      case RED:
        str = Red();
        break;
      case GREEN:
        str = Green();
        break;
      case YELLOW:
        str = Yellow();
        break;
      case BLUE:
        str = Blue();
        break;
      case MAGENTA:
        str = Magenta();
        break;
      case CYAN:
        str = Cyan();
        break;
      case GREY:
        str = Grey();
        break;
      case LIGHT_BLACK:
        str = LightBlack();
        break;
      case LIGHT_RED:
        str = LightRed();
        break;
      case LIGHT_GREEN:
        str = LightGreen();
        break;
      case LIGHT_YELLOW:
        str = LightYellow();
        break;
      case LIGHT_BLUE:
        str = LightBlue();
        break;
      case LIGHT_MAGENTA:
        str = LightMagenta();
        break;
      case LIGHT_CYAN:
        str = LightCyan();
        break;
      case WHITE:
        str = White();
        break;
    }
    return str;
  }
  inline std::string ColorFg(std::string str, unsigned int color) {
    switch (color) {
      case BLACK:
        str = Black(str);
        break;
      case RED:
        str = Red(str);
        break;
      case GREEN:
        str = Green(str);
        break;
      case YELLOW:
        str = Yellow(str);
        break;
      case BLUE:
        str = Blue(str);
        break;
      case MAGENTA:
        str = Magenta(str);
        break;
      case CYAN:
        str = Cyan(str);
        break;
      case GREY:
        str = Grey(str);
        break;
      case LIGHT_BLACK:
        str = LightBlack(str);
        break;
      case LIGHT_RED:
        str = LightRed(str);
        break;
      case LIGHT_GREEN:
        str = LightGreen(str);
        break;
      case LIGHT_YELLOW:
        str = LightYellow(str);
        break;
      case LIGHT_BLUE:
        str = LightBlue(str);
        break;
      case LIGHT_MAGENTA:
        str = LightMagenta(str);
        break;
      case LIGHT_CYAN:
        str = LightCyan(str);
        break;
      case WHITE:
        str = White(str);
        break;
    }
    return str;
  }
  inline std::string ColorFg(unsigned int red, unsigned int green,
                             unsigned int blue) {
    if (red > 255) {
      red = 255;
    }
    if (blue > 255) {
      blue = 255;
    }
    if (blue > 255) {
      blue = 255;
    }
    return "\033[38;2;" + std::to_string(red) + ';' + std::to_string(green) +
           ';' + std::to_string(blue) + 'm';
  }
  inline std::string ColorFg(std::string str, unsigned int red,
                             unsigned int green, unsigned int blue) {
    if (red > 255) {
      red = 255;
    }
    if (blue > 255) {
      blue = 255;
    }
    if (blue > 255) {
      blue = 255;
    }
    return "\033[38;2;" + std::to_string(red) + ';' + std::to_string(green) +
           ';' + std::to_string(blue) + 'm' + str + "\033[39m";
  }
  inline std::string ColorFg(std::array<unsigned int, 3> color) {
    return Color(color[0], color[1], color[2]);
  }
  inline std::string ColorFg(std::string str,
                             std::array<unsigned int, 3> color) {
    return Color(str, color[0], color[1], color[2]);
  }
  inline std::string FColorFg(double red, double green, double blue) {
    if (red > 1.0f) {
      red = 1.0f;
    } else if (red < 0.0f) {
      red = 0.0f;
    }
    if (green > 1.0f) {
      green = 1.0f;
    } else if (green < 0.0f) {
      green = 0.0f;
    }
    if (blue > 1.0f) {
      blue = 1.0f;
    } else if (blue < 0.0f) {
      blue = 0.0f;
    }
    return Color((int)(255 * red), (int)(255 * green), (int)(255 * blue));
  }
  inline std::string FColorFg(std::string str, double red, double green,
                              double blue) {
    if (red > 1.0f) {
      red = 1.0f;
    } else if (red < 0.0f) {
      red = 0.0f;
    }
    if (green > 1.0f) {
      green = 1.0f;
    } else if (green < 0.0f) {
      green = 0.0f;
    }
    if (blue > 1.0f) {
      blue = 1.0f;
    } else if (blue < 0.0f) {
      blue = 0.0f;
    }
    return Color(str, (int)(255 * red), (int)(255 * green), (int)(255 * blue));
  }
  inline std::string FColorFg(std::array<double, 3> color) {
    return FColor(color[0], color[1], color[2]);
  }
  inline std::string FColorFg(std::string str, std::array<double, 3> color) {
    return FColor(str, color[0], color[1], color[2]);
  }

  // All background color function
  inline std::string ColorBg(unsigned int color) {
    std::string str;
    switch (color) {
      case BLACK:
        str = BlackBg();
        break;
      case RED:
        str = RedBg();
        break;
      case GREEN:
        str = GreenBg();
        break;
      case YELLOW:
        str = YellowBg();
        break;
      case BLUE:
        str = BlueBg();
        break;
      case MAGENTA:
        str = MagentaBg();
        break;
      case CYAN:
        str = CyanBg();
        break;
      case GREY:
        str = GreyBg();
        break;
      case LIGHT_BLACK:
        str = LightBlackBg();
        break;
      case LIGHT_RED:
        str = LightRedBg();
        break;
      case LIGHT_GREEN:
        str = LightGreenBg();
        break;
      case LIGHT_YELLOW:
        str = LightYellowBg();
        break;
      case LIGHT_BLUE:
        str = LightBlueBg();
        break;
      case LIGHT_MAGENTA:
        str = LightMagentaBg();
        break;
      case LIGHT_CYAN:
        str = LightCyanBg();
        break;
      case WHITE:
        str = WhiteBg();
        break;
    }
    return str;
  }
  inline std::string ColorBg(std::string str, unsigned int color) {
    switch (color) {
      case BLACK:
        str = BlackBg(str);
        break;
      case RED:
        str = RedBg(str);
        break;
      case GREEN:
        str = GreenBg(str);
        break;
      case YELLOW:
        str = YellowBg(str);
        break;
      case BLUE:
        str = BlueBg(str);
        break;
      case MAGENTA:
        str = MagentaBg(str);
        break;
      case CYAN:
        str = CyanBg(str);
        break;
      case GREY:
        str = GreyBg(str);
        break;
      case LIGHT_BLACK:
        str = LightBlackBg(str);
        break;
      case LIGHT_RED:
        str = LightRedBg(str);
        break;
      case LIGHT_GREEN:
        str = LightGreenBg(str);
        break;
      case LIGHT_YELLOW:
        str = LightYellowBg(str);
        break;
      case LIGHT_BLUE:
        str = LightBlueBg(str);
        break;
      case LIGHT_MAGENTA:
        str = LightMagentaBg(str);
        break;
      case LIGHT_CYAN:
        str = LightCyanBg(str);
        break;
      case WHITE:
        str = WhiteBg(str);
        break;
    }
    return str;
  }
  inline std::string ColorBg(unsigned int red, unsigned int green,
                             unsigned int blue) {
    if (red > 255) {
      red = 255;
    }
    if (blue > 255) {
      blue = 255;
    }
    if (blue > 255) {
      blue = 255;
    }
    return "\033[48;2;" + std::to_string(red) + ';' + std::to_string(green) +
           ';' + std::to_string(blue) + 'm';
  }
  inline std::string ColorBg(std::string str, unsigned int red,
                             unsigned int green, unsigned int blue) {
    if (red > 255) {
      red = 255;
    }
    if (blue > 255) {
      blue = 255;
    }
    if (blue > 255) {
      blue = 255;
    }
    return "\033[48;2;" + std::to_string(red) + ';' + std::to_string(green) +
           ';' + std::to_string(blue) + 'm' + str + "\033[49m";
  }
  inline std::string ColorBg(std::array<unsigned int, 3> color) {
    return ColorBg(color[0], color[1], color[2]);
  }
  inline std::string ColorBg(std::string str,
                             std::array<unsigned int, 3> color) {
    return ColorBg(str, color[0], color[1], color[2]);
  }
  inline std::string FColorBg(double red, double green, double blue) {
    if (red > 1.0f) {
      red = 1.0f;
    } else if (red < 0.0f) {
      red = 0.0f;
    }
    if (green > 1.0f) {
      green = 1.0f;
    } else if (green < 0.0f) {
      green = 0.0f;
    }
    if (blue > 1.0f) {
      blue = 1.0f;
    } else if (blue < 0.0f) {
      blue = 0.0f;
    }
    return ColorBg((int)(255 * red), (int)(255 * green), (int)(255 * blue));
  }
  inline std::string FColorBg(std::string str, double red, double green,
                              double blue) {
    if (red > 1.0f) {
      red = 1.0f;
    } else if (red < 0.0f) {
      red = 0.0f;
    }
    if (green > 1.0f) {
      green = 1.0f;
    } else if (green < 0.0f) {
      green = 0.0f;
    }
    if (blue > 1.0f) {
      blue = 1.0f;
    } else if (blue < 0.0f) {
      blue = 0.0f;
    }
    return ColorBg(str, (int)(255 * red), (int)(255 * green),
                   (int)(255 * blue));
  }
  inline std::string FColorBg(std::array<double, 3> color) {
    return FColorBg(color[0], color[1], color[2]);
  }
  inline std::string FColorBg(std::string str, std::array<double, 3> color) {
    return FColorBg(str, color[0], color[1], color[2]);
  }

  // All foreground and background color funcitons
  inline std::string Color(unsigned int color_fg, unsigned int color_bg) {
    return Color(color_fg) + ColorBg(color_bg);
  }
  inline std::string Color(std::string str, unsigned int color_fg,
                           unsigned int color_bg) {
    return Color(ColorBg(str, color_bg), color_fg);
  }
  inline std::string Color(unsigned int red_fg, unsigned int green_fg,
                           unsigned int blue_fg, unsigned int red_bg,
                           unsigned int green_bg, unsigned int blue_bg) {
    return Color(red_fg, green_fg, blue_fg) +
           ColorBg(red_bg, green_bg, blue_bg);
  }
  inline std::string Color(std::string str, unsigned int red_fg,
                           unsigned int green_fg, unsigned int blue_fg,
                           unsigned int red_bg, unsigned int green_bg,
                           unsigned int blue_bg) {
    return Color(ColorBg(str, red_bg, green_bg, blue_bg), red_fg, green_fg,
                 blue_fg);
  }
  inline std::string Color(std::array<unsigned int, 3> fg,
                           std::array<unsigned int, 3> bg) {
    return Color(fg) + ColorBg(bg);
  }
  inline std::string Color(std::string str, std::array<unsigned int, 3> fg,
                           std::array<unsigned int, 3> bg) {
    return Color(ColorBg(str, bg), fg);
  }
  inline std::string FColor(double red_fg, double green_fg, double blue_fg,
                            double red_bg, double green_bg, double blue_bg) {
    return FColor(red_fg, green_fg, blue_fg) +
           FColorBg(red_bg, green_bg, blue_bg);
  }
  inline std::string FColor(std::string str, double red_fg, double green_fg,
                            double blue_fg, double red_bg, double green_bg,
                            double blue_bg) {
    return FColor(FColorBg(str, red_bg, green_bg, blue_bg), red_fg, green_fg,
                  blue_fg);
  }
  inline std::string FColor(std::array<double, 3> fg,
                            std::array<double, 3> bg) {
    return FColor(fg) + FColorBg(bg);
  }
  inline std::string FColor(std::string str, std::array<double, 3> fg,
                            std::array<double, 3> bg) {
    return FColor(FColorBg(str, bg), fg);
  }

}  // namespace cli

#endif /* ifndef CLI_OUTPUT_HPP */
