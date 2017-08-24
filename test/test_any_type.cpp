#include "any_type.hpp"

#include <sstream>
#include <string>

#include "gtest/gtest.h"

class AnyTest : public testing::Test {
 protected:
  virtual void SetUp() {
    b = true;
    c = 2017;
    d = double(3.1415);
    e = float(3.1415);
    f = 'a';
    g = "const char*";
    h = std::string("std::string");
  }
  virtual void TearDown() {}
  cli::Any a, b, c, d, e, f, g, h;
};

TEST_F(AnyTest, Constructors) {
  cli::Any value;
  EXPECT_EQ(value.type, 0);
  cli::Any b(true);
  EXPECT_EQ(b.type, 1);
  cli::Any i(2017);
  EXPECT_EQ(i.type, 2);
  cli::Any d(double(3.1415));
  EXPECT_EQ(d.type, 3);
  cli::Any f(float(3.1415));
  EXPECT_EQ(f.type, 4);
  cli::Any c('a');
  EXPECT_EQ(c.type, 5);
  cli::Any cc("const char*");
  EXPECT_EQ(cc.type, 6);
  cli::Any s(std::string("std::string"));
  EXPECT_EQ(s.type, 7);
}

TEST_F(AnyTest, OperatorEq) {
  cli::Any v;
  EXPECT_EQ(v.type, 0);
  v = false;
  EXPECT_EQ(v.type, 1);
  v = 2017;
  EXPECT_EQ(v.type, 2);
  v = double(3.1415);
  EXPECT_EQ(v.type, 3);
  v = float(3.1415);
  EXPECT_EQ(v.type, 4);
  v = 'a';
  EXPECT_EQ(v.type, 5);
  v = "const char*";
  EXPECT_EQ(v.type, 6);
  v = std::string("std::string");
  EXPECT_EQ(v.type, 7);
}

TEST_F(AnyTest, GetValue) {
  EXPECT_EQ(a.Bool(), bool());
  EXPECT_EQ(a.Int(), int());
  EXPECT_EQ(a.Double(), double());
  EXPECT_EQ(a.Float(), float());
  EXPECT_EQ(a.Char(), char());
  EXPECT_EQ(std::string(std::string(a.Cchar())), "");
  EXPECT_EQ(a.String(), std::string());

  EXPECT_EQ(b.Bool(), true);
  EXPECT_EQ(b.Int(), int());
  EXPECT_EQ(b.Double(), double());
  EXPECT_EQ(b.Float(), float());
  EXPECT_EQ(b.Char(), char());
  EXPECT_EQ(std::string(std::string(b.Cchar())), "");
  EXPECT_EQ(b.String(), std::string());

  EXPECT_EQ(c.Bool(), bool());
  EXPECT_EQ(c.Int(), 2017);
  EXPECT_EQ(c.Double(), double());
  EXPECT_EQ(c.Float(), float());
  EXPECT_EQ(c.Char(), char());
  EXPECT_EQ(std::string(c.Cchar()), "");
  EXPECT_EQ(c.String(), std::string());

  EXPECT_EQ(d.Bool(), bool());
  EXPECT_EQ(d.Int(), int());
  EXPECT_EQ(d.Double(), double(3.1415));
  EXPECT_EQ(d.Float(), float());
  EXPECT_EQ(d.Char(), char());
  EXPECT_EQ(std::string(d.Cchar()), "");
  EXPECT_EQ(d.String(), std::string());

  EXPECT_EQ(e.Bool(), bool());
  EXPECT_EQ(e.Int(), int());
  EXPECT_EQ(e.Double(), double());
  EXPECT_EQ(e.Float(), float(3.1415));
  EXPECT_EQ(e.Char(), char());
  EXPECT_EQ(std::string(e.Cchar()), "");
  EXPECT_EQ(e.String(), std::string());

  EXPECT_EQ(f.Bool(), bool());
  EXPECT_EQ(f.Int(), int());
  EXPECT_EQ(f.Double(), double());
  EXPECT_EQ(f.Float(), float());
  EXPECT_EQ(f.Char(), 'a');
  EXPECT_EQ(std::string(f.Cchar()), "");
  EXPECT_EQ(f.String(), std::string());

  EXPECT_EQ(g.Bool(), bool());
  EXPECT_EQ(g.Int(), int());
  EXPECT_EQ(g.Double(), double());
  EXPECT_EQ(g.Float(), float());
  EXPECT_EQ(g.Char(), char());
  EXPECT_EQ(std::string(g.Cchar()), "const char*");
  EXPECT_EQ(g.String(), std::string());

  EXPECT_EQ(h.Bool(), bool());
  EXPECT_EQ(h.Int(), int());
  EXPECT_EQ(h.Double(), double());
  EXPECT_EQ(h.Float(), float());
  EXPECT_EQ(h.Char(), char());
  EXPECT_EQ(std::string(h.Cchar()), "");
  EXPECT_EQ(h.String(), std::string("std::string"));
}

TEST_F(AnyTest, OperatorOut) {
  std::stringstream out;
  out << a;
  EXPECT_EQ(out.str(), "(null)");
  out.str(std::string());
  out << b;
  EXPECT_EQ(out.str(), "1");
  out.str(std::string());
  out << c;
  EXPECT_EQ(out.str(), "2017");
  out.str(std::string());
  out << d;
  EXPECT_EQ(out.str(), "3.1415");
  out.str(std::string());
  out << e;
  EXPECT_EQ(out.str(), "3.1415");
  out.str(std::string());
  out << f;
  EXPECT_EQ(out.str(), "a");
  out.str(std::string());
  out << g;
  EXPECT_EQ(out.str(), "const char*");
  out.str(std::string());
  out << h;
  EXPECT_EQ(out.str(), "std::string");
}
