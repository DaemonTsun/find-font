
#include "shl/print.hpp"
#include "find_font.hpp"

int main(int argc, char **argv)
{
    if (argc < 3)
    {
        put("Error: expecting name and style arguments\n");
        return 1;
    }

    ff_cache *c = ff_load_font_cache();

    if (c == nullptr)
    {
        put("Error: could not load font cache\n");
        return 2;
    }

    int ret_code = 0;

    const char **font_names_and_styles = (const char**)argv + 1;
    int count = argc - 1; 
    int found_index = -1;
    const char *path = ff_find_first_font_path(c, font_names_and_styles, count, &found_index);

    if (path == nullptr)
    {
        tprint("No path found.\n");
        ret_code = 3;
    }
    else
        tprint("Path for font '%': %\n", font_names_and_styles[found_index], path);

    ff_unload_font_cache(c);

    return ret_code;
}
