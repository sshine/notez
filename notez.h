#include <stdio.h>
#include <stdlib.h>
#include <sqlite3.h>

typedef struct t_notez_db {
    sqlite3 *db;
} NotezDB;

#define NOTEZ_DB_INIT "CREATE TABLE IF NOT EXISTS notez (id integer primary key, title text, note text, changed datetime)"

NotezDB *notez_init(char *);

/* callbacks */
extern int notez_default_callback(void *, int, char **, char **);
extern int notez_list_callback(void *, int, char **, char **);
