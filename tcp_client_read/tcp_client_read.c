#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/types.h>
#include <sys/socket.h>

void error_exit(char *message);

int main(int argc, char *argv[])
{
	int fd, ret;
	char message[50];
	int str_len;
	struct sockaddr_in server_addr;

	if (argc != 3) {
		printf("Usage : %s <IP> <port>\n", argv[0]);
	}

	fd = socket(AF_INET, SOCK_STREAM, 0);
	if (fd == -1) {
		error_exit("socket() error");
	}

	memset(&server_addr, 0, sizeof(server_addr));
	server_addr.sin_family = AF_INET;
	server_addr.sin_addr.s_addr = inet_addr(argv[1]);
	server_addr.sin_port = htons(atoi(argv[2]));

	ret = connect(fd, (struct sockaddr*) &server_addr, sizeof(server_addr));
	if (ret == -1) {
		error_exit("connect() error");
	}

	str_len = read(fd, message, sizeof(message)-1);
	if (str_len == -1) {
		error_exit("read() error");
	}
	message[str_len] = 0;

	printf("Message from server : %s \n", message);

	close(fd);

	return 0;
}

void error_exit(char *message) {
	fputs(message, stderr);
	fputc('\n', stderr);
	exit(1);
}
