cc=gcc

main:main.o add.o sub.o
	$(cc) -o main main.o add.o sub.o 

main.o:main.c
	$(cc) -c -o main.o main.c
add.o:add.c
	$(cc) -c -o add.o add.c

sub.o:sub.c
	$(cc) -c -o sub.o sub.c

clean:
	rm -f *.o main