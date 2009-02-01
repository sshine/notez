#include <notez.h>

static int notez_default_callback(void *not_used, int argc, char **argv, char **col_name)
{
    int i;
    for (i = 0; i < argc; i++)
    {
        printf("%s = %s\n", col_name[i], argv[i] ? argv[i] : "NULL");
    }
    return 0;
}

static int notez_list_callback(void *not_used, int argc, char **argv, char **col_name)
{
    int i;
    for (i = 0; i < argc; i++)
    {
        printf("%s = %s\n", col_name[i], argv[i] ? argv[i] : "NULL");
    }
    return 0;
}

NotezDB *notez_init(char *filename)
{
    NotezDB *ndb;
    int status;
    char *errMsg;

    errMsg = NULL;

    ndb = (NotezDB *) malloc(sizeof(NotezDB));
    status = sqlite3_open(filename, &(ndb->db));
    if (status) {
        fprintf(stderr, "Can't open database: %s\n", sqlite3_errmsg(ndb->db));
        sqlite3_close(ndb->db);
        exit(1);
    }

    status = sqlite3_exec(ndb->db, NOTEZ_DB_INIT, notez_default_callback, NULL, &errMsg);
    if (status != SQLITE_OK)
    {
        fprintf(stderr, "SQL Error: %s\n", errMsg);
        sqlite3_free(errMsg);
    }

    return ndb;
}

void notez_list(NotezDB *ndb)
{
    int status;
    char *errMsg;

    errMsg = NULL;

    status = sqlite3_exec(ndb->db, "SELECT * FROM notez",
                          notez_list_callback, NULL, &errMsg);
    if (status != SQLITE_OK)
    {
        fprintf(stderr, "SQL Error: %s\n", errMsg);
        sqlite3_free(errMsg);
    }
}
