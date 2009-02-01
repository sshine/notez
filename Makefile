default:
	gcc -o notez db_callbacks.c db.c main.c -lsqlite3 -I. -I/usr/include
