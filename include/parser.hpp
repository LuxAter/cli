#ifndef CLI_PARSER_HPP
#define CLI_PARSER_HPP

#include <iostream>
#include <map>
#include <string>
#include <tuple>
#include <vector>

#include <stdarg.h>

#include "any.hpp"

namespace cli {
  class Parser {
    struct Argument {
      Argument() {}
      Argument(std::vector<std::string> name_, std::string dest_,
               std::string help_, std::string action_, Any def_value_)
          : name(name_),
            dest(dest_),
            help(help_),
            action(action_),
            default_value(def_value_) {}
      std::vector<std::string> name;
      std::string dest;
      std::string help;
      std::string action;
      Any default_value;
      bool true_argument_ = true;
      bool valid() {
        if (name.size() == 0) {
          return false;
        } else if (dest == std::string()) {
          return false;
        }
        return true;
      }
    };

   public:
    typedef Parser& reference;

    // {name}, dest, [action], [default], [help]
    // add single name with dest
    void AddArgument(std::string name, std::string dest) {
      push_back_argument({{name}, dest, "", "get_value", Any()});
    }
    // add multiple names with dest
    void AddArgument(std::vector<std::string> name, std::string dest) {
      push_back_argument({name, dest, "", "get_value", Any()});
    }
    // add single name with dest, and default
    void AddArgument(std::string name, std::string dest, Any default_value) {
      push_back_argument({{name}, dest, "", "get_value", default_value});
    }
    // add multiple names with dest, and default
    void AddArgument(std::vector<std::string> name, std::string dest,
                     Any default_value) {
      push_back_argument({name, dest, "", "get_value", default_value});
    }
    // add single name with dest, and help/action
    void AddArgument(std::string name, std::string dest,
                     std::string help_action) {
      if (is_action(help_action) == true) {
        push_back_argument({{name}, dest, "", help_action, Any()});
      } else {
        push_back_argument({{name}, dest, help_action, "get_value", Any()});
      }
    }
    // add multiple names with dest and help/action
    void AddArgument(std::vector<std::string> name, std::string dest,
                     std::string help_action) {
      if (is_action(help_action) == true) {
        push_back_argument({name, dest, "", help_action, Any()});
      } else {
        push_back_argument({name, dest, help_action, "get_value", Any()});
      }
    }
    // add single name with dest, action, and help
    void AddArgument(std::string name, std::string dest, std::string action,
                     std::string help) {
      push_back_argument({{name}, dest, help, action, Any()});
    }
    // add multiple names with dest, action, and help
    void AddArgument(std::vector<std::string> name, std::string dest,
                     std::string action, std::string help) {
      push_back_argument({name, dest, help, action, Any()});
    }
    // add single name with dest, default, and help
    void AddArgument(std::string name, std::string dest, Any default_value,
                     std::string help) {
      push_back_argument({{name}, dest, help, "get_value", default_value});
    }
    // add multiple names with dest, default, and help
    void AddArgument(std::vector<std::string> name, std::string dest,
                     Any default_value, std::string help) {
      push_back_argument({name, dest, help, "get_value", default_value});
    }
    // add single name with dest, action, default, and help
    void AddArgument(std::string name, std::string dest, std::string action,
                     Any default_value, std::string help) {
      push_back_argument({{name}, dest, help, action, default_value});
    }
    // add multiple names with dest, action, default, and help
    void AddArgument(std::vector<std::string> name, std::string dest,
                     std::string action, Any default_value, std::string help) {
      push_back_argument({name, dest, help, action, default_value});
    }

    reference ArgumentGroup(std::string name) {
      group_name_ = name;
      return *this;
    }

