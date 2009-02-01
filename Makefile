default:
	gcc -o notez db.c main.c -lsqlite3 -I. -I/usr/include
