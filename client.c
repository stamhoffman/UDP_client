#include <sys/socket.h>
#include <sys/types.h>
#include <string.h>
#include <stdio.h>
#include <errno.h>
#include <arpa/inet.h>
#include <unistd.h>


#define point_addr_serv struct sockaddr
#define MAXLINE

int main(int argc, char const *argv[]) {

  int sock_descriptor;
  struct sockaddr_in serv_addr;

  serv_addr.sin_family = AF_INET;
  serv_addr.sin_port = htons(13);

  if(inet_pton(AF_INET, argv[1], &serv_addr.sin_addr) == -1)
    {
      printf("Error inet_pton :%s\n",strerror(errno));
    }
      else printf("inet_pton OK\n");

    if((sock_descriptor = socket(AF_INET, SOCK_DGRAM,0)) == -1)
      {
        printf("Error socket: %s\n", strerror(errno));
      }
        else printf("socket_OK \n");

  int kodogramma[4] = {1,11,111,11111};

  printf("kodogramma_1: %d\n", kodogramma[0]);
  printf("kodogramma_2: %d\n", kodogramma[1]);
  printf("kodogramma_3: %d\n", kodogramma[2]);
  printf("kodogramma_4: %d\n", kodogramma[3]);

  sendto(sock_descriptor, kodogramma, sizeof(kodogramma), 0,
        (point_addr_serv*)&serv_addr,sizeof(serv_addr));

  int recv_buffer[4];

  if(recvfrom(sock_descriptor, recv_buffer, sizeof(recv_buffer), 0, (point_addr_serv *) &serv_addr,sizeof(serv_addr)) == -1)
  {
    printf("Error recvfrom(): %s\n", strerror(errno));
  }
  printf("World_1: %d\n",recv_buffer[0]);
  printf("World_2: %d\n",recv_buffer[1]);
  printf("World_3: %d\n",recv_buffer[2]);
  printf("World_4: %d\n",recv_buffer[3]);


  return 0;
}
