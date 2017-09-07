#ifndef CLI_CURSOR_HPP
#define CLI_CURSOR_HPP

#include <math.h>

namespace cli {
  enum ClearMethods {
    CLEAR_END = 0,
    CLEAR_BEGIN = 1,
    CLEAR_ALL = 2,
  };

  // Cursor movement functions
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
  inline void SaveCursor() { printf("\033[s"); }
  inline void RestoreCursor() { printf("\033[u"); }

  // Console/Line clearing functions
  inline void Clear(unsigned int method = CLEAR_ALL) {
    printf("\033[%iJ", method);
  }
  inline void ClearLine(unsigned int method = CLEAR_ALL) {
    printf("\033[%iK", method);
  }
}  // namespace cli

#endif /* ifndef CLI_CURSOR_HPP */
