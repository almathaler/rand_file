ifeq ($(DEBUG), true)
CC = gcc -g
else
CC = gcc
endif

all: rand_file.o
	$(CC) -o program rand_file.o
rand_file.o:
	$(CC) -c rand_file.c
run:
	./program
clean:
	rm *.o
	rm program 
