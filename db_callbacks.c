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

int notez_list_callback(void *not_used, int argc, char **argv, char **col_name)
{
    int i;
    for (i = 0; i < argc; i++)
    {
        printf("%s = %s\n", col_name[i], argv[i] ? argv[i] : "NULL");
    }
    return 0;
}


