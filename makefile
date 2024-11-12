CC = gcc
CFLAGS = -Wall -Wextra -std=c11
OBJ = main.o repl.o btree.o

all: db

db: $(OBJ)
	$(CC) $(CFLAGS) -o db $(OBJ)

main.o: main.c btree.h repl.h
	$(CC) $(CFLAGS) -c main.c

repl.o: repl.c repl.h btree.h
	$(CC) $(CFLAGS) -c repl.c

btree.o: btree.c btree.h
	$(CC) $(CFLAGS) -c btree.c

clean:
	rm -f $(OBJ) db
