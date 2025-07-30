
server: main.c
	$(CC) -o server main.c $(shell pkg-config --cflags --libs jansson)

run: server
	./server

clean:
	- rm -rf server