# Terminal #

## Summary ##

### Functions ###

|                                   |                                       |
|-----------------------------------|---------------------------------------|
| [`SaveBuffer`](#savebuffer)       | Saves the current buffer settings     |
| [`RestoreBuffer`](#restorebuffer) | Restores the buffer to saved setting  |
| [`BufferOff`](#bufferoff)         | Disables the buffering of input       |
| [`BufferOn`](#bufferon)           | Enables the buffering for input       |
| [`EchoOff`](#echooff)             | Disables echoing input                |
| [`EchoOn`](#echoon)               | Enables echoing of input              |
| [`GetSize`](#getsize)             | Gets the columns and rows of terminal |

## Functions ##

### SaveBuffer ###

```cpp
inline void SaveBuffer();
```

Saves the buffer and buffer settings internally, so that it may be restored
later with [`RestoreBuffer`](#restorebuffer).

### RestoreBuffer ###

```cpp
inline void RestoreBuffer();
```

Restores saved buffer and buffer settings. May only be called after some
instance of [`SaveBuffer`](#savebuffer) is called.

### BufferOff ###

```cpp
inline void BufferOff();
```

Disables input buffering (e.g. the enter key does not need to be pressed).

### BufferOn ###

```cpp
inline void BufferOn();
```

Enables input buffering (e.g. the enter key must be pressed).

### EchoOff ###

```cpp
inline void EchoOff();
```

Disables input echoing (e.g. the terminal will not print the keys that are
pressed).

### EchoOn ###

```cpp
inline void EchoOn();
```

Enables input echoing (e.g. the terminal will print the keys pressed).

### GetSize ###

```cpp
inline void GetSize(int& col, int& row);
```

Gets the size of the terminal in columns and rows, and returns the values
thought the input parameters.

| Parameter |                                       |
|-----------|---------------------------------------|
| `col`     | Returns number of columns in terminal |
| `row`     | Returns number of rows in terminal    |
