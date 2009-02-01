#include <notez.h>

int main(int argc, char **argv)
{
    NotezDB *ndb;
    
    ndb = notez_init("notez.db");
    notez_list(ndb);

    return 0;
}
