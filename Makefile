CC = gcc
CFLAGS = -Wall -O2
INCLUDES = -I. -I/usr/include
LIBS = -lsqlite3
BIN = notez

CFILES = help.c duration.c db_callbacks.c db.c main.c
OBJS = ${CFILES:.c=.o}

all: ${CFILES} ${BIN}

${BIN}: ${OBJS}
	${CC} ${CFLAGS} ${LIBS} ${OBJS} -o $@

.c.o:
	${CC} ${CFLAGS} ${INCLUDES} -c $< -o $@

clean:
	rm -f ${OBJS} ${BIN}
