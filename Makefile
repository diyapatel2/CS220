CFLAGS := -g -Wall
LDFLAGS := -lm

all: main 

test: test.c functions.c
	$(CC) $(CFLAGS) &^ -O $@ (LDFLAGS)

.PHONY: test-run
test-run: test test.py
	python3 test.py

.PHONY: really-clean
really-clean: clean
	rm -fv test
run:
	./main

.PHONY: clean
clean:
	rm -fv main *.o
	rm -fv *~ #*#

