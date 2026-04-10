#include <errno.h>
#include <string.h>
#include <unistd.h>
#include <netdb.h>
#include <sys/socket.h>
#include <sys/select.h>
#include <netinet/in.h>
#include <stdlib.h>
#include <stdio.h>

void fatal_error() {
  write(2, "Fatal error\n", 12);
  exit(1);
}

// Given
int extract_message(char **buf, char **msg)
{
	char	*newbuf;
	int	i;

	*msg = 0;
	if (*buf == 0)
		return (0);
	i = 0;
	while ((*buf)[i])
	{
		if ((*buf)[i] == '\n')
		{
			newbuf = calloc(1, sizeof(*newbuf) * (strlen(*buf + i + 1) + 1));
			if (newbuf == 0)
				return (-1);
			strcpy(newbuf, *buf + i + 1);
			*msg = *buf;
			(*msg)[i + 1] = 0;
			*buf = newbuf;
			return (1);
		}
		i++;
	}
	return (0);
}

// Given
char *str_join(char *buf, char *add)
{
	char	*newbuf;
	int		len;

	if (buf == 0)
		len = 0;
	else
		len = strlen(buf);
	newbuf = malloc(sizeof(*newbuf) * (len + strlen(add) + 1));
	if (newbuf == 0)
		return (0);
	newbuf[0] = 0;
	if (buf != 0)
		strcat(newbuf, buf);
	free(buf);
	strcat(newbuf, add);
	return (newbuf);
}

int main(int argc, char **argv) {
	int sockfd, connfd, len;
	struct sockaddr_in servaddr, cli;

	if (argc != 2) {
		write(2, "Wrong number of arguments\n", 26);
		return 1;
	}
	// socket create and verification 
	sockfd = socket(AF_INET, SOCK_STREAM, 0);
	if (sockfd < 0)
		return fatal_error();
	bzero(&servaddr, sizeof(servaddr));

	// assign IP, PORT 
	servaddr.sin_family = AF_INET;
	servaddr.sin_addr.s_addr = htonl(2130706433); //127.0.0.1
	servaddr.sin_port = htons(atoi(argv[1]));

	// Binding newly created socket to given IP and verification 
	if (bind(sockfd, (const struct sockaddr *)&servaddr, sizeof(servaddr)) < 0)
		return fatal_error();
	if (listen(sockfd, 10) < 0)
		return fatal_error();

	// NEW
	fd_set all_fds, read_fds;
	FD_ZERO(&all_fds); //clears the fd set
	FD_SET(sockfd, &all_fds); // adds sockfd to the fd set
	int maxfd = sockfd; // maxfd is the highest fd number. Right now, it's sockfd (the only one)
	int ids[FD_SETSIZE];
	char *bufs[FD_SETSIZE];

	for (int i = 0; i < FD_SETSIZE; i++) {
		ids[i] = -1;
		bufs[i] = NULL;
	}

	int next_id = 0;
	char buffer[1024];

	while (1) {
		read_fds = all_fds; // copy it
		if (select(maxfd + 1, &read_fds, NULL, NULL, NULL) < 0)
			fatal_error();
		for (int fd = 0; fd <= maxfd; fd++) {
			if (!FD_ISSET(fd, &read_fds))
				// ************* Unused FD ************* //
				continue;
			if (fd == sockfd) {
				// ********** New connection *********** //
				struct sockaddr_in	cli;
				char welcome_msg[64];
				socklen_t			len = sizeof(cli);

				connfd = accept(fd, (struct sockaddr *)&cli, &len);
				if (connfd < 0)
					fatal_error();
				FD_SET(connfd, &all_fds); // 
				if (connfd > maxfd) // Check and set if it is the new maxfd
					maxfd = connfd;
				ids[connfd] = next_id++; // Asign incremental ID
				bufs[connfd] = NULL;
				sprintf(welcome_msg, "server: client %d just arrived\n", ids[connfd]);
				for (int other_fd = 0; other_fd <= maxfd; other_fd++)
					// Send new client connected msg to every client except the new one
					if (other_fd != fd && other_fd != connfd && FD_ISSET(other_fd, &all_fds)
						&& send(other_fd, welcome_msg, strlen(welcome_msg), 0) < 0)
							fatal_error();
			} else 
			{ // data sent by client or connection closed
				int read_bytes = recv(fd, buffer, sizeof(buffer) - 1, 0);
				if (read_bytes > 0)
				{
					buffer[read_bytes] = '\0';
					bufs[fd] = str_join(bufs[fd], buffer);
					if (bufs[fd])
						fatal_error();

					char *line = NULL;
					int msg_extracted;
					while ((msg_extracted = extract_message(&bufs[fd], &line)) > 0)
					{
						char prefix[64];
						sprintf(prefix, "client %d: ", ids[fd]);
						// broadcast message
						for (int other_fd = 0; other_fd <= maxfd; other_fd++)
						{
							if (other_fd != sockfd && other_fd != fd && FD_ISSET(other_fd, &all_fds)
								&& send(other_fd, prefix, strlen(prefix), 0) < 0
								&& send(other_fd, line, strlen(line), 0) < 0)
									fatal_error();
						}
						free(line);
						line = NULL;
					}
					if (msg_extracted < 0)
						fatal_error();
				}
				else
				{
					char goodbye_msg[64];
					int other_fd;

					sprintf(goodbye_msg, "server: client %d just left\n", ids[fd]);
					for (other_fd = 0; other_fd <= maxfd; other_fd++)
						// Send client disconnected msg to every client except the new one
						if (other_fd != sockfd && other_fd != fd && FD_ISSET(other_fd, all_fds)
							&& send(other_fd, goodbye_msg, strlen(goodbye_msg), 0) < 0)
								fatal_error();
					// clean up fds and buffers
					FD_CLR(fd, &all_fds);
					close(fd);
					if (bufs[fd] != NULL)
						free(bufs[fd]);
					bufs[fd] = NULL;
					ids[fd] = -1;
				}
			}
		}
	}
}