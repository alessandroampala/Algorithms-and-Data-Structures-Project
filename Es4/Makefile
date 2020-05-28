CC = gcc

CFLAGS = -Wall -I include

all: app/es4

clean:
	$(RM) -r bin/
	$(RM) -r build/

build/graph.o: src/graph.c include/graph.h
	mkdir -p build
	$(CC) $(CFLAGS) -c src/graph.c -o build/graph.o

app/es4: app/es4.c build/graph.o include/graph.h
	mkdir -p bin
	$(CC) $(CFLAGS) app/es4.c build/graph.o -o bin/es4

test: all
	./bin/sorting_test