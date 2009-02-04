#include <notez.h>

int notez_default_callback(void *not_used, int argc, char **argv, char **col_name)
{
    int i;
    for (i = 0; i < argc; i++)
    {
        printf("%s = %s\n", col_name[i], argv[i] ? argv[i] : "NULL");
    }
    return 0;
}

// id, title, note, changed
int notez_list_callback(void *not_used, int argc, char **argv, char **col_name)
{
    char *dur = duration(argv[1]);
    printf("   %s   %s   %s\n", argv[0], dur, argv[2]);
    return 0;
}

