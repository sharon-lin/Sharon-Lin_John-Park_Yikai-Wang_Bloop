all: server client

server: server.o networking.o print_ascii.o
	gcc -o server server.o networking.o print_ascii.o

client: client.o networking.o print_ascii.o
	gcc -o client client.o networking.o print_ascii.o

server.o: server.c networking.h
	gcc -c server.c

client.o: client.c networking.h
	gcc -c client.c

networking.o: networking.c networking.h
	gcc -c networking.c

print_ascii.o: print_ascii.c print_ascii.h
	gcc -c print_ascii.c

clean:
	rm -f *.o
	rm -f *~
	rm server
	rm client
