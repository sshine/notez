#include <notez.h>

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

    status = sqlite3_exec(ndb->db, NOTEZ_DB_LIST_QUERY,
                          notez_list_callback, NULL, &errMsg);
    if (status != SQLITE_OK)
    {
        fprintf(stderr, "SQL Error: %s\n", errMsg);
        sqlite3_free(errMsg);
    }
}
