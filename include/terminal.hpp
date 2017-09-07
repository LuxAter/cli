#ifndef CLI_INPUT_HPP
#define CLI_INPUT_HPP

#include <termios.h>

namespace cli {

  static struct termios saved;

  void SaveBuffer() {
    struct termios t;
    tcgetattr(0, &t);
    saved = t;
  }
  void RestoreBuffer() { tcsetattr(0, TCSANOW, &saved); }

  void BufferOff() {
    struct termios t;
    tcgetattr(0, &t);
    t.c_lflag &= ~ICANON;
    tcsetattr(0, TCSANOW, &t);
  }
  void BufferOn() {
    struct termios t;
    tcgetattr(0, &t);
    t.c_lflag &= ICANON;
    tcsetattr(0, TCSANOW, &t);
  }
  void EchoOff() {
    struct termios t;
    tcgetattr(0, &t);
    t.c_lflag &= ~ECHO;
    tcsetattr(0, TCSANOW, &t);
  }
  void EchoOn() {
    struct termios t;
    tcgetattr(0, &t);
    t.c_lflag &= ECHO;
    tcsetattr(0, TCSANOW, &t);
  }
}  // namespace cli

#endif /* ifndef CLI_INPUT_HPP */
