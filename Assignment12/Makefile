all: loader hellosh

loader: loader.c
	gcc loader.c -m32 -std=c89 -g -Wl,-z,execstack -o loader
hellosh: hellosh
	gcc -std=c89 hellosh.c -o hellosh

.PHONY: clean
clean:
	rm -f loader hellosh
	rm -f *.o
	rm -f *~ \#*\# *.swp
