#include <notez.h>

void notez_shorthelp()
{
    printf(
        "Type `notez help' to get help.\n"
    );
}

void notez_longhelp()
{
    printf(
        "Available commands are:\n"
        "  notez [list]\n"
        "  notez add [<title> [<message>]]\n"
        "  notez del <title>/<num>\n"
        "  notez search <str>\n"
    );
}