    std::map<std::string, Any> ParseArgs(int argc, const char* argv[]) {
      exe_name_ = std::string(argv[0]);
      exe_name_.erase(exe_name_.begin(), exe_name_.begin() + 2);
      std::vector<std::string> args;
      for (int i = 0; i < argc; i++) {
        args.push_back(argv[i]);
      }
      std::map<std::string, Any> values = set_defaults();
      bool special = false;
      for (size_t i = 1; i < args.size() && special == false; i++) {
        if (args[i] == "-h" || args[i] == "--help") {
          DisplayHelp();
          special = true;
        } else if (args[i] == "--version" && version_ != std::string()) {
          DisplayVersion();
          special = true;
        }
      }
      for (size_t i = 1; i < args.size() && special == false; i++) {
        Argument arg = find_argument(args[i]);
        if (arg.true_argument_ == false) {
          if (print_ == true) {
            std::cout << "Unknown argument \"" << args[i] << "\"!\n";
          }
        } else if (arg.valid() == false) {
          if (print_ == true) {
            std::cout << "Invalid Argument (no name or destination)!\n";
          }
        }
        if (arg.action == "get_value") {
          if (args.size() > i + 1) {
            i += 1;
            values[arg.dest] = set_value(args[i]);
          } else if (print_ == true) {
            std::cout << "Failed to provide value for argument!\n";
          }
        } else if (arg.action == "set_true") {
          values[arg.dest] = true;
        } else if (arg.action == "set_false") {
          values[arg.dest] = false;
        }
      }
      return values;
    }

    void SetHelpHeader(std::string msg, ...) {
      va_list args, buff_args;
      va_start(args, msg);
      va_start(buff_args, msg);
      ssize_t buff_size = vsnprintf(NULL, 0, msg.c_str(), buff_args);
      char* fmt = new char[buff_size];
      vsprintf(fmt, msg.c_str(), args);
      va_end(buff_args);
      va_end(args);
      help_header_ = std::string(fmt);
    }

    void SetHelpUsage(std::string msg, ...) {
      va_list args, buff_args;
      va_start(args, msg);
      va_start(buff_args, msg);
      ssize_t buff_size = vsnprintf(NULL, 0, msg.c_str(), buff_args);
      char* fmt = new char[buff_size];
      vsprintf(fmt, msg.c_str(), args);
      va_end(buff_args);
      va_end(args);
      help_usage_str_ = std::string(fmt);
    }

    void SetVersion(std::string version, ...) {
      va_list args, buff_args;
      va_start(args, version);
      va_start(buff_args, version);
      ssize_t buff_size = vsnprintf(NULL, 0, version.c_str(), buff_args);
      char* fmt = new char[buff_size];
      vsprintf(fmt, version.c_str(), args);
      va_end(buff_args);
      va_end(args);
      version_ = std::string(fmt);
    }

    void SetPrint(bool setting) { print_ = setting; }

    void DisplayHelp() {
      if (print_ == true) {
        std::cout << HelpString();
      }
    }

    std::string HelpString() {
      std::string help_str;
      help_str += help_header_ + "\n";
      help_str += version_ + "\n";

      int width = 0, current_size = 0;

      for (size_t i = 0; i < help_header_.size(); i++) {
        if (help_header_[i] == '\n') {
          if (current_size > width) {
            width = current_size;
          }
          current_size = 0;
        } else {
          current_size += 1;
        }
      }
      for (size_t i = 0; i < version_.size(); i++) {
        if (version_[i] == '\n') {
          if (current_size > width) {
            width = current_size;
          }
          current_size = 0;
        } else {
          current_size += 1;
        }
      }
      help_str += std::string(width, '=') + "\n";
      if (help_usage_ == true) {
        if (help_usage_str_ == std::string()) {
          help_str += "Usage: " + exe_name_ + " [options]\n";
        } else {
          help_str += help_usage_str_ + "\n";
        }
      }
      help_str += "\nArguments:\n";

      for (std::vector<Argument>::iterator it = arguments_.begin();
           it != arguments_.end(); it++) {
        help_str += DisplayArgumentHelp(*it, 2);
        help_str += "\n";
      }
      for (std::map<std::string, std::vector<Argument>>::iterator it =
               group_arguments_.begin();
           it != group_arguments_.end(); ++it) {
        help_str += "\n  " + it->first + ":\n";
        for (std::vector<Argument>::iterator sub_it = it->second.begin();
             sub_it != it->second.end(); ++sub_it) {
          help_str += DisplayArgumentHelp(*sub_it, 4);
          help_str += "\n";
        }
      }
      return help_str;
    }

