#include <notez.h>

NotezDB *notez_init(char *filename)
{
    NotezDB *tmp;
    int status;

    tmp = (NotezDB *) malloc(sizeof(NotezDB));
    status = sqlite3_open(filename, &(tmp->db));
    if (status) {
        fprintf(stderr, "Can't open database: %s\n", sqlite3_errmsg(tmp->db));
        sqlite3_close(tmp->db);
        exit(1);
    }
    return tmp;
}
