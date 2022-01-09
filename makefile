CC=gcc
NAME=bv
FLAGS= -ansi

main: main.o byteReader.o
	$(CC) -o $(NAME) main.o byteReader.o
	rm *.o

main.o:
	$(CC) $(FLAGS) -c main.c

byteReader.o:
	$(CC) $(FLAGS) -c byteReader.c

test1:
	valgrind ./$(NAME) test1.test

test2:
	valgrind ./$(NAME) test2.test

test3:
	valgrind ./$(NAME) test3.test

install:
	sudo cp $(NAME) /usr/bin/