    void DisplayVersion() {
      if (print_ == true) {
        std::cout << VersionString() << "\n";
      }
    }

    std::string VersionString() { return version_; }

    std::string DisplayArgumentHelp(Argument arg, int indent) {
      std::string entry = std::string(indent, ' ');
      for (size_t i = 0; i < arg.name.size(); i++) {
        entry += arg.name[i];
        if (i != arg.name.size() - 1) {
          entry += ", ";
        }
      }
      if (entry.size() >= 20) {
        entry += "\n" + std::string(20, ' ');
      } else {
        entry += std::string(20 - entry.size(), ' ');
      }
      entry += arg.help;
      return entry;
    }

    size_t ArgumentCount(std::string group = std::string()) {
      if (group != std::string()) {
        return group_arguments_[group].size();
      } else {
        size_t count = arguments_.size();
        for (std::map<std::string, std::vector<Argument>>::iterator it =
                 group_arguments_.begin();
             it != group_arguments_.end(); ++it) {
          count += it->second.size();
        }
        return count;
      }
    }

   private:
    bool is_action(std::string str) {
      bool action = false;
      if (str == "get_value") {
        action = true;
      } else if (str == "set_true") {
        action = true;
      } else if (str == "set_false") {
        action = true;
      }
      return action;
    }

    void push_back_argument(Argument arg) {
      if (group_name_ == std::string()) {
        arguments_.push_back(arg);
      } else {
        group_arguments_[group_name_].push_back(arg);
      }
    }

    std::map<std::string, Any> set_defaults() {
      std::map<std::string, Any> return_map;
      for (std::vector<Argument>::iterator it = arguments_.begin();
           it != arguments_.end(); ++it) {
        return_map[it->dest] = it->default_value;
      }
      for (std::map<std::string, std::vector<Argument>>::iterator it =
               group_arguments_.begin();
           it != group_arguments_.end(); ++it) {
        for (std::vector<Argument>::iterator sub_it = it->second.begin();
             sub_it != it->second.end(); ++sub_it) {
          return_map[sub_it->dest] = sub_it->default_value;
        }
      }
      return return_map;
    }

    Argument find_argument(std::string str) {
      Argument return_argument;
      return_argument.true_argument_ = false;
      for (std::vector<Argument>::iterator it = arguments_.begin();
           it != arguments_.end(); ++it) {
        for (size_t i = 0; i < it->name.size(); i++) {
          if (it->name[i] == str) {
            return *it;
          }
        }
        for (std::map<std::string, std::vector<Argument>>::iterator it =
                 group_arguments_.begin();
             it != group_arguments_.end(); ++it) {
          for (std::vector<Argument>::iterator sub_it = it->second.begin();
               sub_it != it->second.end(); ++sub_it) {
            for (size_t i = 0; i < sub_it->name.size(); i++) {
              if (sub_it->name[i] == str) {
                return *sub_it;
              }
            }
          }
        }
      }
      return return_argument;
    }

    Any set_value(std::string str) {
      Any type;
      // TODO(Arden): Add string extensions
      if (str == "false") {
        type = false;
      } else if (str == "true") {
        type = true;
      } else {
        bool integer = true, decimal = false;
        for (size_t i = 0; i < str.size() && integer == true; i++) {
          if ((str[i] != 46 && str[i] != 44) && (str[i] > 57 || str[i] < 48)) {
            integer = false;
          } else if (str[i] == 46 || str[i] == 44) {
            if (decimal == false) {
              decimal = true;
            } else {
              integer = false;
            }
          }
        }
        if (integer == true && decimal == true) {
          type = stof(str);
        } else if (integer == true && decimal == false) {
          type = stoi(str);
        } else {
          type = str;
        }
      }
      return type;
    }

    std::string exe_name_ = std::string();

    bool help_usage_ = true;
    bool print_ = true;

    std::string group_name_ = std::string();
    std::string help_header_ = "Help Page";
    std::string help_usage_str_ = std::string();
    std::string version_ = std::string();

    std::vector<Argument> arguments_;
    std::map<std::string, std::vector<Argument>> group_arguments_;
  };
}  // namespace cli

#endif /* ifndef CLI_PARSER_HPP */
