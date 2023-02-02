all: process thread

process:
	gcc process.c -o process.out

thread:
	gcc -pthread thread.c -o thread.out
clean:
	rm -f *.o