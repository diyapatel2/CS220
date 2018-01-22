all: thread mutex multithread

thread: thread.c 
	gcc thread.c -pthread -o thread

mutex: mutex.c
	gcc mutex.c -pthread -o mutex

multithread: multithread.c
	gcc multithread.c -pthread -o multi

clean:
	rm -fv thread 
	rm -fv mutex
	rm -fv multi
	rm -fv *.o *~ \#*\# *.swp
