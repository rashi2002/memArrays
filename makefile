CC = clang
CFLAGS = -Wall -std=c99 -pedantic

array.o: array.h memsys.o memsys.h
	$(CC) $(CFLAGS) -c array.c

memsys.o: memsys.h
	$(CC) $(CFLAGS) -c memsys.c


clean:  
	rm *.o 
