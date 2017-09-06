#ifndef CLI_CONSOLE_HPP
#define CLI_CONSOLE_HPP

#include <math.h>
#include <array>

namespace cli {
  enum ClearMethods {
    CLEAR_END = 0,
    CLEAR_BEGIN = 1,
    CLEAR_ALL = 2,
  };
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
  inline void MoveCursor(int x = 0, int y = 0) {
    if (x < 0) {
      printf("\033[%iD", abs(x));
    } else if (x > 0) {
      printf("\033[%iC", x);
    }
    if (y < 0) {
      printf("\033[%iA", abs(y));
    } else if (y > 0) {
      printf("\033[%iB", y);
    }
  }
  inline void SetCursor(int x, int y) { printf("\033[%i;%iH", x, y); }
  inline void Clear(unsigned int method = CLEAR_ALL) {
    printf("\033[%iJ", method);
  }
  inline void ClearLine(unsigned int method = CLEAR_ALL) {
    printf("\033[%iK", method);
  }

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

  inline std::string Default(std::string str) {
    return "\033[39m" + str + "\033[39m";
  }
  inline std::string Black(std::string str) {
    return "\033[30m" + str + "\033[39m";
  }
  inline std::string Red(std::string str) {
    return "\033[31m" + str + "\033[39m";
  }
  inline std::string Green(std::string str) {
    return "\033[32m" + str + "\033[39m";
  }
  inline std::string Yellow(std::string str) {
    return "\033[33m" + str + "\033[39m";
  }
  inline std::string Blue(std::string str) {
    return "\033[34m" + str + "\033[39m";
  }
  inline std::string Magenta(std::string str) {
    return "\033[35m" + str + "\033[39m";
  }
  inline std::string Cyan(std::string str) {
    return "\033[36m" + str + "\033[39m";
  }
  inline std::string Grey(std::string str) {
    return "\033[37m" + str + "\033[39m";
  }

  inline std::string LightBlack(std::string str) {
    return "\033[90m" + str + "\033[39m";
  }
  inline std::string LightRed(std::string str) {
    return "\033[91m" + str + "\033[39m";
  }
  inline std::string LightGreen(std::string str) {
    return "\033[92m" + str + "\033[39m";
  }
  inline std::string LightYellow(std::string str) {
    return "\033[93m" + str + "\033[39m";
  }
  inline std::string LightBlue(std::string str) {
    return "\033[94m" + str + "\033[39m";
  }
  inline std::string LightMagenta(std::string str) {
    return "\033[95m" + str + "\033[39m";
  }
  inline std::string LightCyan(std::string str) {
    return "\033[96m" + str + "\033[39m";
  }
  inline std::string White(std::string str) {
    return "\033[97m" + str + "\033[39m";
  }

  inline std::string DefaultBg(std::string str) {
    return "\033[49m" + str + "\033[49m";
  }
  inline std::string BlackBg(std::string str) {
    return "\033[40m" + str + "\033[49m";
  }
  inline std::string RedBg(std::string str) {
    return "\033[41m" + str + "\033[49m";
  }
  inline std::string GreenBg(std::string str) {
    return "\033[42m" + str + "\033[49m";
  }
  inline std::string YellowBg(std::string str) {
    return "\033[43m" + str + "\033[49m";
  }
  inline std::string BlueBg(std::string str) {
    return "\033[44m" + str + "\033[49m";
  }
  inline std::string MagentaBg(std::string str) {
    return "\033[45m" + str + "\033[49m";
  }
  inline std::string CyanBg(std::string str) {
    return "\033[46m" + str + "\033[49m";
  }
  inline std::string GreyBg(std::string str) {
    return "\033[47m" + str + "\033[49m";
  }

  inline std::string LightBlackBg(std::string str) {
    return "\033[100m" + str + "\033[49m";
  }
  inline std::string LightRedBg(std::string str) {
    return "\033[101m" + str + "\033[49m";
  }
  inline std::string LightGreenBg(std::string str) {
    return "\033[102m" + str + "\033[49m";
  }
  inline std::string LightYellowBg(std::string str) {
    return "\033[103m" + str + "\033[49m";
  }
  inline std::string LightBlueBg(std::string str) {
    return "\033[104m" + str + "\033[49m";
  }
  inline std::string LightMagentaBg(std::string str) {
    return "\033[105m" + str + "\033[49m";
  }
  inline std::string LightCyanBg(std::string str) {
    return "\033[106m" + str + "\033[49m";
  }
  inline std::string WhiteBg(std::string str) {
    return "\033[107m" + str + "\033[49m";
  }

  inline std::string Color(std::string str, unsigned int color) {
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
  inline std::string Color(std::string str, unsigned int red,
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
           ';' + std::to_string(blue) + 'm' + str + "\033[39m";
  }

}  // namespace cli

#endif /* ifndef CLI_CURSOR_HPP */
