CC = gcc

CFLAGS = -Wall -I include

all: build/array.o build/sorting.o


clean:
	$(RM) -rf bin/*
	$(RM) -rf build/*


build/array.o: src/array.c include/array.h
	mkdir -p build #mkdir if it doesn't exist
	$(CC) $(CFLAGS) -c src/array.c -o build/array.o

build/sorting.o: src/sorting.c include/sorting.h
	$(CC) $(CFLAGS) -c src/sorting.c -o build/sorting.o

