#ifndef CLI_ANY_TYPE_HPP
#define CLI_ANY_TYPE_HPP

#include <iostream>
#include <string>

namespace cli {
  class Any {
    enum AnyType {
      NONE = 0,
      BOOL = 1,
      INT = 2,
      DOUBLE = 3,
      FLOAT = 4,
      CHAR = 5,
      CCHAR = 6,
      STRING = 7
    };

   public:
    Any() : type(NONE) {}
    Any(const Any& copy)
        : type(copy.type),
          bool_(copy.bool_),
          int_(copy.int_),
          double_(copy.double_),
          float_(copy.float_),
          cchar_(copy.cchar_),
          char_(copy.char_),
          string_(copy.string_) {}
    explicit Any(bool v) : type(BOOL), bool_(v) {}
    explicit Any(int v) : type(INT), int_(v) {}
    explicit Any(double v) : type(DOUBLE), double_(v) {}
    explicit Any(float v) : type(FLOAT), float_(v) {}
    explicit Any(char v) : type(CHAR), char_(v) {}
    explicit Any(const char* v) : type(CCHAR), cchar_(v) {}
    explicit Any(std::string v) : type(STRING), string_(v) {}

    ~Any() {}

    void operator=(bool v) {
      type = BOOL;
      bool_ = v;
    }
    void operator=(int v) {
      type = INT;
      int_ = v;
    }
    void operator=(double v) {
      type = DOUBLE;
      double_ = v;
    }
    void operator=(float v) {
      type = FLOAT;
      float_ = v;
    }
    void operator=(char v) {
      type = CHAR;
      char_ = v;
    }
    void operator=(const char* v) {
      type = CCHAR;
      cchar_ = v;
    }
    void operator=(std::string v) {
      type = STRING;
      string_ = v;
    }

    bool Bool() const { return bool_; }
    int Int() const { return int_; }
    double Double() const { return double_; }
    float Float() const { return float_; }
    const char* Cchar() const { return cchar_; }
    char Char() const { return char_; }
    std::string String() const { return string_; }

    operator bool() { return bool_; }
    operator int() { return int_; }
    operator double() { return double_; }
    operator float() { return float_; }
    operator const char*() { return cchar_; }
    operator char() { return char_; }
    operator std::string() { return string_; }

    friend std::ostream& operator<<(std::ostream& out, const Any& v) {
      switch (v.type) {
        case BOOL:
          out << v.Bool();
          break;
        case INT:
          out << v.Int();
          break;
        case DOUBLE:
          out << v.Double();
          break;
        case FLOAT:
          out << v.Float();
          break;
        case CCHAR:
          out << v.Cchar();
          break;
        case CHAR:
          out << v.Char();
          break;
        case STRING:
          out << v.String();
          break;
        default:
          out << "(null)";
          break;
      }
      return out;
    }

    friend bool operator==(const Any& lhs, const Any& rhs) {
      if (lhs.type != rhs.type) {
        return false;
      } else {
        if (lhs.type == NONE) {
          return true;
        } else if (lhs.type == BOOL) {
          return lhs.Bool() == rhs.Bool();
        } else if (lhs.type == INT) {
          return lhs.Int() == rhs.Int();
        } else if (lhs.type == DOUBLE) {
          return lhs.Double() == rhs.Double();
        } else if (lhs.type == FLOAT) {
          return lhs.Float() == rhs.Float();
        } else if (lhs.type == CHAR) {
          return lhs.Char() == rhs.Char();
        } else if (lhs.type == CCHAR) {
          return lhs.Cchar() == rhs.Cchar();
        } else if (lhs.type == STRING) {
          return lhs.String() == rhs.String();
        } else {
          return false;
        }
      }
    }

    unsigned int type;

   private:
    bool bool_ = bool();
    int int_ = int();
    double double_ = double();
    float float_ = float();
    const char* cchar_ = "";
    char char_ = char();
    std::string string_ = std::string();
  };
}

#endif /* ifndef CLI_ANY_TYPE_HPP */
