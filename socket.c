#include <fcntl.h>
#include <netinet/in.h>
#include <string.h>
#include <sys/sendfile.h>
#include <sys/socket.h>
#include <unistd.h>

void main() {
  int s = socket(AF_INET, SOCK_STREAM, 0);
  struct sockaddr_in addr = {
      AF_INET,
      0x901f,
      0,
  };

  bind(s, &addr, sizeof(addr));
  listen(s, 10);
  int client_fd = accept(s, 0, 0);

  char buffer[256] = {0};
  recv(client_fd, buffer, 256, 0);
  char *f = buffer + 5;
  *strchr(f, ' ') = 0;
  int opend_fd = open(f, O_RDONLY);
  sendfile(client_fd, opend_fd, 0, 256);
  close(opend_fd);
  close(client_fd);
  close(s);
}
