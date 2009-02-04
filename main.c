#include <notez.h>

int main(int argc, char **argv)
{
    NotezDB *ndb;
    
    ndb = notez_init("notez.db");

    // list
    if (argc == 1) {
        // notez_shorthelp();
        notez_list(ndb);
        exit(EXIT_SUCCESS);
    }

    // list
    if (argc == 2) {
        if (!strcasecmp(argv[1], "help")) {
            notez_longhelp();
            exit(EXIT_SUCCESS);
        }
        if (!strcasecmp(argv[1], "list")) {
            notez_list(ndb);
            exit(EXIT_SUCCESS);
        }
        printf("Unknown command: %s.\n", argv[1]);
        notez_shorthelp();
        exit(EXIT_FAILURE);
    }

    // add
    if (!strcasecmp(argv[1], "add")) {
        printf("Not implemented adding yet.\n");
        exit(EXIT_SUCCESS);
    }

    // del
    if (!strcasecmp(argv[1], "del")) {
        printf("Not implemented deleting yet.\n");
        exit(EXIT_SUCCESS);
    }

    // search
    if (!strcasecmp(argv[1], "search")) {
        printf("Not implemented searching yet.\n");
        exit(EXIT_SUCCESS);
    }

    if (!strcasecmp(argv[1], "help")) {
        notez_longhelp();
        exit(EXIT_SUCCESS);
    }
    printf("Unknown command: %s.\n", argv[1]);
    notez_shorthelp();
    exit(EXIT_FAILURE);
}
