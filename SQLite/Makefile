default:
	make build

build:
	gcc main.c -l sqlite3 -o main

run:
	make build
	./main

clean:
	rm -rf ./main *.db *.log