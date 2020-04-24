CC = gcc

CFLAGS = -ggdb -O0 -Wall -I include -I Resources/C/Unity/

all: build/hashmap.o bin/hashmap_app test/hashmap_test prova/prova


clean:
	$(RM) -r bin/
	$(RM) -r build/

build/hashmap.o: src/hashmap.c include/hashmap.h
	mkdir -p build
	$(CC) $(CFLAGS) -c src/hashmap.c -o build/hashmap.o

bin/hashmap_app: app/hashmap_app.c include/hashmap.h build/hashmap.o
	$(CC) $(CFLAGS) app/hashmap_app.c build/hashmap.o -o bin/app

test/hashmap_test: test/hashmap_test.c include/hashmap.h build/hashmap.o
	mkdir -p bin
	$(CC) $(CFLAGS) test/hashmap_test.c build/hashmap.o Resources/C/Unity/unity.c -o bin/test

prova/prova: prova/prova.c include/hashmap.h build/hashmap.o
	$(CC) $(CFLAGS) prova/prova.c build/hashmap.o -o prova/prova

test: all
	./bin/test

run: all
	./bin/app hashes.csv

prova: all
	./prova/prova