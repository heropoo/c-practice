build: preprocess compile assemble link 
	echo "done"

run: build
	./hello

preprocess: hello.c
	gcc -E hello.c -o hello.i

compile: hello.i
	gcc -S hello.i -o hello.s

assemble: hello.s
	gcc -c hello.s -o hello.o

link: hello.o
	gcc hello.o -o hello
