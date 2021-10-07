CC = clang
CFLAGS = -Wall -std=c99 -pedantic

test1: array.o memsys.o test1.o
	$(CC) $(CFLAGS) array.o memsys.o test1.o -o test1
test1.o: array.o array.h memsys.o memsys.h
	$(CC) $(CFLAGS) -c test1.c

array.o: array.h memsys.o memsys.h
	$(CC) $(CFLAGS) -c array.c

memsys.o: memsys.h
	$(CC) $(CFLAGS) -c memsys.c


clean:  
	rm *.o test1
