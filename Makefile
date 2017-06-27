
client: client.o
	gcc -Wall client.o -o client

client.o: client.c
	gcc -Wall -c client.c

server: server.o
	gcc -Wall server.o -o server

server.o: server.c
	gcc -Wall -c server.c

clear:
	rm -f client server client.o server.o
