all: stat.o
	gcc stat.o
run: a.out
	./a.out
stat.o: stat.c
	gcc -c stat.c
again: stat.c
	emacs stat.c
clean: stat.o
	rm stat.o
