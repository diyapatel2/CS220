CFLAGS:=-g -Wall -std=c99

all: poker

poker: poker.c
	gcc poker.c -o poker
	$(CC) $(CFLAGS) -o poker poker.c

.PHONY: clean
clean:
	rm -fv poker Output.txt
	rm -fv *~ \#*\# *.swp
