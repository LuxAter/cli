#ifndef CLI_INPUT_HPP
#define CLI_INPUT_HPP

#include <stdio.h>
#include <sys/ioctl.h>
#include <termios.h>

namespace cli {

  static struct termios saved;

  inline void SaveBuffer() {
    struct termios t;
    tcgetattr(0, &t);
    saved = t;
  }
  inline void RestoreBuffer() { tcsetattr(0, TCSANOW, &saved); }

  inline void BufferOff() {
    struct termios t;
    tcgetattr(0, &t);
    t.c_lflag &= ~ICANON;
    tcsetattr(0, TCSANOW, &t);
  }
  inline void BufferOn() {
    struct termios t;
    tcgetattr(0, &t);
    t.c_lflag &= ICANON;
    tcsetattr(0, TCSANOW, &t);
  }
  inline void EchoOff() {
    struct termios t;
    tcgetattr(0, &t);
    t.c_lflag &= ~ECHO;
    tcsetattr(0, TCSANOW, &t);
  }
  inline void EchoOn() {
    struct termios t;
    tcgetattr(0, &t);
    t.c_lflag &= ECHO;
    tcsetattr(0, TCSANOW, &t);
  }

  inline void GetSize(int& col, int& row) {
    struct winsize w;
    ioctl(0, TIOCGWINSZ, &w);
    col = w.ws_col;
    row = w.ws_row;
  }

}  // namespace cli

#endif /* ifndef CLI_INPUT_HPP */
