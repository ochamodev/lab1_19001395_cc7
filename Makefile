process:
	gcc -lpthread process.c -o process.o

thread:
	gcc -pthread thread.c -o thread.o
	./thread.o
clean:
	rm -f *.o