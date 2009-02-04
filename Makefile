CFLAGS = -Wall -O2
INCLUDES = -I. -I/usr/include
LIBS = -lsqlite3

default:
	gcc -o notez duration.c db_callbacks.c db.c main.c \
		$(CFLAGS) $(LIBS) $(INCLUDES)
