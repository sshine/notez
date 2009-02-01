#include <notez.h>

static int callback(void *not_used, int argc, char **argv, char **col_name)
{
    int i;
    for (i = 0; i < argc; i++)
    {
        printf("%s = %s\n", col_name[i], argv[i] ? argv[i] : "NULL");
    }
    return 0;
}

int main(int argc, char **argv)
{
    NotezDB *ndb;
    char *errMsg;
    int exec_status;
    
    ndb = notez_init("notez.db");
    errMsg = NULL;
    exec_status = sqlite3_exec(ndb->db, "CREATE TABLE IF NOT EXISTS notez (id integer primary key, title text, note text, changed datetime)", callback, NULL, &errMsg);
    if (exec_status != SQLITE_OK)
    {
        fprintf(stderr, "SQL Error: %s\n", errMsg);
        sqlite3_free(errMsg);
    }

    return 0;
}
