#include <stdio.h>
#include <stdlib.h>
#include <sqlite3.h>
#include <string.h>
#include <time.h>

typedef struct t_notez_db {
    sqlite3 *db;
} NotezDB;

#define NOTEZ_DB_INIT "CREATE TABLE IF NOT EXISTS notez (id integer primary key, title text, note text, changed datetime)"
#define NOTEZ_DB_LIST_QUERY "SELECT id, strftime(\"%s\", changed) AS changed, title FROM notez ORDER BY id DESC"

NotezDB *notez_init(char *);
void notez_list(NotezDB *);

char *duration(char *);

void notez_shorthelp(void);
void notez_longhelp(void);

/* callbacks */
extern int notez_default_callback(void *, int, char **, char **);
extern int notez_list_callback(void *, int, char **, char **);
