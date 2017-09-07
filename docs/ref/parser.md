# Parser #

## Summary ##


The *Parser* class is used to integrate with command line arguments provided at
function call time. It will parse command line arguments and return a map of
values for the program to handle as it will. The *Parser* can also be
configured to provide an automatically generated help and version pages, as well
as different sub groups of options that are distinguished in the help section.

To use the parser class, include `parser.hpp`.

### Member Functions ###

|                                               |                                         |
|-----------------------------------------------|-----------------------------------------|
| [`AddArgument`](#addargument)                 | Adds a new argument to the parser       |
| [`ArgumentGroup`](#argumentgroup)             | Sets a group for new added arguments    |
| [`ParseArgs`](#parseargs)                     | Parses command line arguments           |
| [`SetHelpHeader`](#sethelpheader)             | Sets the header for the help output     |
| [`SetHelpUsage`](#sethelpusage)               | Sets the usage text for the help output |
| [`SetVersion`](#setversion)                   | Sets the version string                 |
| [`SetPrint`](#setprint)                       | Toggles if outputs should be printed    |
| [`DisplayHelp`](#displayhelp)                 | Prints help string                      |
| [`HelpString`](#helpstring)                   | Gets help output as string              |
| [`DisplayVerison`](#displayverison)           | Prints version string                   |
| [`VersionString`](#versionstring)             | Gets version output as string           |
| [`DisplayArgumentHelp`](#displayargumenthelp) | Creates help string for given argument  |
| [`ArgumentCount`](#argumentcount)             | Gets number of arguments                |

## Functions ##

### AddArgument ###

```cpp
void AddArgument(std::string name, std::string dest);
void AddArgument(std::vector<std::string> name, std::string dest);
void AddArgument(std::string name, std::string dest, cli::Any default_value);
void AddArgument(std::vector<std::string> name, std::string dest,
                 cli::Any default_value);
void AddArgument(std::string name, std::string dest,
                 std::string help_action);
void AddArgument(std::vector<std::string> name, std::string dest,
                 std::string help_action);
void AddArgument(std::string, std::string dest, std::string action,
                 std::string help);
void AddArgument(std::vector<std::string> name, std::string dest,
                 std::string action, std::string help);
void AddArgument(std::string name, std::string dest, cli::Any default_value,
                 std::string help);
void AddArgument(std::vector<std::string> name, std::string dest,
                 cli::Any default_value, std::string help);
void AddArgument(std::string name, std::string dest, std::string action,
                 cli::Any default_value, std::string help);
void AddArgument(std::vector<std::string> name, std::string dest,
                 std::string action, cli::Any default_value, std::string help);
```

Adds a new argument to either the global arguments, or the current argument
group.

| Parameters      |                                                |
|-----------------|------------------------------------------------|
| `name`          | name(s) to search for in command line          |
| `dest`          | location to save result to                     |
| `default_value` | default value to save if argument is not used  |
| `help_action`   | either an action to be done, or help text      |
| `action`        | action to be used when argument is called      |
| `help`          | help text for argument to display on help call |

### ArgumentGroup ###

```cpp
Parser& ArgumentGroup(std::string name);
```

Initialized a new argument group, that later arguments will be added to.

**Return Value:** `Parser&`

### ParseArgs ###

```cpp
std::map<std::string, cli::Any> ParseArgs(int argc, const char* argv[]);
```

Reads arguments from command line, and returns a `map`. The map if filled with
the arguments that have been added to the parser from `AddArgument`.

| Parameters |                                             |
|------------|---------------------------------------------|
| `argc`     | number of arguments in `argv`               |
| `argv`     | array of arguments passed from command line |

**Return Value:** `std::map<std::string, cli::Any>` containing parsed data from
command line.

### SetHelpHeader ###

```cpp
void SethelpHeader(std::string msg, ...);
```

Sets the header on help output.

| Parameters |                                           |
|------------|-------------------------------------------|
| `msg`      | text to set as the help header            |
| `...`      | additional arguments for formatting `msg` |

### SetHelpUsage ###

```cpp
void SetHelpUsage(std::string msg, ...);
```

Sets the usage text on help output.

| Parameters |                                           |
|------------|-------------------------------------------|
| `msg`      | text to set as usage text                 |
| `...`      | additional arguments for formatting `msg` |

### SetVersion ###

```cpp
void SetVersion(std::string version, ...);
```

Sets the version text on version and help output.

| Parameters |                                           |
|------------|-------------------------------------------|
| `version`      | text to set as version text                 |
| `...`      | additional arguments for formatting `version` |

### SetPrint ###

```cpp
void SetPrint(bool setting);
```

Sets if output should be printed to `std::cout`.

| Parameters |                       |
|------------|-----------------------|
| `setting`  | setting value to save |

### DisplayHelp ###

```cpp
void DisplayHelp();
```

Prints help text to `std::cout`.

### HelpString ###

```cpp
std::string HelpString();
```

Returns help text as a `std::string`.

**Return Value:** `std::string` containing help text.

### DisplayVersion ###

```cpp
void DisplayVersion();
```

Prints the version text to `std::cout`.

### VersionString ###

```cpp
std::string VersionString();
```

Returns version text as a `std::string`.

**Return Value:** `std::string` containing version text.

### ArgumentCount ###

```cpp
size_t ArgumentCount(std::string group = std::string());
```

Counts the number of arguments set. If `group` is left as `std::string()`,
returns total count of arguments. Otherwise, returns the count of the specified
argument group.

| Parameters |                                 |
|------------|---------------------------------|
| `group`    | string specifying group to count |

**Return Value:** `size_t` count of arguments in specified group.
