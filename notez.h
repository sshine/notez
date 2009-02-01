#include <stdio.h>
#include <stdlib.h>
#include <sqlite3.h>

typedef struct t_notez_db {
    sqlite3 *db;
} NotezDB;

NotezDB *notez_init(char *);
