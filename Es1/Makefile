CC = gcc

CFLAGS = -Wall -I include -I Resources/C/Unity/

all: build/array.o build/sorting.o bin/sorting_app unit_test/sorting_test


clean:
	$(RM) -r bin/
	$(RM) -r build/


build/array.o: src/array.c include/array.h
	mkdir -p build #mkdir if it doesn't exist
	$(CC) $(CFLAGS) -c src/array.c -o build/array.o

build/sorting.o: src/sorting.c include/sorting.h include/array.h
	$(CC) $(CFLAGS) -c src/sorting.c -o build/sorting.o

bin/sorting_app: app/sorting_app.c include/array.h build/array.o include/sorting.h build/sorting.o
	mkdir -p bin
	$(CC) $(CFLAGS) app/sorting_app.c  build/array.o build/sorting.o -o bin/sorting_app

unit_test/sorting_test: unit_test/sorting_test.c build/array.o include/array.h build/sorting.o include/sorting.h
	$(CC) $(CFLAGS) unit_test/sorting_test.c build/array.o build/sorting.o Resources/C/Unity/unity.c -o bin/sorting_test

test: all
	./bin/sorting_test