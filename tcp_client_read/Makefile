CC = gcc
CFLAGS = -W -Wall -O2
LDFLAGS = -lm

all : tcp_client_read

tcp_client_read : tcp_client_read.c
	$(CC) $(CFLAGS) -o $@ $^ $(LDFLAGS)

clean :
	rm -rf *.o
