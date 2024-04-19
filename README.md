# find-font
Finding font files on Linux and Windows.

This library is intended to be either used as a reference implentation to find fonts on Linux using [`fontconfig`](https://gitlab.freedesktop.org/fontconfig/fontconfig) caches or the Windows Registry on Windows, or the source files `src/find_font.cpp` and `src/find_font.hpp` may be directly copied into a project which uses [`shl`](https://github.com/DaemonTsun/shl).

## Usage

> [!TIP]
> See [`src/main.cpp`](src/main.cpp) for a minimal example using the library.

1. Build the find-font cache using `ff_cache *c = ff_load_font_cache()`
2. Search for fonts using `const char *path = ff_find_font_path(c, "fontname", "fontstyle")`
3. When you no longer need to look for fonts, unload the cache using `ff_unload_font_cache(c)`

See [`src/find_font.hpp`](src/find_font.hpp) for the full reference of functions.
