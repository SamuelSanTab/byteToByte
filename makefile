CC=gcc
NAME=main

main: main.o
	$(CC) -o $(NAME) main.o
	rm *.o

main.o:
	$(CC) -c main.c

clean:
	rm *.o $(NAME)

test:
	valgrind ./$(NAME) pruebas.png
