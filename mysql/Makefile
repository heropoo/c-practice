default:
	make build

build: main.c
	gcc main.c -I /usr/include/mysql/ -L /lib/ -l mysqlclient -o main

run:
	make build
	./main

clean:
	rm -rf main
