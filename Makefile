process:
	gcc process.c -o process.out && ./process.out

thread:
	gcc -pthread thread.c -o thread.out && ./thread.out
clean:
	rm -f *.o