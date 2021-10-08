CC = clang
CFLAGS = -Wall -std=c99 -pedantic

test6: array.o memsys.o test6.o
	$(CC) $(CFLAGS) array.o memsys.o test6.o -o test6
test6.o: array.o array.h memsys.o memsys.h
	$(CC) $(CFLAGS) -c test6.c

array.o: array.h memsys.o memsys.h
	$(CC) $(CFLAGS) -c array.c

memsys.o: memsys.h
	$(CC) $(CFLAGS) -c memsys.c


clean:  
	rm *.o test6
