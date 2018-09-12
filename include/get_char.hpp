#ifndef CLI_GET_CHAR_HPP_
#define CLI_GET_CHAR_HPP_

#include <sys/ioctl.h>
#include <termios.h>
#include <unistd.h>
#include <iostream>

namespace cli {
  enum KeyCodes {
    KEY_ERR = 0,
    KEY_ENTER = 10,
    KEY_ESCAPE = 27,
    KEY_SPACE = 32,
    KEY_EXCLAMATION_MARK = 33,
    KEY_QUOTATION_MARK = 34,
    KEY_NUMBER_SIGN = 35,
    KEY_DOLLAR_SIGN = 36,
    KEY_PERCENT_SIGN = 37,
    KEY_AMPERSAND = 38,
    KEY_APOSTROPHE = 39,
    KEY_LEFT_PARENTHESIS = 40,
    KEY_RIGHT_PARENTHESIS = 41,
    KEY_ASTERISK = 42,
    KEY_PLUS = 43,
    KEY_COMMA = 44,
    KEY_MINUS = 45,
    KEY_FULL_STOP = 46,
    KEY_SOLIDUS = 47,
    KEY_ZERO = 48,
    KEY_ONE = 49,
    KEY_TWO = 50,
    KEY_THREE = 51,
    KEY_FOUR = 52,
    KEY_FIVE = 53,
    KEY_SIX = 54,
    KEY_SEVEN = 55,
    KEY_EIGHT = 56,
    KEY_NINE = 57,
    KEY_COLON = 58,
    KEY_SEMICOLON = 59,
    KEY_LESS_THAN_SIGN = 60,
    KEY_EQUALS_SIGN = 61,
    KEY_GREATER_THAN_SIGN = 62,
    KEY_QUESTION_MARK = 63,
    KEY_AT = 64,
    KEY_CAPITAL_A = 65,
    KEY_CAPITAL_B = 66,
    KEY_CAPITAL_C = 67,
    KEY_CAPITAL_D = 68,
    KEY_CAPITAL_E = 69,
    KEY_CAPITAL_F = 70,
    KEY_CAPITAL_G = 71,
    KEY_CAPITAL_H = 72,
    KEY_CAPITAL_I = 73,
    KEY_CAPITAL_J = 74,
    KEY_CAPITAL_K = 75,
    KEY_CAPITAL_L = 76,
    KEY_CAPITAL_M = 77,
    KEY_CAPITAL_N = 78,
    KEY_CAPITAL_O = 79,
    KEY_CAPITAL_P = 80,
    KEY_CAPITAL_Q = 81,
    KEY_CAPITAL_R = 82,
    KEY_CAPITAL_S = 83,
    KEY_CAPITAL_T = 84,
    KEY_CAPITAL_U = 85,
    KEY_CAPITAL_V = 86,
    KEY_CAPITAL_W = 87,
    KEY_CAPITAL_X = 88,
    KEY_CAPITAL_Y = 89,
    KEY_CAPITAL_Z = 90,
    KEY_LEFT_SQUARE_BRACKET = 91,
    KEY_REVERSE_SOLIDUS = 92,
    KEY_RIGHT_SQUARE_BRACKET = 93,
    KEY_CIRCUMFLEX_ACCENT = 94,
    KEY_LOW_LINE = 95,
    KEY_GRAVE_ACCENT = 96,
    KEY_A = 97,
    KEY_B = 98,
    KEY_C = 99,
    KEY_D = 100,
    KEY_E = 101,
    KEY_F = 102,
    KEY_G = 103,
    KEY_H = 104,
    KEY_I = 105,
    KEY_J = 106,
    KEY_K = 107,
    KEY_L = 108,
    KEY_M = 109,
    KEY_N = 110,
    KEY_O = 111,
    KEY_P = 112,
    KEY_Q = 113,
    KEY_R = 114,
    KEY_S = 115,
    KEY_T = 116,
    KEY_U = 117,
    KEY_V = 118,
    KEY_W = 119,
    KEY_X = 120,
    KEY_Y = 121,
    KEY_Z = 122,
    KEY_LEFT_CURLY_BRACKET = 123,
    KEY_VERTICAL_LINE = 124,
    KEY_RIGHT_CURLY_BRACKET = 125,
    KEY_TILDE = 126,
    KEY_BACKSPACE = 127,

    KEY_UP = 128,
    KEY_DOWN = 129,
    KEY_RIGHT = 130,
    KEY_LEFT = 131
  };

  uint8_t GetCh() {
    int result = -1, bytes = 0;
    struct termios term;
    tcgetattr(0, &term);
    term.c_lflag &= !ICANON;
    term.c_lflag &= ~ECHO;
    tcsetattr(0, TCSANOW, &term);
    while (result != 0 || bytes <= 0) {
      bool wait = true;
      while (wait == true) {
        usleep(100);
        result = ioctl(0, FIONREAD, &bytes);
        wait = !bytes;
      }
    }
    uint8_t key = 0;
    char ch = std::cin.get();
    if (ch == 3) {
      exit(1);
    } else if (ch == 27 && bytes > 1) {
      switch (std::cin.get()) {
        case '[': {
          if (bytes > 2) {
            switch (std::cin.get()) {
              case 'A':
                key = KEY_UP;
                break;
              case 'B':
                key = KEY_DOWN;
                break;
              case 'C':
                key = KEY_RIGHT;
                break;
              case 'D':
                key = KEY_LEFT;
                break;
            }
          } else {
            key = 27;
          }
          break;
        }
        default:
          key = 27;
      }
    } else {
      key = ch;
    }
    tcgetattr(0, &term);
    term.c_lflag |= ECHO;
    term.c_lflag |= ICANON;
    tcsetattr(0, TCSANOW, &term);
    return key;
  }

  char Ascii(uint8_t ch) { return (ch >= 128 ? 0 : static_cast<char>(ch)); }
}  // namespace cli

#endif  // CLI_GET_CHAR_HPP_
