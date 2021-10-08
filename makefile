CC = clang
CFLAGS = -Wall -std=c99 -pedantic

test7: array.o memsys.o test7.o
	$(CC) $(CFLAGS) array.o memsys.o test7.o -o test7
	
test7.o: array.o array.h memsys.o memsys.h
	$(CC) $(CFLAGS) -c test7.c

array.o: array.h memsys.o memsys.h
	$(CC) $(CFLAGS) -c array.c

memsys.o: memsys.h
	$(CC) $(CFLAGS) -c memsys.c


clean:  
	rm *.o test7
