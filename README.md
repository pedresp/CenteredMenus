# CENTERED MENUS

Centered Menus is a mini-library designed to simplify the use of centered
menu options in the `ncurses` library.


## How to use

To use this library, you need to add the directory `cms/` to your project
and link it to your executable within your CMakeLists.txt file.

The function provided for the creation of menus is the following:

```
int cms::centered_menu(const std::string& title, const std::vector<std::string>& options)
```

#### Parameters

- **title** Title of the menu
- **options** Vector of possible options present in the menu

#### Return value

- Index of the option selected 

### Examples

This repository includes an example in the `main.cpp` file that
demonstrates how to use the `cms::centered_menu` function. To run it,
you will need to compile
the project using `cmake` and the `CMakeLists.txt` file. 

### Warning

**cms::centered_menu** sets curs_set to *false* and disables the echoing
of characters with `noecho()`. If your program requires curs_set set to
be *true* or needs character echoing enabled, you will need to configure
these manually.
