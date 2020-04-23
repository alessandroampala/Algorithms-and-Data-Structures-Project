CC = gcc

CFLAGS = -ggdb -O0 -Wall -I include -I Resources/C/Unity/

all: build/sorting.o bin/sorting_app test/sorting_test


clean:
	$(RM) -r bin/
	$(RM) -r build/

build/sorting.o: src/sorting.c include/sorting.h
	mkdir -p build
	$(CC) $(CFLAGS) -c src/sorting.c -o build/sorting.o

bin/sorting_app: app/sorting_app.c include/sorting.h build/sorting.o
	mkdir -p bin
	$(CC) $(CFLAGS) app/sorting_app.c build/sorting.o -o bin/sorting_app

test/sorting_test: test/sorting_test.c include/sorting.h build/sorting.o
	$(CC) $(CFLAGS) test/sorting_test.c build/sorting.o Resources/C/Unity/unity.c -o bin/sorting_test

test: all
	./bin/sorting_test