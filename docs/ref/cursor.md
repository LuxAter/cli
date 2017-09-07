# Cursor #

## Summary ##

Cursor is a selection of functions that are used to enable mobility of the
terminal cursor

### Enums ###

|                                 |                                       |
|---------------------------------|---------------------------------------|
| [`ClearMethods`](#clearmethods) | Enumerator defining types of clearing |

### Functions ###

|                                   |                                              |
|-----------------------------------|----------------------------------------------|
| [`MoveCursor`](#movecursor)       | Moves cursor to relative to current position |
| [`SetCursor`](#setcursor)         | Moves cursor to absolute position            |
| [`SaveCursor`](#savecursor)       | Saves current cursor position                |
| [`RestoreCursor`](#restorecursor) | Restores cursor to saved position            |
| [`Clear`](#clear)                 | Clears terminal of all output                |
| [`ClearLine`](#clearline)         | Clears current line of all output            |

## Enum ##

### ClearMethods ###

```cpp
enum ClearMethods{
  CLEAR_END = 0,
  CLEAR_BEGIN = 1,
  CLEAR_ALL = 2
};
```

The methods that are used in [`Clear`](#clear) and [`ClearLine`](#clearline),
to determin how the clearing is acomplished.

## Functions ##

### MoveCursor ###

```cpp
inline void MoveCursor(int x = 0, int y = 0);
```

Moves the cursor relative to the current cursor position. Entering a negative
number will cause the cursor to be moved in the reverse direction.

| Parameters |                                             |
|------------|---------------------------------------------|
| *x*        | Number of spaces in the x direction to move |
| *y*        | Number of spaces in the y direction to move |

### Setcursor ###

```cpp
inline void SetCursor(int x, int y);
```

Sets the cursor to the absolute location, where the top left of the terminal is
at `0,0`.

| Parameters |                             |
|------------|-----------------------------|
| *x*        | X position to set cursor to |
| *y*        | Y position to set cursor to |


### SaveCursor ###

```cpp
inline void SaveCursor();
```

Saves the current cursor position, so it can be restored at a future point in
time with [`RestoreCursor`](#restorecursor).

### RestoreCursor ###

```cpp
inline void RestoreCursor();
```

Restores the cursor position that was previsously saved with
[`SaveCursor`](#savecursor).

### Clear ###

```cpp
inline void Clear(unsigned int method = CLEAR_ALL);
```

Clears the entire terminal according to the method passed to the function. If
*method* is `CLEAR_END`, then the terminal is only cleared from the cursor to
the end. If *method* is `CLEAR_BEGIN`, then the terminal is only cleared from
the cursor to the begining of the terminal. If *method* is `CLEAR_ALL`, then
the entire terminal is cleared.

| Parameters |                                         |
|------------|-----------------------------------------|
| *method*   | defines the method to use when clearing |

### ClearLine ###

```cpp
inline void ClearLine(unsigned int method = CLEAR_ALL);
```

Clears the line according to the method passed to the function. If *method* is
`CLEAR_END`, then the line is cleared from the cursor to the end of the line.
If *method* is `CLEAR_BEGIN`, then the line is cleared from the begining of the
line to the cursor. If *method* is `CLEAR_ALL`, then the entire line is
cleared.

| Parameters |                                         |
|------------|-----------------------------------------|
| *method*   | defines the method to use when clearing |
