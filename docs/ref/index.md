# Reference #

Here is the API reference for the **CLI** library. The reference documentation
is for defining the specific functions and how they are used. For more in depth
guides on how the functions can be combined, and for further examples, see the
[Tutorial](../tut/index.md).

**CLI** Modules:

* [`any.hpp`](any.md): A class that can be used to represent
    most basic types including `bool`, `int`, `double`, `float`, `char`, `const
    char*`, and `std::string`.
* [`cursor.hpp`](cursor.md): A set of functions used to move the cursor
    around and clear the terminal window and line.
* [`output.hpp`](output.md): A set of functions for fine control over the
    output of the terminal (e.g. Colors and attributes).
* [`parser.hpp`](parser.md): A class that can be used to read and parse the
    input arguments provided by the command line (**Note:** [`Any`](ref/any.md)
    is required).
* [`terminal.hpp`](terminal.md): A set of functions used to control the
    terminal system. Enabling/Disabling buffering or echo.
