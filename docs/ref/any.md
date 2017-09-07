# Any #

## Summary ##

Any is a class that is used for representation of many of the different basic
data types. The `Any` class can represent `bool`, `int`, `double`, `float`,
`char`, `const char*`, and `std::string`.

In order to use this class, include `any_type.hpp`.

### Member Enums ###

|                       |                                          |
|-----------------------|------------------------------------------|
| [`AnyType`](#anytype) | Enumerator specifying type that is stored |

### Member Variables ###

|                 |                              |
|-----------------|------------------------------|
| [`type`](#type) | stores the type of the class |

### Member Functions ###

|                                 |                            |
|---------------------------------|----------------------------|
| [`(constructor)`](#constructor) | constructs the class       |
| [`(destructor)`](#destructor)   | destructs the class        |
| [`operator=`](#operator)        | assigns value to the class |

| Access                |                                              |
|-----------------------|----------------------------------------------|
| [`Bool`](#bool)       | returns the `bool` value of the class        |
| [`Int`](#int)         | returns the `int` value of the class         |
| [`Double`](#double)   | returns the `double` value of the class      |
| [`Float`](#float)     | returns the `float` value of the class       |
| [`Char`](#char)       | returns the `char` value of the class        |
| [`Cchar`](#constchar) | returns the `const char*` value of the class |
| [`String`](#string)   | returns the `string` value of the class      |

### Non-Member Functions ###

|                                       |                                     |
|---------------------------------------|-------------------------------------|
| [`operator<<`](#operator_1)      | prints value of the class to stream |
| [`operator==`](#operator_2) | compares two Any type variables     |

---

## Enums ##

### AnyType ###

```cpp
enum AnyType {
  NONE = 0,
  BOOL = 1,
  INT = 2,
  DOUBLE = 3,
  FLOAT = 4,
  CHAR = 5,
  CCHAR = 6,
  STIRNG = 7
};
```

The types that are used to distinguish the variable type that is stored in the
class.

## Variables ##

### type ###

```cpp
unsigned int type = NONE;
```

Variable that is used to store the variable type from [`AnyType`](#anytype) that
is represented by the class.

## Functions ##

### (constructor) ###

```cpp
Any();
Any(const Any& copy);
explicit Any(bool v);
explicit Any(int v);
explicit Any(double v);
explicit Any(float v);
explicit Any(char v);
explicit Any(const char* v);
explicit Any(std::string v);
```

Constructs a new Any object from any of the given values. This value can be
retrieved later using one of the [Access Functions](#member-functions).

| Parameters |                                               |
|------------|-----------------------------------------------|
| *copy*     | another Any object to clone                   |
| *v*        | any data type to set for the Any object value |

### (destructor) ###

```cpp
~Any();
```

Destructs the Any object and any stored data values from it.

### operator= ###

```cpp
Any& operator=(bool v);
Any& operator=(int v);
Any& operator=(double v);
Any& operator=(float v);
Any& operator=(char v);
Any& operator=(const char* v);
Any& operator=(std::string v);
```

Sets the value and type to the corresponding entered value.

#### Parameters ####

|     |                                               |
|-----|-----------------------------------------------|
| *v* | any data type to set for the Any object value |

**Return Value:** `*this`

### Access Function ###

#### Bool ####

```cpp
bool Bool() const;
```

**Return Value:** `bool` stored in class.

#### Int ####

```cpp
int Int() const;
```

**Return Value:** `int` stored in class.

#### Double ####

```cpp
double Double() const;
```

**Return Value:** `double` stored in class.

#### Float ####

```cpp
float Float() const;
```

**Return Value:** `float` stored in class.

#### Char ####

```cpp
char Char() const;
```

**Return Value:** `char` stored in class.

#### Cchar ####

```cpp
const char* Cchar() const;
```

**Return Value:** `const char*` stored in class.

#### String ####

```cpp
std::string String() const;
```

**Return Value:** `std::string` stored in class.

### operator<< ###

```cpp
std::ostream& operator<<(std::ostream& out, const Any& v);
```

Prints value stored by object to ostream.

**Return Value:** `std::ostream` containing object value.

### operator== ###

```cpp
bool operatpr==(const Any& lhs, const Any& rhs);
```

Compares values stored in Any objects, and returns `true` if they are the same.

**Return Value:** `bool` comparison of value stored in Any object.

