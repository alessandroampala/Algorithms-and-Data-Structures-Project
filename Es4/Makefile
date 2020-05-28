CC = gcc

CFLAGS = -Wall -I include

all: build/stack.o build/graph.o app/es4

clean:
	$(RM) -r bin/
	$(RM) -r build/

build/stack.o: src/stack.c include/stack.h
	mkdir -p build
	$(CC) $(CFLAGS) -c src/stack.c -o build/stack.o

build/graph.o: src/graph.c include/graph.h
	$(CC) $(CFLAGS) -c src/graph.c -o build/graph.o

app/es4: app/es4.c build/graph.o include/graph.h
	mkdir -p bin
	$(CC) $(CFLAGS) app/es4.c build/graph.o build/stack.o -o bin/es4