#ifndef CLI_REGEX_HPP
#define CLI_REGEX_HPP

#include <regex>

#include <iostream>

namespace cli {
  bool Regex(std::string str, std::string regex) {
    return std::regex_match(str, std::regex(regex));
  }

  std::vector<std::string> RegexFind(std::string str, std::string regex) {
    std::vector<std::string> matches;
    std::smatch match;
    while (std::regex_search(str, match, std::regex(regex))) {
      matches.push_back(match.str());
      str = match.suffix();
    }
    return matches;
  }

  std::string RegexReplace(std::string str, std::string regex,
                           std::string replace) {
    return std::regex_replace(str, std::regex(regex), replace.c_str());
  }

  std::string IntRegex() { return "[\\+-]?[0-9]+"; }
  std::string FloatRegex() { return "[\\+-]?[0-9]*\\.[0-9]+"; }
  std::string CharRegex() { return "."; }
  std::string StringRegex() { return ".+"; }
  std::string TimeRegex() {
    return "([0-9]|0[0-9]|1[0-9]|2[0-3]):[0-5]?[0-9](:[0-5]?[0-9])?";
  }

  std::string GenerateDateRegex(std::string fmt) {
    std::string regex = "";
    std::map<std::string, std::string> regex_pat = {
        {"abbr_day", "((Mon)|(Tue)|(Wen)|(Thu)|(Fri)|(Sat)|(Sun))"},
        {"day_name",
         "((Monday)|(Tuesday)|(Wednesday)|(Thursday)|(Friday)|(Saturday)|("
         "Sunday))"},
        {"abbr_month",
         "((Jan)|(Feb)|(Mar)|(Apr)|(May)|(Jun)|(Jul)|(Aug)|(Sep)|(Oct)|(Nov)|("
         "Dec))"},
        {"month_name",
         "((January)|(February)|(March)|(April)|(May)|(June)|(July)|(August)|("
         "September)|(October)|(November)|(December))"},
        {"cent", "([0-9][0-9])"},
        {"day", "(0?[1-9]|[12][0-9]|3[01])"},
        {"hour_24", "(([01]?[0-9])|(2[0-4]))"},
        {"hour_12", "((0?[1-9])|(1[1-2]))"},
        {"day_year", "((0?[0-9]?[0-9])|([12][0-9][0-9])|(3[0-6][0-6]))"},
        {"month", "((0?[0-9])|(1[012]))"},
        {"minute", "([0-5]?[0-9])"},
        {"am_pm", "((am)|(Am)|(AM)|(pm)|(Pm)|(PM))"},
        {"second", "(([0-5]?[0-9])|(6[01]))"},
        {"day_week", "([1-7])"},
        {"year_last", "([0-9]{2})"},
        {"year", "([0-9]{4})"}};
    for (int i = 0; i < (int)fmt.size(); i++) {
      if (fmt[i] == '%' && i < (int)fmt.size() - 1) {
        i++;
        if (fmt[i] == 'a') {
          regex += regex_pat["abbr_day"];
        } else if (fmt[i] == 'A') {
          regex += regex_pat["day_name"];
        } else if (fmt[i] == 'b') {
          regex += regex_pat["abbr_month"];
        } else if (fmt[i] == 'B') {
          regex += regex_pat["month_name"];
        } else if (fmt[i] == 'c') {
          regex += regex_pat["abbr_day"] + " " + regex_pat["abbr_month"] + " " +
                   regex_pat["day"] + " " + regex_pat["hour_24"] + ":" +
                   regex_pat["minute"] + ":" + regex_pat["second"] + " " +
                   regex_pat["year"];
        } else if (fmt[i] == 'C') {
          regex += regex_pat["cent"];
        } else if (fmt[i] == 'd') {
          regex += regex_pat["day"];
        } else if (fmt[i] == 'D') {
          regex += regex_pat["month"] + "\\/" + regex_pat["day"] + "\\/" +
                   regex_pat["year_last"];
        } else if (fmt[i] == 'e') {
          regex += regex_pat["day"];
        } else if (fmt[i] == 'F') {
          regex += regex_pat["year"] + "-" + regex_pat["month"] + "-" +
                   regex_pat["day"];
        } else if (fmt[i] == 'h') {
          regex += regex_pat["abbr_month"];
        } else if (fmt[i] == 'H') {
          regex += regex_pat["hour_24"];
        } else if (fmt[i] == 'I') {
          regex += regex_pat["hour_12"];
        } else if (fmt[i] == 'j') {
          regex += regex_pat["day_year"];
        } else if (fmt[i] == 'm') {
          regex += regex_pat["month"];
        } else if (fmt[i] == 'M') {
          regex += regex_pat["minute"];
        } else if (fmt[i] == 'p') {
          regex += regex_pat["am_pm"];
        } else if (fmt[i] == 'r') {
          regex += regex_pat["hour_12"] + ":" + regex_pat["minute"] + ":" +
                   regex_pat["second"] + " " + regex_pat["am_pm"];
        } else if (fmt[i] == 'R') {
          regex += regex_pat["hour_24"] + ":" + regex_pat["minute"];
        } else if (fmt[i] == 'S') {
          regex += regex_pat["second"];
        } else if (fmt[i] == 'T') {
          regex += regex_pat["hour_24"] + ":" + regex_pat["minute"] + ":" +
                   regex_pat["second"];
        } else if (fmt[i] == 'u') {
          regex += regex_pat["day_week"];
        } else if (fmt[i] == 'x') {
          regex += regex_pat["month"] + "\\/" + regex_pat["day"] + "\\/" +
                   regex_pat["year_last"];
        } else if (fmt[i] == 'X') {
          regex += regex_pat["hour_24"] + ":" + regex_pat["minute"] + ":" +
                   regex_pat["second"];
        } else if (fmt[i] == 'y') {
          regex += regex_pat["year_last"];
        } else if (fmt[i] == 'Y') {
          regex += regex_pat["year"];
        } else {
          regex += fmt[i];
        }
      } else {
        if (fmt[i] == '[' || fmt[i] == ']' || fmt[i] == '?' || fmt[i] == '(' ||
            fmt[i] == ')' || fmt[i] == '.' || fmt[i] == '+' || fmt[i] == '*' ||
            fmt[i] == '{' || fmt[i] == '}' || fmt[i] == '/' || fmt[i] == '\\' ||
            fmt[i] == '|' || fmt[i] == '^' || fmt[i] == '$') {
          regex += "\\";
        }
        regex += fmt[i];
      }
    }
    return regex;
  }

}  // namespace cli

#endif /* ifndef CLI_REGEX_HPP */
