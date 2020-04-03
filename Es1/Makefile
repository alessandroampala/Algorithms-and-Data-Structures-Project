CC = gcc

CFLAGS = -Wall -I include

all: build/array.o build/sorting.o bin/sorting_app


clean:
	$(RM) -rf bin/*
	$(RM) -rf build/*


build/array.o: src/array.c include/array.h
	mkdir -p build #mkdir if it doesn't exist
	$(CC) $(CFLAGS) -c src/array.c -o build/array.o

build/sorting.o: src/sorting.c include/sorting.h
	$(CC) $(CFLAGS) -c src/sorting.c -o build/sorting.o

bin/sorting_app: app/sorting_app.c build/array.o build/sorting.o
	mkdir -p build
	$(CC) $(CFLAGS) app/sorting_app.c  build/array.o build/sorting.o -o bin/sorting_app
