CC=gcc -g

all: server client

server: server.o networking.o print_ascii.o
	$(CC) server.o networking.o print_ascii.o -o server

client: client.o networking.o print_ascii.o
	$(CC) client.o networking.o print_ascii.o -o client

server.o: server.c networking.h
	$(CC) -c server.c

client.o: client.c networking.h
	$(CC) -c client.c

networking.o: networking.c networking.h
	$(CC) -c networking.c

print_ascii.o: print_ascii.c print_ascii.h
	$(CC) -c print_ascii.c

clean: 
	rm *.o *~


