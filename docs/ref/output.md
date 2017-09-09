# Output #

## Summary ##

### Enum ###

|                     |                              |
|---------------------|------------------------------|
| [`Colors`](#colors) | Used to define color options |

### Functions ###

#### Attribute Functions ####

|                           |                                 |
|---------------------------|---------------------------------|
| [`Reset`](#reset)         | Reset all attributes to default |
| [`Bold`](#bold)           | Prints bold text                |
| [`Dim`](#dim)             | Prints dim text                 |
| [`Italic`](#italic)       | Prints italic text              |
| [`Underline`](#underline) | Prints underlined text          |
| [`Blink`](#blink)         | Prints blinking text            |
| [`BlinkFast`](#blink-fast) | Prints fast blinking text       |
| [`Reverse`](#reverse)     | Prints reversed/inversed text   |
| [`Conceal`](#conceal)     | Prints concealed text           |
| [`CrossOut`](#crossout)   | Prints crossed out text         |

#### Color Functions ####

|                         |                                                    |
|-------------------------|----------------------------------------------------|
| [`ColorFg`](#colorfg)   | Sets foreground to specified value                 |
| [`FColorFg`](#fcolorfg) | Sets foreground to floating value                  |
| [`ColorBg`](#colorbg)   | Sets background to specified value                 |
| [`FColorBg`](#fcolorbg) | Sets background to floating value                  |
| [`Color`](#color)       | Sets background and foreground to specified values |
| [`FColor`](#fcolor)     | Sets background and foreground to floating values  |

##### Base 16 Colors #####

|                                |                               |
|--------------------------------|-------------------------------|
| [`Default`](#base-16-colors_1) | Prints the default color text |
| [`Black`](#base-16-colors_1)   | Prints black text             |
| [`Red`](#base-16-colors_1)     | Prints red text               |
| [`Green`](#base-16-colors_1)   | Prints green text             |
| [`Yellow`](#base-16-colors_1)  | Prints yellow text            |
| [`Blue`](#base-16-colors_1)    | Prints blue text              |
| [`Magenta`](#base-16-colors_1) | Prints magenta text           |
| [`Cyan`](#base-16-colors_1)    | Prints cyan text              |
| [`Grey`](#base-16-colors_1)    | Prints grey text              |

## Enum ##

### Colors ###

```cpp
enum Colors{
  BLACK = 0,
  RED = 1,
  GREEN = 2,
  YELLOW = 3,
  BLUE = 4,
  MAGENTA = 5,
  CYAN = 6,
  GREY = 7,
  LIGHT_BLACK = 8,
  LIGHT_RED = 9,
  LIGHT_GREEN = 10,
  LIGHT_YELLOW = 11,
  LIGHT_BLUE = 12,
  LIGHT_MAGENTA = 13,
  LIGHT_CYAN = 14,
  WHITE = 15
};
```
The different base 16 colors that can be used to specify a color in
[`ColorFg`](#colorfg) or [`ColorBg`](#colorbg).

## Functions ##

### Attribute Functions ###

#### Reset ####

```cpp
inline std::string Reset();
inline std::stirng Reset(std::string str);
```

Resets the current output to default text formatting.

| Parameter |                 |
|-----------|-----------------|
| `str`     | String to print |

**Return:** string containing reset data and `str` if supplied.

#### Bold ####

```cpp
inline std::string Bold(std::string str);
inline std::string StartBold();
inline std::string EndBold();
```

Controls bold output settings;

* Prints only `str` in bold.
* Starts bold output.
* Stops bold output.

| Parameter |                 |
|-----------|-----------------|
| `str`     | String to print |

**Return:** string containing attribute data, and `str` if supplied.

#### Dim ####

```cpp
inline std::string Dim(std::string str);
inline std::string StartDim();
inline std::string EndDim();
```

Controls dim output settings;

* Prints only `str` in dim.
* Starts dim output.
* Stops dim output.

| Parameter |                 |
|-----------|-----------------|
| `str`     | String to print |

**Return:** string containing attribute data, and `str` if supplied.

#### Italic ####

```cpp
inline std::string Italic(std::string str);
inline std::string StartItalic();
inline std::string EndItalic();
```

Controls italic output settings;

* Prints only `str` in italic.
* Starts italic output.
* Stops italic output.

| Parameter |                 |
|-----------|-----------------|
| `str`     | String to print |

**Return:** string containing attribute data, and `str` if supplied.

#### Underline ####

```cpp
inline std::string Underline(std::string str);
inline std::string StartUnderline();
inline std::string EndUnderline();
```

Controls underline output settings;

* Prints only `str` underlined.
* Starts underlined output.
* Stops underlined output.

| Parameter |                 |
|-----------|-----------------|
| `str`     | String to print |

**Return:** string containing attribute data, and `str` if supplied.

#### Blink ####

```cpp
inline std::string Blink(std::string str);
inline std::string StartBlink();
inline std::string EndBlink();
```

Controls blinking output settings;

* Prints only `str` blinking.
* Starts blinking output.
* Stops blinking output.

| Parameter |                 |
|-----------|-----------------|
| `str`     | String to print |

**Return:** string containing attribute data, and `str` if supplied.

#### Blink Fast ####

```cpp
inline std::string BlinkFast(std::string str);
inline std::string StartBlinkFast();
inline std::string EndBlinkFast();
```

Controls fast blinking output settings;

* Prints only `str` blinking fast.
* Starts fast blinking output.
* Stops fast blinking output.

| Parameter |                 |
|-----------|-----------------|
| `str`     | String to print |

**Return:** string containing attribute data, and `str` if supplied.

#### Reverse ####

```cpp
inline std::string Reverse(std::string str);
inline std::string StarReverse();
inline std::string EndReverse();
```

Controls reverse output settings;

* Prints only `str` reversed.
* Starts reversed output.
* Stops reversed output.

| Parameter |                 |
|-----------|-----------------|
| `str`     | String to print |

**Return:** string containing attribute data, and `str` if supplied.

#### Conceal ####

```cpp
inline std::string Conceal(std::string str);
inline std::string StarConceal();
inline std::string EndConceal();
```

Controls conceal output settings;

* Prints only `str` concealed.
* Starts concealed output.
* Stops concealed output.

| Parameter |                 |
|-----------|-----------------|
| `str`     | String to print |

**Return:** string containing attribute data, and `str` if supplied.

#### CrossOut ####

```cpp
inline std::string CrossOut(std::string str);
inline std::string StartCrossOut();
inline std::string EndCrossOut();
```

Controls cross out output settings;

* Prints only `str` crossed out.
* Starts crossed out output.
* Stops crossed out output.

| Parameter |                 |
|-----------|-----------------|
| `str`     | String to print |

**Return:** string containing attribute data, and `str` if supplied.

### Color Functions ###

#### ColorFg ####

```cpp
inline std::string ColorFg(unsigned int color);
inline std::string ColorFg(std::string str, unsigned int color);
inline std::string ColorFg(unsigned int red, unsigned int green,
                           unsigned int blue);
inline std::string ColorFg(std::string str, unsigned int red,
                           unsigned int green, unsigned int blue);
inline std::string ColorFg(std::array<unsigned int, 3> color);
inline std::string ColorFg(std::string str,
                           std::array<unsigned int, 3> color);
```

Sets the color output to the color specified in `color`, which is set from [`Colors`](#colors). Or sets the color from 0-256 values for `red`, `blue`, and `green`, if the current terminal supports true colors.

| Parameter |                                                                             |
|-----------|-----------------------------------------------------------------------------|
| `color`   | value representing a color of the base 16 selection, or array of rbg values |
| `str`     | string to print in provided color                                           |
| `red`     | 0-256 value for red component                                               |
| `green`   | 0-256 value for green component                                             |
| `blue`    | 0-256 value for blue component                                              |


**Return:** string containing attribute data, and `str` if supplied.

#### FColorFg ####

```cpp
inline std::string FColorFg(double red, double green,
                           double blue);
inline std::string FColorFg(std::string str, double red,
                           double green, double blue);
inline std::string FColorFg(std::array<double, 3> color);
inline std::string FColorFg(std::string str,
                           std::array<double, 3> color);
```

 Sets the color from 0-1 values for `red`, `blue`, and `green`, if the current
 terminal supports true colors. And prints `str` if supplied.

| Parameter |                                   |
|-----------|-----------------------------------|
| `color`   | array of 0-1 rbg values           |
| `str`     | string to print in provided color |
| `red`     | 0-1 value for red component       |
| `green`   | 0-1 value for green component     |
| `blue`    | 0-1 value for blue component      |

**Return:** string containing attribute data, and `str` if supplied

#### ColorBg ####

```cpp
inline std::string ColorBg(unsigned int color);
inline std::string ColorBg(std::string str, unsigned int color);
inline std::string ColorBg(unsigned int red, unsigned int green,
                           unsigned int blue);
inline std::string ColorBg(std::string str, unsigned int red,
                           unsigned int green, unsigned int blue);
inline std::string ColorBg(std::array<unsigned int, 3> color);
inline std::string ColorBg(std::string str,
                           std::array<unsigned int, 3> color);
```

Sets the color output to the background color specified in `color`, which is set from [`Colors`](#colors). Or sets the background color from 0-256 values for `red`, `blue`, and `green`, if the current terminal supports true colors.

| Parameter |                                                                             |
|-----------|-----------------------------------------------------------------------------|
| `color`   | value representing a color of the base 16 selection, or array of rbg values |
| `str`     | string to print in provided color                                           |
| `red`     | 0-256 value for red component                                               |
| `green`   | 0-256 value for green component                                             |
| `blue`    | 0-256 value for blue component                                              |


**Return:** string containing attribute data, and `str` if supplied.

#### FColorBg ####

```cpp
inline std::string FColorBg(double red, double green,
                           double blue);
inline std::string FColorBg(std::string str, double red,
                           double green, double blue);
inline std::string FColorBg(std::array<double, 3> color);
inline std::string FColorBg(std::string str,
                           std::array<double, 3> color);
```

 Sets the background color from 0-1 values for `red`, `blue`, and `green`, if the current
 terminal supports true colors. And prints `str` if supplied.

| Parameter |                                   |
|-----------|-----------------------------------|
| `color`   | array of 0-1 rbg values           |
| `str`     | string to print in provided color |
| `red`     | 0-1 value for red component       |
| `green`   | 0-1 value for green component     |
| `blue`    | 0-1 value for blue component      |

**Return:** string containing attribute data, and `str` if supplied

#### Color ####

```cpp
inline std::string Color(unsigned int color_fg, unsigned int color_bg);
inline std::string Color(std::string str, unsigned int color_fg,
                         unsigned int color_bg);
inline std::string Color(unsigned int red_fg, unsigned int green_fg,
                         unsigned int blue_fg, unsigned int red_bg,
                         unsigned int green_bg, unsigned int blue_bg);
inline std::string Color(std::string str, unsigned int red_fg,
                         unsigned int green_fg, unsigned int blue_fg,
                         unsigned int red_bg, unsigned int green_bg,
                         unsigned int blue_bg);
inline std::string Color(std::array<unsigned int, 3> fg,
                         std::array<unsigned int, 3> bg);
inline std::string Color(std::string str, std::array<unsigned int, 3> fg,
                         std::array<unsigned int, 3> bg);
```

Sets the foreground and background color to either a color set from
[`Colors`](#colors), or from 0-256 `red`, `green`, `blue` values.

| Parameter  |                                    |
|------------|------------------------------------|
| `color_fg` | base 16 color index                |
| `color_bg` | base 16 color index                |
| `str`      | string to be printed in set color  |
| `red_fg`   | 0-256 red value for fg             |
| `green_fg` | 0-256 green value for fg           |
| `blue_fg`  | 0-256 blue value for fg            |
| `red_bg`   | 0-256 red value for bg             |
| `green_bg` | 0-256 green value for bg           |
| `blue_bg`  | 0-256 blue value for bg            |
| `fg`       | array of 3 0-256 rgb values for fg |
| `bg`       | array of 3 0-256 rgb values for bg |

**Return:** string containing attribute data, and `str` if supplied

#### FColor ####

```cpp
inline std::string FColor(double red_fg, double green_fg,
                         double blue_fg, double red_bg,
                         double green_bg, double blue_bg);
inline std::string FColor(std::string str, double red_fg,
                         double green_fg, double blue_fg,
                         double red_bg, double green_bg,
                         double blue_bg);
inline std::string FColor(std::array<double, 3> fg,
                         std::array<double, 3> bg);
inline std::string FColor(std::string str, std::array<double, 3> fg,
                         std::array<double, 3> bg);
```

Sets the foreground and background color from 0-1 `red`, `green`, `blue` values.

| Parameter  |                                   |
|------------|-----------------------------------|
| `red_fg`   | 0-1 red value for fg              |
| `green_fg` | 0-1 green value for fg            |
| `blue_fg`  | 0-1 blue value for fg             |
| `red_bg`   | 0-1 red value for bg              |
| `green_bg` | 0-1 green value for bg            |
| `blue_bg`  | 0-1 blue value for bg             |
| `str`      | string to be printed in set color |
| `fg`       | array of 3 0-1 rgb values for fg  |
| `bg`       | array of 3 0-1 rgb values for bg  |

**Return:** string containing attribute data, and `str` if supplied

#### Base 16 Colors ####

All of the following base 16 colors have the same set of functions;

```cpp
inline Color();
inline Color(std::string str);
inline LightColor();
inline LightColor(std::string str);
inline ColorBg();
inline ColorBg(std::string str);
inline LightColorBg();
inline LightColorBg(std::string str);
```

With color replaced with the respective color names. The set of possible color
names are:

|         |  |
|---------|--|
| Default |  |
| Black   |  |
| Red     |  |
| Green   |  |
| Yellow  |  |
| Blue    |  |
| Magenta |  |
| Cyan    |  |
| Grey    |  |
| White   |  |

*Note:* `Default` only has definitions for `[1]`, `[2]`, `[5]`, and `[6]`.

*Note:* The light variant of `Grey` does not exist, instead use `White`.

These functions do the following;

* Set the foreground color.
* Set the foreground color only for `str`.
* Set the foreground color to the light variant.
* Set the foreground color to the light variant only for `str`.
* Set the background color.
* Set the background color only for `str`.
* Set the background color to the light variant.
* Set the background color to the light variant only for `str`.

| Parameter |                              |
|-----------|------------------------------|
| `str`     | string to print in set color |

**Return:** string containing attribute data, and `str` if supplied.
